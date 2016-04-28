#include "LPC17xx.h"
#include "G4intl.h"
#include "FreeRTOS.h"
#include "task.h"
//#include "uip.h"

/* Necesarias para la funcion Fijar_GET_en_Matriz */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**************************************************/

char* accionGET;
char* inputGET;


/****************************************************************************
  			FUNCIONES
 ***************************************************************************/

void
pointer2string(char *pointer, char string[])   //Copia un puntero a una cadena estandar
    {
	int i;
	for(i=0;i<=strlen(pointer);i++) string[i]=*(pointer+i);
    return;
    }

char*
substring(const char string[],int inicio,int longitud)  //Extrae una sub-cadena, DESTRUYENDO EN EL PROCESO a la cadena original!
    /* Devuelve una subcadena a partir de la cadena pasada
        El primer caracter se toma como 1, no cero.
        Si la longitud es "cero" => se copia 'todo' a partir del caracter inicio
    */

    {
    strcpy(stemp,string);
    if ((inicio < 1)||((inicio-1+longitud) > strlen(stemp))) return NULL;
    char *aux;
    aux=stemp+(inicio-1)*sizeof(char);
    if (longitud!=0) *(aux+longitud)='\0';
    return aux;
    }

int
stringcompare(const char s1[], const char s2[])   //Compara 2 cadenas y devuelve 1 si son iguales, 0 si son distintas
    {
    int i;
    if (strlen(s1)!=strlen(s2)) return 0;
    for (i=0;i<strlen(s1);i++) if (s1[i]!=s2[i]) return 0;
    return 1;
    }



void
extraer_variables_GET(char* p) {

    /*Variables a usar*/
    char *q, *aux1, s_completa[100], s_parcial[100];
    char GETvar_name[6], GETvar_valu[16];
    int i;

    //Capturar en el nuevo puntero "q" todo lo que hay detras del "?"
    q =strchr(p,'?')+1;

    //Copiar el puntero q en una cadena s_completa
    pointer2string(q,s_completa);

    // #1 - si no existe ningun GET, o es uno trucho me voy; esta condicion funcionalmente no es necesaria pero se deja como acelerador de programa
    if(strlen(s_completa)==1) {
    	//printf("aborto funcion porque no hay GET presente\n");
    	return;
    	}

    // el siguiente FOR va trozando la cadena en sus componentes separados por &
    i=0;
    for(aux1=strtok(s_completa,"&"); i<2; i++) {     //la 1er invocación de strtok toma el 1er pedazo

        //Tomar el "componente actual" y meterlo en la cadena s_parcial (string parcial)
        pointer2string(aux1,s_parcial);    //nom[i]

        /*
         *  Ahora en s_parcial tengo UNA SOLA variable con SU valor.
         *  El desafío es poder encontrar en QUÉ variable asignar el valor.
         *  Para ello asumiré que "la variable" tendrá longitud fija de 6 caracteres, siendo
         *  los 5 primeros para la variable y la 6ta para el # de puerto.
         *  A partir de la presunción anterior, busco obtener la variable (sin puerto) para luego
         *  obtener su valor
         */

        //Extraer SOLO la variable en cuestión
        pointer2string(substring(s_parcial,1,6),GETvar_name);  	//corto todo lo que sigue al 6to caracter

        /* Ahora en GETvar_name tengo el nombre de la variable */

        //Obtener el valor asignado al combo variable/puerto obtenidos antes
        pointer2string(substring(s_parcial,6+2,0),GETvar_valu); //salteo el igual(+1) y empiezo desde "+2"

        /* Ahora en GETvar_valu tengo el valor para el puerto en cuestion */
		taskENTER_CRITICAL();
        if (i==0) strcpy(inputx,GETvar_valu);
		if (i==1) strcpy(accion,GETvar_valu);
		taskEXIT_CRITICAL();

    aux1=strtok(NULL, "&"); //TOMAR EL SIGUIENTE TROZO VARIABLE=VALOR
    }

    return;
    }

