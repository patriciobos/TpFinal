 /*
 *  pwms.h
 *
 *  Created on: 12/11/2015
 *      Author: Juan Manuel Cruz
 */

#ifndef RITS_H_
#define RITS_H_


#include "C_API.h"

void configRit (uint16_t timeInterval_ms, void (*isr)(void));


#endif /* RITS_H_ */
