################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwIP/src/netif/etharp.c \
../lwIP/src/netif/ethernetif.c 

OBJS += \
./lwIP/src/netif/etharp.o \
./lwIP/src/netif/ethernetif.o 

C_DEPS += \
./lwIP/src/netif/etharp.d \
./lwIP/src/netif/ethernetif.d 


# Each subdirectory must supply rules for building sources it contributes
lwIP/src/netif/%.o: ../lwIP/src/netif/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -DCORE_M4 -D__LPC43XX__ -D__NEWLIB__ -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/Control/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/lwIP/inc/ipv4" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/freeRTOS/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/HAL/Board/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/HAL/Chip/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/HAL/Chip/inc/usbd" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/lwIP/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

