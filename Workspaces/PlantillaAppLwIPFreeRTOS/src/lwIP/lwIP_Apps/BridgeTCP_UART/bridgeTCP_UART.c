/*
 * bridgeTCP_UART.c
 *
 *  Created on: 22/11/2013
 *      Author: Alejandro
 */

#include "lwip/tcp.h"
#include "UART.h"
extern UART Consola;

#define PUERTO_TCP_BRIDGE 33333
static err_t RegistrarCallbacksSocket 	(void *arg, struct tcp_pcb *pcb, err_t err);
static err_t socket_recv 				(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);

void InitBridgeTCP_UART ( void )
{
	struct tcp_pcb * pcb;
	err_t err;

	if((pcb = tcp_new()) == NULL);		//Intento alocar un process control block para la conexion TCP
		return; // No pude alocar mi socket tcp!

	//La pongo a escuchar en la direccion y puerto indicados
	if((err = tcp_bind(pcb, IP_ADDR_ANY, PUERTO_TCP_BRIDGE)) != ERR_OK) //(IP_ADDR_ANY significa "la que me hayan asignado", por DHCP o estaticamente)
		return;

	//La pongo a escuchar en la direccion y puerto indicados
	err = tcp_bind	( pcb, IP_ADDR_ANY, PUERTO_TCP_BRIDGE ); //(IP_ADDR_ANY significa "la que me hayan asignado", por DHCP o estaticamente)
	pcb = tcp_listen( pcb );	//Pongo la conexion en estado de escucha

	tcp_arg		( pcb, pcb );
	//callback para cuando se acepte una conexion en el puerto
	tcp_accept	( pcb, RegistrarCallbacksSocket );
}

static err_t RegistrarCallbacksSocket (void *arg, struct tcp_pcb *pcb, err_t err)
{
	//TCP trabaja con conexiones, cuando se establece una nueva se le ponen sus callbacks
	//lpcb es

	struct tcp_pcb_listen *lpcb = (struct tcp_pcb_listen*)arg;
	tcp_accepted(lpcb);					//Le aviso al stack que ya acepte la conexion
	tcp_setprio(pcb, TCP_PRIO_NORMAL);	/* Set priority */

	//Seteo los callbacks que se llaman en los determinados eventos:
	tcp_recv(pcb, socket_recv);		// Datos recibidos
//	tcp_err	(pcb, socket_err);		// Error fatal en la conexion
//	tcp_sent(pcb, socket_sent);		// Datos enviados
//	tcp_poll(pcb, socket_poll, 0); 	// Funcion que llama periodicamente el stack TCP sobre esta conexion

	return ERR_OK;
}

static err_t socket_recv (void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
	struct tcp_pcb_listen * lpcb = (struct tcp_pcb_listen*)arg;
	tcp_accepted(lpcb);					/* Decrease the listen backlog counter */

//Me aseguro que no haya habido errores
	if ((err != ERR_OK) || (p == NULL))
	{
		if (p != NULL) {
			tcp_recved(pcb, p->tot_len);
			pbuf_free(p);
		}
		tcp_close(pcb);
		return ERR_OK;
	}

//Cuento la cantidad de bytes y los mando a la Consola
	int nBytes 	= p->len;				//p->len: total de bytes en este pbuf
	char * pc 	= (char *) p->payload;	//p->payload: puntero a los datos que trae el pbuf
	while(nBytes)
	{
		UARTputc(&Consola, *pc++);
		nBytes--;
	}

//Cleanup
	tcp_recved(pcb, p->tot_len);	//Le aviso al stack que ya utilice los bytes recibidos
	if (p != NULL)	pbuf_free(p);	//Libero el pbuf para que el stack recupera la memoria dinamica alocada
	return ERR_OK;
}
