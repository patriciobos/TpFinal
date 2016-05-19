#ifndef WEB_CGI_H
#define WEB_CGI_H

//#include "cf_board.h"

#include "lpc_types.h"

/*
 * The command table entry data structure
 */
typedef const struct
{
    char *  command;                /* CGI string id  */
    int    (*func)(CHAR *, void *); /* actual function to call */
} CGI_CMD;

/*FSL:prototypes*/

/*FSL: extern functions*/

extern int
uart_configuration_process(CHAR *name, void *request);

extern int
reset_configuration_process(CHAR *name, void *request);

extern int
spi_configuration_process(CHAR *name, void *request);

extern int
mac_configuration_process(CHAR *name, void *request);

extern int
tcp_configuration_process(CHAR *name, void *request);

/*
 * Macros for User InterFace command table entries
 */

#ifndef CGI_UART_CONFIGURATION
#define CGI_UART_CONFIGURATION    \
    {"uart.cgi",uart_configuration_process}
#endif

#ifndef CGI_SPI_CONFIGURATION
#define CGI_SPI_CONFIGURATION    \
    {"spi.cgi",spi_configuration_process}
#endif

#ifndef CGI_MAC_CONFIGURATION
#define CGI_MAC_CONFIGURATION    \
    {"mac.cgi",mac_configuration_process}
#endif

#ifndef CGI_TCP_CONFIGURATION
#define CGI_TCP_CONFIGURATION    \
    {"tcp.cgi",tcp_configuration_process}
#endif

#ifndef CGI_RESET_CONFIGURATION
#define CGI_RESET_CONFIGURATION    \
    {"reset.cgi",reset_configuration_process}
#endif

#define CGI_MAX_COMMANDS       		sizeof(CGI_CMD_ARRAY)/sizeof(CGI_CMD )

/**
 * Implements a CGI call
 *
 * @param CGI name
 * @param argument to be used for CGI called function 
 * @return returned value by function linked to execute by POST request
 */
uint8_t
CGI_parser(int8_t *name, void *request);

#endif
