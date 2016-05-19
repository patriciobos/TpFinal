#include "http_cgi.h"
#include "stdlib.h"

#include "lpc_types.h"

#include "setget.h"
#include "utilities.h"

/*variable to hold if a reset must be issued*/
uint8_t reset_var = FALSE;
/*reusing buffers for CGI processing*/
uint8_t *u8Archivo;

/*list of cgi's for this process*/
CGI_CMD CGI_CMD_ARRAY[]  = 
{
  CGI_UART_CONFIGURATION,              /*config.shtml: configuration file*/
  CGI_SPI_CONFIGURATION,               /*spi.shtml: configuration file*/
  CGI_MAC_CONFIGURATION,               /*mac.shtml: configuration file*/
  CGI_TCP_CONFIGURATION,               /*tcp.shtml: configuration file*/
  CGI_RESET_CONFIGURATION
};

/**
 * Implements a CGI call
 *
 * @param CGI name
 * @param argument to be used for CGI called function 
 * @return returned value by function linked to execute by POST request
 */
uint8_t
CGI_parser(int8_t *name, void *request)
{
     uint8_t i;

     for(i=0;i<CGI_MAX_COMMANDS;i++)
     {
        if(!strncmp((const char *)name,(const char *)CGI_CMD_ARRAY[i].command,strlen(CGI_CMD_ARRAY[i].command)))//contains array
        {
            return CGI_CMD_ARRAY[i].func((char *)name,request);//execute function if matches
        }
     }
     //CGI: no replacement was found!!!
     return NULL;
}

//***************************************************************************//

int reset_configuration_process(char *name, void *request)
{
    /*stop watchdog, let's see what happens*/
    (void)request;

    /*file for POST request*/
    strcpy(name,"X");
    reset_var = TRUE;
    
    return 1;
}

//static int
//uart_configuration_process(char *name, void *request)
//{
//    /*FSL:start configuration processing*/
//    uint8_t *string;
//
//    /*variable holding ROM info to be write*/
//    ROM_OPTIONS data;
//
//    /*search for string on linked list: reusing SD buffer*/
//    if((string = search_string_linked_list(request, u8Archivo, (uint8_t *)STRING_DOUBLE_END, NULL)) != NULL)
//    {
//        /*read*/
//        get_all_params(&data);
//
//        /*parse string*/
//
//        //baud
//        data.uart_baud             = (uint32_t)parse_number((uint8_t **)&string,'=',10);
//        //port
//        data.uart_port             = (uint8_t)parse_number((uint8_t **)&string,'=',10);
//        //parity
//        data.uart_parity           = (uint8_t)parse_number((uint8_t **)&string,'=',10);
//        //number of bits
//        data.uart_number_of_bits   = (uint8_t)parse_number((uint8_t **)&string,'=',10);
//        //stop bits
//        data.uart_stop_bits        = (uint8_t)parse_number((uint8_t **)&string,'=',10);
//        //flow control
//        data.uart_flow_control     = (uint8_t)parse_number((uint8_t **)&string,'=',10);
//
//        //validate it????
//
//        /*write*/
//        set_all_params(&data);
//    }
//
//    /*file for POST request*/
//    strcpy(name,"CONFIG.SHTML");
//
//    return 1;
//}
//
//static int
//spi_configuration_process(char *name, void *request)
//{
//    /*FSL:start configuration processing*/
//    uint8_t *string;
//
//    /*variable holding ROM info to be write*/
//    ROM_OPTIONS data;
//
//    /*search for string on linked list: reusing SD buffer*/
//    if((string = search_string_linked_list(request, u8Archivo, (uint8_t *)STRING_DOUBLE_END, NULL)) != NULL)
//    {
//        /*read*/
//        get_all_params(&data);
//
//        /*parse string*/
//
//        //baud
//        data.spi_baud      = (uint32_t)parse_number((uint8_t **)&string,'=',10);
//        //port
//        data.spi_port      = (uint8_t)parse_number((uint8_t **)&string,'=',10);
//        //polarity
//        data.spi_polarity  = (uint8_t)parse_number((uint8_t **)&string,'=',10);
//        //phase
//        data.spi_phase     = (uint8_t)parse_number((uint8_t **)&string,'=',10);
//        //master
//        data.spi_master    = (uint8_t)parse_number((uint8_t **)&string,'=',10);
//        //polling-interrupt
//        data.spi_interrupt = (uint8_t)parse_number((uint8_t **)&string,'=',10);
//
//        //validate it????
//
//        /*write*/
//        set_all_params(&data);
//    }
//
//    /*file for POST request*/
//    strcpy(name,"SPI.SHTML");
//
//    return 1;
//}

int mac_configuration_process(char *name, void *request)
{        
    /*FSL:start configuration processing*/
    uint8_t *string;
    
    /*temporal buffer*/
    char temp[18];
    
    /*variable holding ROM info to be write*/
    ROM_OPTIONS data;
    
    /*search for string on linked list: reusing SD buffer*/
    if((string = search_string_linked_list(request, u8Archivo, (uint8_t *)STRING_DOUBLE_END, NULL)) != NULL)
    {
        /*read*/
        get_all_params(&data);
        
        /*parse string*/
        
        //mac address
        parse_mac_ip_address_string((uint8_t **)&string,(uint8_t *)&temp,'=','&');
        if(temp[0] != 0)/*only write if different to NULL*/
          parse_ethaddr(temp,&data.eth_ethaddr[0]);        
        //ip address
        parse_mac_ip_address_string((uint8_t **)&string,(uint8_t *)&temp,'=','&');
        if(temp[0] != 0)/*only write if different to NULL*/
          ip_convert_address(temp,(CHAR *)&data.eth_ip_add[0]);
        
        //mask address
        parse_mac_ip_address_string((uint8_t **)&string,(uint8_t *)&temp,'=','&');
        if(temp[0] != 0)/*only write if different to NULL*/
          ip_convert_address(temp,(CHAR *)&data.eth_netmask[0]);
        
        //gw address
        parse_mac_ip_address_string((uint8_t **)&string,(uint8_t *)&temp,'=','&');
        if(temp[0] != 0)/*only write if different to NULL*/
          ip_convert_address(temp,(CHAR *)&data.eth_gateway[0]);        
        
        //server address
        parse_mac_ip_address_string((uint8_t **)&string,(uint8_t *)&temp,'=','&');
        if(temp[0] != 0)/*only write if different to NULL*/
          ip_convert_address(temp,(CHAR *)&data.eth_server_add[0]);
        
        //polling-interrupt
        data.eth_dhcp_auto = (uint8_t)parse_number((uint8_t **)&string,'=',10);;
        
        /*write*/
        set_all_params(&data);
    }
    
    /*file for POST request*/
    strcpy(name,"MAC.SHTML");
    
    return 1;
}

int tcp_configuration_process(char *name, void *request)
{        
    /*FSL:start configuration processing*/
    uint8_t *string;
    
    /*variable holding ROM info to be write*/
    ROM_OPTIONS data;
    
    /*search for string on linked list: reusing SD buffer*/
    if((string = search_string_linked_list(request, u8Archivo, (uint8_t *)STRING_DOUBLE_END, NULL)) != NULL)
    {
        /*read*/
        get_all_params(&data);
        
        /*parse string*/
        
        //port
        data.bridge_tcp_port      = (uint16_t)parse_number((uint8_t **)&string,'=',10);
        //client-server
        data.bridge_tcp_server    = (uint8_t)parse_number((uint8_t **)&string,'=',10);
        //config or bridge
        data.bridge_configuration = (uint8_t)parse_number((uint8_t **)&string,'=',10);
        //uart, spi or iic
        data.bridge_tcp_mode      = (uint8_t)parse_number((uint8_t **)&string,'=',10);
        //validate it????
        
        /*write*/
        set_all_params(&data);
    }
    
    /*file for POST request*/
    strcpy(name,"TCP.SHTML");
    
    return 1;
}
