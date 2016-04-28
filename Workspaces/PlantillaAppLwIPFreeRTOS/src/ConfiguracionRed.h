/*
 * ConfiguracionRed.h
 *
 *  Created on: 20/11/2013
 *      Author: Alejandro
 */

#ifndef CONFIGURACIONRED_H_
#define CONFIGURACIONRED_H_


#define configMAC_INTERRUPT_PRIORITY				( 2 )
#define configLWIP_TASK_PRIORITY					( 2 )
#define configCOMMAND_INTERPRETER_TASK_PRIORITY		( 3U )

#define configCOMMAND_INTERPRETER_STACK_SIZE		( configMINIMAL_STACK_SIZE * 4 )
#define conifgTCPIP_TASK_STACK_SIZE					( configMINIMAL_STACK_SIZE * 4 )

/*-----------------------------------------------------------
 * Ethernet configuration.
 *-----------------------------------------------------------*/

/* MAC address configuration. */
#define configMAC_ADDR0	0x00
#define configMAC_ADDR1	0x12
#define configMAC_ADDR2	0x13
#define configMAC_ADDR3	0x10
#define configMAC_ADDR4	0x15
#define configMAC_ADDR5	0x11

/* IP address configuration. */
#define configIP_ADDR0		192
#define configIP_ADDR1		168
#define configIP_ADDR2		0
#define configIP_ADDR3		200

/* Gateway IP address configuration. */
#define configGW_IP_ADDR0	192
#define configGW_IP_ADDR1	168
#define configGW_IP_ADDR2	0
#define configGW_IP_ADDR3	1

/* Netmask configuration. */
#define configNET_MASK0		255
#define configNET_MASK1		255
#define configNET_MASK2		255
#define configNET_MASK3		0

#endif /* CONFIGURACIONRED_H_ */
