/*
 * actuators.h
 *
 *  Created on: 23 de may. de 2016
 *      Author: pato
 */

#ifndef INC_ACTUATORS_H_
#define INC_ACTUATORS_H_

typedef enum {OFF = 0, ON = !OFF} actuatorState_t;

enum {portNum_1 = 0,
	  portNum_2,
	  portNum_3,
	  portNum_4
};

const char *actuatorsHandler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);

char* getActuatorState(int portNum);

#endif /* INC_ACTUATORS_H_ */
