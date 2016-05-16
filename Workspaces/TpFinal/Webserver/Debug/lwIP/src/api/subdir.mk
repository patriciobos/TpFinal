################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwIP/src/api/api_lib.c \
../lwIP/src/api/api_msg.c \
../lwIP/src/api/err.c \
../lwIP/src/api/netbuf.c \
../lwIP/src/api/netdb.c \
../lwIP/src/api/netifapi.c \
../lwIP/src/api/sockets.c \
../lwIP/src/api/tcpip.c 

OBJS += \
./lwIP/src/api/api_lib.o \
./lwIP/src/api/api_msg.o \
./lwIP/src/api/err.o \
./lwIP/src/api/netbuf.o \
./lwIP/src/api/netdb.o \
./lwIP/src/api/netifapi.o \
./lwIP/src/api/sockets.o \
./lwIP/src/api/tcpip.o 

C_DEPS += \
./lwIP/src/api/api_lib.d \
./lwIP/src/api/api_msg.d \
./lwIP/src/api/err.d \
./lwIP/src/api/netbuf.d \
./lwIP/src/api/netdb.d \
./lwIP/src/api/netifapi.d \
./lwIP/src/api/sockets.d \
./lwIP/src/api/tcpip.d 


# Each subdirectory must supply rules for building sources it contributes
lwIP/src/api/%.o: ../lwIP/src/api/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -D__USE_LPCOPEN -DDEBUG -D__CODE_RED -DCORE_M4 -D__LPC43XX__ -D__NEWLIB__ -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/Control/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/lwIP/inc/ipv4" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/freeRTOS/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/HAL/Board/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/HAL/Chip/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/HAL/Chip/inc/usbd" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/lwIP/inc" -I/usr/local/lpcxpresso_8.0.0_526/lpcxpresso/tools/arm-none-eabi/include -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


