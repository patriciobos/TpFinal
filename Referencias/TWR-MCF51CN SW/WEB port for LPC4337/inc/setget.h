/*
 * File:        setget.h
 * Purpose:     Definitions for common parameters
 *
 * Notes:
 */

#ifndef _SETGET_H_
#define _SETGET_H_

/********************************************************************/

#define STRING_SIZE                    (40)

/* 
 * Structure definition for the Parameters 
 */
typedef struct
{
    /*Ethernet options*/                    //bytes
    uint8_t   eth_ethaddr[6];                 //6: mac add
    uint8_t   eth_ip_add[4];                  //4: target ip add
    uint8_t   eth_netmask[4];                 //4: netmask
    uint8_t   eth_gateway[4];                 //4: gateway
    uint8_t   eth_server_add[4];              //4: connect to server...
    uint8_t   eth_dhcp_auto;                  //1: get ip address
    uint8_t   eth_pad;                        //1

    /*General Bridge options*/
    uint8_t   bridge_configuration;           //1: config bridge or bridge
    uint8_t   bridge_tcp_mode;                //1: uart, spi or iic
    uint8_t   bridge_tcp_server;              //1: server/client for bridge
    uint16_t  bridge_tcp_port;                //2: port used by bridges
    uint8_t   bridge_pad;                     //1

    /*UART options*/
    uint8_t   uart_port;                      //1
    uint32_t  uart_baud;                      //4
    uint8_t   uart_parity;                    //1
    uint8_t   uart_number_of_bits;            //1
    uint8_t   uart_stop_bits;                 //1
    uint8_t   uart_flow_control;              //1: sw, hw or none
    uint8_t   uart_pad;                       //1

    /*SPI options*/
    uint8_t   spi_port;                       //1
    uint16_t  spi_baud;                       //2
    uint8_t   spi_polarity;                   //1
    uint8_t   spi_phase;                      //1
    uint8_t   spi_master;                     //1: master or slave
    uint8_t   spi_interrupt;                  //1: interrupt or polling
    uint8_t   spi_pad;                        //1
    
    /*I2C options*/
    //TBD
    
    /*Email options*/
    char    email_username[STRING_SIZE];    //40
    char    email_password[STRING_SIZE];    //40
    char    email_smtp_server[STRING_SIZE]; //40
    uint8_t   email_authentication_required;  //1
    
} ROM_OPTIONS;
                                        
#define ROM_OPTIONS_SIZE                sizeof(ROM_OPTIONS)
#define ROM_OPTIONS_LONG_SIZE           ROM_OPTIONS_SIZE/4 /*longwords*/

/*One byte: get & set*/
typedef const struct
{
    uint8_t    (*get)(void); /* GET function to call */
    void    (*set)(uint8_t); /* SET function to call */
} ONE_BYTE;

/*Two bytes: get & set*/
typedef const struct
{
    uint16_t    (*get)(void); /* GET function to call */
    void    (*set)(uint16_t); /* SET function to call */
} TWO_BYTES;

/*Four bytes: get & set*/
typedef const struct
{
    uint32_t    (*get)(void); /* GET function to call */
    void    (*set)(uint32_t); /* SET function to call */
} FOUR_BYTES;

/*Six bytes: get & set*/
typedef const struct
{
    void    (*get)(uint8_t *); /* GET function to call */
    void    (*set)(uint8_t *); /* SET function to call */
} SIX_BYTES;

/*size of function arrays*/
#define ONE_BYTE_ELEMENTS     (sizeof(one_byte_array)/sizeof(one_byte_array[0]))
#define TWO_BYTES_ELEMENTS    (sizeof(two_bytes_array)/sizeof(two_bytes_array[0]))
#define FOUR_BYTES_ELEMENTS   (sizeof(four_bytes_array)/sizeof(four_bytes_array[0]))
#define SIX_BYTES_ELEMENTS    (sizeof(six_bytes_array)/sizeof(six_bytes_array[0]))

/*Prototypes*/

/*function to get array elements*/
uint8_t
get_one_byte_elements();
uint8_t
get_two_bytes_elements();
uint8_t
get_four_bytes_elements();
uint8_t
get_six_bytes_elements();

void
update_board_params (uint8_t *data, uint16_t length, uint32_t offset);

/********************************************************************/

#endif /* _SETGET_H_ */
