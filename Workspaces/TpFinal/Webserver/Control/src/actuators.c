
/* Definición de variables globales para insertar en el HTML*/

#include "actuators.h"
//#include "board_api.h"



actuatorState_t actuatorState[4] = {ON,OFF,ON,OFF};

const char estadoActuadorApagado[] = "APAGADO";
const char estadoActuadorEncendido[] = "ENCENDIDO";

char* getActuatorState(int portNum){
//
	char *ptrActuatorState;

	if(actuatorState[portNum] == OFF)
		return ptrActuatorState = (char *) estadoActuadorApagado;
	else
		return ptrActuatorState = (char *) estadoActuadorEncendido;
//
//	if (actuatorState(port) == OFF)
//		return ptrActuatorState = estadoActuadorApagado;
//	else
//		return ptrActuatorState = estadoActuadorEncendido;
//
}

const char *actuatorsHandler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]) {

//	if( strcmp(pcParam[0], "state") == 0)
//	{
//		if( strcmp(pcValue[0], "on") == 0)
//			IO004_SetPin(IO004_Handle0);
//		else if ( strcmp(pcValue[0], "off") == 0)
//			IO004_ResetPin(IO004_Handle0);
//	}
//	DEBUGOUT("actuarorsHandler has been called!\r\n");

	return "/index.shtml";
}
