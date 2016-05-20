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
//	case ssiACT1_INDEX:
//		strcpy( pcBuffer, "estado1" );
//		break;
//
//	case ssiACT2_INDEX:
//		strcpy( pcBuffer, "estado2" );
//		break;
//
//	case ssiACT3_INDEX:
//		strcpy( pcBuffer, "estado3" );
//		break;
//
//	case ssiACT4_INDEX:
//		strcpy( pcBuffer, "estado4" );
//		break;

//	case ssiSENSOR1_INDEX:
//		strcpy( pcBuffer, "Hola" );
//		break;
//	case ssiSENSOR2_INDEX:
//		strcpy( pcBuffer, "Hola" );
//		break;
//	case ssiSENSOR3_INDEX:
//		strcpy( pcBuffer, "Hola" );
//		break;
//	case ssiALARMA1_INDEX:
//		strcpy( pcBuffer, "Hola" );
//		break;
//	case ssiALARMA2_INDEX:
//		strcpy( pcBuffer, "Hola" );
//		break;
//	case ssiALARMA3_INDEX:
//		strcpy( pcBuffer, "Hola" );
//		break;

	default:
		strcpy( pcBuffer, "Hola" );
//		//vTaskG4RX( ( int8_t * ) pcBuffer );
		break;
	}

	/* Include a count of the number of times an SSI function has been executed
	in the returned string. */
//	uiUpdateCount++;
//	sprintf( cUpdateString, "\r\n\r\nRefresh count %u", uiUpdateCount );
//	strcat( pcBuffer, cUpdateString );
	return strlen( pcBuffer );
}
