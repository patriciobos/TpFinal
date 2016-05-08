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
	arm-none-eabi-gcc -DDEBUG -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX -D__CODE_RED -DLPC43_MULTICORE_M0APP -D__MULTICORE_NONE -D__REDLIB__ -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Base/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Chip/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Board/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Drivers/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/Control/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/arch" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/ipv4" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/lwip" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/netif" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/posix" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/ipv4/lwip" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/freeRTOS/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


