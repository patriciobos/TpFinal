################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwip/src/netif/etharp.c \
../lwip/src/netif/ethernetif.c 

OBJS += \
./lwip/src/netif/etharp.o \
./lwip/src/netif/ethernetif.o 

C_DEPS += \
./lwip/src/netif/etharp.d \
./lwip/src/netif/ethernetif.d 


# Each subdirectory must supply rules for building sources it contributes
lwip/src/netif/%.o: ../lwip/src/netif/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -D__REDLIB__ -DCORE_M4 -I"/home/pato/Embebidos/tpfinal/Workspace LPCOPEN/lpc_chip_43xx/inc" -I"/home/pato/Embebidos/tpfinal/Workspace LPCOPEN/lpc_board_nxp_lpcxpresso_4337/inc" -I"/home/pato/Embebidos/tpfinal/Workspace LPCOPEN/lwip_freertos_tcpecho/example/inc" -I"/home/pato/Embebidos/tpfinal/Workspace LPCOPEN/lwip_freertos_tcpecho/lwip/inc" -I"/home/pato/Embebidos/tpfinal/Workspace LPCOPEN/lwip_freertos_tcpecho/lwip/inc/ipv4" -I"/home/pato/Embebidos/tpfinal/Workspace LPCOPEN/lwip_freertos_tcpecho/freertos/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


