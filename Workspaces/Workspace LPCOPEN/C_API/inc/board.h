/*
 * board.h
 *
 *  Created on: 12/11/2015
 *      Author: Juan Manuel Cruz
 */

#ifndef BOARD_H_
#define BOARD_H_


#include "C_API.h"

#include "irqs.h"
#include "leds.h"
#include "rgbs.h"
#include "gpios.h"
#include "rits.h"
#include "pwms.h"
#include "uarts.h"
#include "adcs.h"
#include "dacs.h"
#include "delays.h"
#include "teclas.h"


void initBoard (void);
void initBoardCiaaNxp ();


#endif /* BOARD_H_ */
