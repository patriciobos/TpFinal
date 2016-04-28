//*****************************************************************************
//   +--+       
//   | ++----+   
//   +-++    |  
//     |     |  
//   +-+--+  |   
//   | +--+--+  
//   +----+    Copyright (c) 2009-10 Code Red Technologies Ltd.
//
// Microcontroller Startup code for use with Red Suite
//
// Version : 101130
//
// Software License Agreement
//
// The software is owned by Code Red Technologies and/or its suppliers, and is
// protected under applicable copyright laws.  All rights are reserved.  Any
// use in violation of the foregoing restrictions may subject the user to criminal
// sanctions under applicable laws, as well as to civil liability for the breach
// of the terms and conditions of this license.
//
// THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
// OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
// USE OF THIS SOFTWARE FOR COMMERCIAL DEVELOPMENT AND/OR EDUCATION IS SUBJECT
// TO A CURRENT END USER LICENSE AGREEMENT (COMMERCIAL OR EDUCATIONAL) WITH
// CODE RED TECHNOLOGIES LTD.
//
//*****************************************************************************
#if defined (__cplusplus)
#ifdef __REDLIB__
#error Redlib does not support C++
#else
//*****************************************************************************
//
// The entry point for the C++ library startup
//
//*****************************************************************************
extern "C" {
	extern void __libc_init_array(void);
}
#endif
#endif

#define WEAK __attribute__ ((weak))
#define ALIAS(f) __attribute__ ((weak, alias (#f)))

// Code Red - if CMSIS is being used, then SystemInit() routine
// will be called by startup code rather than in application's main()
#if defined (__USE_CMSIS)
#include "system_LPC13xx.h"
#endif

//*****************************************************************************
#if defined (__cplusplus)
extern "C" {
#endif

//*****************************************************************************
//
// Forward declaration of the default handlers. These are aliased.
// When the application defines a handler (with the same name), this will
// automatically take precedence over these weak definitions
//
//*****************************************************************************
     void ResetISR(void);
WEAK void NMI_Handler(void);
WEAK void HardFault_Handler(void);
WEAK void MemManage_Handler(void);
WEAK void BusFault_Handler(void);
WEAK void UsageFault_Handler(void);
WEAK void SVCall_Handler(void);
WEAK void DebugMon_Handler(void);
WEAK void PendSV_Handler(void);
WEAK void SysTick_Handler(void);
WEAK void IntDefaultHandler(void);

//*****************************************************************************
//
// Forward declaration of the specific IRQ handlers. These are aliased
// to the IntDefaultHandler, which is a 'forever' loop. When the application
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//
//*****************************************************************************

void I2C_IRQHandler (void) ALIAS(IntDefaultHandler);
void TIMER16_0_IRQHandler (void) ALIAS(IntDefaultHandler);
void TIMER16_1_IRQHandler (void) ALIAS(IntDefaultHandler);
void TIMER32_0_IRQHandler (void) ALIAS(IntDefaultHandler);
void TIMER32_1_IRQHandler (void) ALIAS(IntDefaultHandler);
void SSP_IRQHandler (void) ALIAS(IntDefaultHandler);
void UART_IRQHandler (void) ALIAS(IntDefaultHandler);
void USB_IRQHandler (void) ALIAS(IntDefaultHandler);
void USB_FIQHandler (void) ALIAS(IntDefaultHandler);
void ADC_IRQHandler (void) ALIAS(IntDefaultHandler);
void WDT_IRQHandler (void) ALIAS(IntDefaultHandler);
void BOD_IRQHandler (void) ALIAS(IntDefaultHandler);
void FMC_IRQHandler (void) ALIAS(IntDefaultHandler);
void PIOINT3_IRQHandler (void) ALIAS(IntDefaultHandler);
void PIOINT2_IRQHandler (void) ALIAS(IntDefaultHandler);
void PIOINT1_IRQHandler (void) ALIAS(IntDefaultHandler);
void PIOINT0_IRQHandler (void) ALIAS(IntDefaultHandler);
void WAKEUP_IRQHandler  (void) ALIAS(IntDefaultHandler);

extern void xPortSysTickHandler(void);
extern void xPortPendSVHandler(void);
extern void vPortSVCHandler( void );

//*****************************************************************************
//
// The entry point for the application.
// __main() is the entry point for Redlib based applications
// main() is the entry point for Newlib based applications
//
//*****************************************************************************
#if defined (__REDLIB__)
extern void __main(void);
#endif
extern int main(void);
//*****************************************************************************
//
// External declaration for the pointer to the stack top from the Linker Script
//
//*****************************************************************************
extern void _vStackTop(void);

//*****************************************************************************
#if defined (__cplusplus)
} // extern "C"
#endif
//*****************************************************************************
//
// The vector table.
// This relies on the linker script to place at correct location in memory.
//
//*****************************************************************************
extern void (* const g_pfnVectors[])(void);
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {
	// Core Level - CM3
	&_vStackTop, // The initial stack pointer
	ResetISR,								// The reset handler
	NMI_Handler,							// The NMI handler
	HardFault_Handler,						// The hard fault handler
	MemManage_Handler,						// The MPU fault handler
	BusFault_Handler,						// The bus fault handler
	UsageFault_Handler,						// The usage fault handler
	0,										// Reserved
	0,										// Reserved
	0,										// Reserved
	0,										// Reserved
	vPortSVCHandler,                        // SVCall handler
	DebugMon_Handler,						// Debug monitor handler
	0,										// Reserved
	xPortPendSVHandler,                     // The PendSV handler
	xPortSysTickHandler,                    // The SysTick handler

    // Wakeup sources (40 ea.) for the I/O pins:
    //   PIO0 (0:11)
    //   PIO1 (0:11)
    //   PIO2 (0:11)
    //   PIO3 (0:3)
    WAKEUP_IRQHandler,                      // PIO0_0  Wakeup
    WAKEUP_IRQHandler,                      // PIO0_1  Wakeup
    WAKEUP_IRQHandler,                      // PIO0_2  Wakeup
    WAKEUP_IRQHandler,                      // PIO0_3  Wakeup
    WAKEUP_IRQHandler,                      // PIO0_4  Wakeup
    WAKEUP_IRQHandler,                      // PIO0_5  Wakeup
    WAKEUP_IRQHandler,                      // PIO0_6  Wakeup
    WAKEUP_IRQHandler,                      // PIO0_7  Wakeup
    WAKEUP_IRQHandler,                      // PIO0_8  Wakeup
    WAKEUP_IRQHandler,                      // PIO0_9  Wakeup
    WAKEUP_IRQHandler,                      // PIO0_10 Wakeup
    WAKEUP_IRQHandler,                      // PIO0_11 Wakeup

    WAKEUP_IRQHandler,                      // PIO1_0  Wakeup
    WAKEUP_IRQHandler,                      // PIO1_1  Wakeup
    WAKEUP_IRQHandler,                      // PIO1_2  Wakeup
    WAKEUP_IRQHandler,                      // PIO1_3  Wakeup
    WAKEUP_IRQHandler,                      // PIO1_4  Wakeup
    WAKEUP_IRQHandler,                      // PIO1_5  Wakeup
    WAKEUP_IRQHandler,                      // PIO1_6  Wakeup
    WAKEUP_IRQHandler,                      // PIO1_7  Wakeup
    WAKEUP_IRQHandler,                      // PIO1_8  Wakeup
    WAKEUP_IRQHandler,                      // PIO1_9  Wakeup
    WAKEUP_IRQHandler,                      // PIO1_10 Wakeup
    WAKEUP_IRQHandler,                      // PIO1_11 Wakeup

    WAKEUP_IRQHandler,                      // PIO2_0  Wakeup
    WAKEUP_IRQHandler,                      // PIO2_1  Wakeup
    WAKEUP_IRQHandler,                      // PIO2_2  Wakeup
    WAKEUP_IRQHandler,                      // PIO2_3  Wakeup
    WAKEUP_IRQHandler,                      // PIO2_4  Wakeup
    WAKEUP_IRQHandler,                      // PIO2_5  Wakeup
    WAKEUP_IRQHandler,                      // PIO2_6  Wakeup
    WAKEUP_IRQHandler,                      // PIO2_7  Wakeup
    WAKEUP_IRQHandler,                      // PIO2_8  Wakeup
    WAKEUP_IRQHandler,                      // PIO2_9  Wakeup
    WAKEUP_IRQHandler,                      // PIO2_10 Wakeup
    WAKEUP_IRQHandler,                      // PIO2_11 Wakeup

    WAKEUP_IRQHandler,                      // PIO3_0  Wakeup
    WAKEUP_IRQHandler,                      // PIO3_1  Wakeup
    WAKEUP_IRQHandler,                      // PIO3_2  Wakeup
    WAKEUP_IRQHandler,                      // PIO3_3  Wakeup  
    
    I2C_IRQHandler,                      // I2C0
    TIMER16_0_IRQHandler,                      // CT16B0 (16-bit Timer 0)
    TIMER16_1_IRQHandler,                      // CT16B1 (16-bit Timer 1)
    TIMER32_0_IRQHandler,                      // CT32B0 (32-bit Timer 0)
    TIMER32_1_IRQHandler,                      // CT32B1 (32-bit Timer 1)
    SSP_IRQHandler,                      // SSP0
    UART_IRQHandler,                      // UART0

    USB_IRQHandler,                                      // USB IRQ
    USB_FIQHandler,                                      // USB FIQ

    ADC_IRQHandler,                      // ADC   (A/D Converter)
    WDT_IRQHandler,                      // WDT   (Watchdog Timer)
    BOD_IRQHandler,                      // BOD   (Brownout Detect)
    FMC_IRQHandler,                      // Flash (IP2111 Flash Memory Controller)
    PIOINT3_IRQHandler,                      // PIO INT3
    PIOINT2_IRQHandler,                      // PIO INT2
    PIOINT1_IRQHandler,                      // PIO INT1
    PIOINT0_IRQHandler,                      // PIO INT0
    
};

//*****************************************************************************
// Functions to carry out the initialization of RW and BSS data sections. These
// are written as separate functions rather than being inlined within the
// ResetISR() function in order to cope with MCUs with multiple banks of
// memory.
//*****************************************************************************
__attribute__ ((section(".after_vectors")))
void data_init(unsigned int romstart, unsigned int start, unsigned int len) {
	unsigned int *pulDest = (unsigned int*) start;
	unsigned int *pulSrc = (unsigned int*) romstart;
	unsigned int loop;
	for (loop = 0; loop < len; loop = loop + 4)
		*pulDest++ = *pulSrc++;
}

__attribute__ ((section(".after_vectors")))
void bss_init(unsigned int start, unsigned int len) {
	unsigned int *pulDest = (unsigned int*) start;
	unsigned int loop;
	for (loop = 0; loop < len; loop = loop + 4)
		*pulDest++ = 0;
}

#ifndef USE_OLD_STYLE_DATA_BSS_INIT
//*****************************************************************************
// The following symbols are constructs generated by the linker, indicating
// the location of various points in the "Global Section Table". This table is
// created by the linker via the Code Red managed linker script mechanism. It
// contains the load address, execution address and length of each RW data
// section and the execution and length of each BSS (zero initialized) section.
//*****************************************************************************
extern unsigned int __data_section_table;
extern unsigned int __data_section_table_end;
extern unsigned int __bss_section_table;
extern unsigned int __bss_section_table_end;
#else
//*****************************************************************************
// The following symbols are constructs generated by the linker, indicating
// the load address, execution address and length of the RW data section and
// the execution and length of the BSS (zero initialized) section.
// Note that these symbols are not normally used by the managed linker script
// mechanism in Red Suite/LPCXpresso 3.6 (Windows) and LPCXpresso 3.8 (Linux).
// They are provide here simply so this startup code can be used with earlier
// versions of Red Suite which do not support the more advanced managed linker
// script mechanism introduced in the above version. To enable their use,
// define "USE_OLD_STYLE_DATA_BSS_INIT".
//*****************************************************************************
extern unsigned int _etext;
extern unsigned int _data;
extern unsigned int _edata;
extern unsigned int _bss;
extern unsigned int _ebss;
#endif


//*****************************************************************************
// Reset entry point for your code.
// Sets up a simple runtime environment and initializes the C/C++
// library.
//*****************************************************************************
__attribute__ ((section(".after_vectors")))
void
ResetISR(void) {

#ifndef USE_OLD_STYLE_DATA_BSS_INIT
    //
    // Copy the data sections from flash to SRAM.
    //
	unsigned int LoadAddr, ExeAddr, SectionLen;
	unsigned int *SectionTableAddr;

	// Load base address of Global Section Table
	SectionTableAddr = &__data_section_table;

    // Copy the data sections from flash to SRAM.
	while (SectionTableAddr < &__data_section_table_end) {
		LoadAddr = *SectionTableAddr++;
		ExeAddr = *SectionTableAddr++;
		SectionLen = *SectionTableAddr++;
		data_init(LoadAddr, ExeAddr, SectionLen);
	}
	// At this point, SectionTableAddr = &__bss_section_table;
	// Zero fill the bss segment
	while (SectionTableAddr < &__bss_section_table_end) {
		ExeAddr = *SectionTableAddr++;
		SectionLen = *SectionTableAddr++;
		bss_init(ExeAddr, SectionLen);
	}
#else
	// Use Old Style Data and BSS section initialization.
	// This will only initialize a single RAM bank.
	unsigned int * LoadAddr, *ExeAddr, *EndAddr, SectionLen;

    // Copy the data segment from flash to SRAM.
	LoadAddr = &_etext;
	ExeAddr = &_data;
	EndAddr = &_edata;
	SectionLen = (void*)EndAddr - (void*)ExeAddr;
	data_init((unsigned int)LoadAddr, (unsigned int)ExeAddr, SectionLen);
	// Zero fill the bss segment
	ExeAddr = &_bss;
	EndAddr = &_ebss;
	SectionLen = (void*)EndAddr - (void*)ExeAddr;
	bss_init ((unsigned int)ExeAddr, SectionLen);
#endif

#ifdef __USE_CMSIS
	SystemInit();
#endif

#if defined (__cplusplus)
	//
	// Call C++ library initialisation
	//
	__libc_init_array();
#endif

#if defined (__REDLIB__)
	// Call the Redlib library, which in turn calls main()
	__main() ;
#else
	main();
#endif

	//
	// main() shouldn't return, but if it does, we'll just enter an infinite loop
	//
	while (1) {
		;
	}
}

//*****************************************************************************
// Default exception handlers. Override the ones here by defining your own
// handler routines in your application code.
//*****************************************************************************
__attribute__ ((section(".after_vectors")))
void NMI_Handler(void)
{
    while(1)
    {
    }
}
__attribute__ ((section(".after_vectors")))
void HardFault_Handler(void)
{
    while(1)
    {
    }
}
__attribute__ ((section(".after_vectors")))
void MemManage_Handler(void)
{
    while(1)
    {
    }
}
__attribute__ ((section(".after_vectors")))
void BusFault_Handler(void)
{
    while(1)
    {
    }
}
__attribute__ ((section(".after_vectors")))
void UsageFault_Handler(void)
{
    while(1)
    {
    }
}
__attribute__ ((section(".after_vectors")))
void SVCall_Handler(void)
{
    while(1)
    {
    }
}
__attribute__ ((section(".after_vectors")))
void DebugMon_Handler(void)
{
    while(1)
    {
    }
}
__attribute__ ((section(".after_vectors")))
void PendSV_Handler(void)
{
    while(1)
    {
    }
}
__attribute__ ((section(".after_vectors")))
void SysTick_Handler(void)
{
    while(1)
    {
    }
}

//*****************************************************************************
//
// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.
//
//*****************************************************************************
__attribute__ ((section(".after_vectors")))
void IntDefaultHandler(void)
{
    while(1)
    {
    }
}
