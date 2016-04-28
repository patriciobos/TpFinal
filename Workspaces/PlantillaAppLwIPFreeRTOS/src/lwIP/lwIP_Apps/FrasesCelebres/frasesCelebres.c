/*
 * bridgeTCP_UART.c
 *
 *  Created on: 22/11/2013
 *      Author: Alejandro
 */

#include "string.h"
#include "lwip/udp.h"
#include "UART.h"
extern UART Consola;

#define PUERTO_UDP_FRASES_CELEBRES 33333
err_t socket_recv ( void *arg, struct udp_pcb *tpcb, struct pbuf *p, struct ip_addr *addr, u16_t port );

const char * frases[] = {
	"Hay dos cosas infinitas: el Universo y la estupidez humana. Y del Universo no estoy seguro. (Albert Einstein)",
	"Idealismo es la capacidad de ver a las personas como podrian ser si no fueran como son. (Kurt Goetz)",
	"El objetivo de la guerra no es morir por tu pais. Sino asegurarse de que el otro bastardo muera por el suyo. (General S Patton)",
	"No hay nada como el amor de una mujer casada. Es una cosa de la que ningun marido tiene la menor idea. (Oscar Wilde)"
};

void InitServidorFrasesCelebres ( void )
{
	struct udp_pcb * pcb;
	err_t err;

	if((pcb = udp_new()) == NULL);		//Intento alocar un process control block para la conexion TCP
		return; // No pude alocar mi socket udp!

	//La pongo a escuchar en la direccion y puerto indicados
	if((err = udp_bind(pcb, IP_ADDR_ANY, PUERTO_UDP_FRASES_CELEBRES)) != ERR_OK) //(IP_ADDR_ANY significa "la que me hayan asignado", por DHCP o estaticamente)
		return;

	//Los callbacks UDP pueden recibir un argumento extra
	udp_recv(pcb, (udp_recv_fn) socket_recv, NULL);		// Datos recibidos
	//Ojo, udp no es orientado a conexion, asi que no tiene mas eventos que "datos recibidos"

	return;
}

err_t socket_recv ( void *arg, struct udp_pcb *tpcb, struct pbuf *p, struct ip_addr *addr, u16_t port )
{
	struct pbuf * q = NULL;
	if (p == NULL) {
		return ERR_OK;
	}

//Cuento la cantidad de bytes y los mando a la Consola
	char * pp 	= (char *) p->payload;	//p->payload: puntero a los datos que trae el pbuf
	int indice;

	switch(pp[0])	//Segun la primera letra mando un mensaje de vuelta a la conexion
	{
		case 'a':
			indice = 0;
			break;

		case 'g':
			indice = 1;
			break;

		case 'p':
			indice = 2;
			break;

		case 'w':
			indice = 3;
			break;

		default:
			indice = -1;
			break;
	}

	if(indice != -1)
	{
		int largo = strlen(frases[indice]) + 1; //Strlen no cuenta el \0 al final del string
		q = pbuf_alloc(PBUF_RAM, largo, PBUF_RAW);
		if(q != NULL)
		{
			memcpy(q->payload, frases[indice], largo);
			strcat((char*)q->payload, "\r\n"); q->len +=2; q->tot_len+=2;
			udp_sendto(tpcb, q, addr, port);
			pbuf_free(q);
		}
	}
	pbuf_free(p);
	return ERR_OK;
}
