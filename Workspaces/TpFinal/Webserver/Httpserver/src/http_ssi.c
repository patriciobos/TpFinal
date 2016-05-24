/*
 * http_ssi.c
 *
 *  Created on: 20 de may. de 2016
 *      Author: pato
 */


#include "http_ssi.h"
#include "httpd.h"
//#include "actuators.h"

#include "lpc_types.h"
#include "string.h"


uint16_t SSIHandler( int iIndex, char *pcBuffer, int iBufferLength )
{

	/* Unused parameter. */
	( void ) iBufferLength;

	/* The SSI handler function that generates text depending on the index of
	the SSI tag encountered. */

	char *ptrState;

	switch( iIndex )
	{

	case ssiACT1_INDEX:
		ptrState = getActuatorState(portNum_1);
		strcpy( pcBuffer, ptrState );
		break;

	case ssiACT2_INDEX:
		ptrState = getActuatorState(portNum_2);
		strcpy( pcBuffer, ptrState );
		break;

	case ssiACT3_INDEX:
		ptrState = getActuatorState(portNum_3);
		strcpy( pcBuffer, ptrState );
		break;

	case ssiACT4_INDEX:
		ptrState = getActuatorState(portNum_4);
		strcpy( pcBuffer, ptrState );
		break;

	case ssiSENSOR1_INDEX:
		strcpy( pcBuffer, "value1" );
		break;

	case ssiSENSOR2_INDEX:
		strcpy( pcBuffer, "value2" );
		break;

	case ssiSENSOR3_INDEX:
		strcpy( pcBuffer, "value3" );
		break;

	case ssiALARMA1_INDEX:
		strcpy( pcBuffer, "Normal" );
		break;

	case ssiALARMA2_INDEX:
		strcpy( pcBuffer, "Normal" );
		break;

	case ssiALARMA3_INDEX:
		strcpy( pcBuffer, "Normal" );
		break;

	default:
		strcpy( pcBuffer, "Hola" );
		break;
	}

	return strlen( pcBuffer );
}
