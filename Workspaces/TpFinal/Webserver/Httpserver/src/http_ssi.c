/*
 * http_ssi.c
 *
 *  Created on: 20 de may. de 2016
 *      Author: pato
 */


#include "http_ssi.h"
#include "httpd.h"
#include "lpc_types.h"
#include "string.h"

uint16_t SSIHandler( int iIndex, char *pcBuffer, int iBufferLength )
{

	/* Unused parameter. */
	( void ) iBufferLength;

	/* The SSI handler function that generates text depending on the index of
	the SSI tag encountered. */

	switch( iIndex )
	{
		default:
			//TaskENTER_CRITICAL();
			strcat( pcBuffer, "Hola" );
			//TaskEXIT_CRITICAL();
			//vTaskG4RX( ( int8_t * ) pcBuffer );
			break;
	}

	/* Include a count of the number of times an SSI function has been executed
	in the returned string. */
//	uiUpdateCount++;
//	sprintf( cUpdateString, "\r\n\r\nRefresh count %u", uiUpdateCount );
//	strcat( pcBuffer, cUpdateString );
	return strlen( pcBuffer );
}
