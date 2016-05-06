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
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -D__REDLIB__ -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/lpc_chip_43xx/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/lpc_chip_43xx/inc/usbd" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/Control/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/Board/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/lwip" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/freeRTOS/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/arch" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/ipv4" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/ipv4/lwip" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/netif" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/posix" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/posix/sys" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


