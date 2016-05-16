################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwIP/src/core/def.c \
../lwIP/src/core/dhcp.c \
../lwIP/src/core/dns.c \
../lwIP/src/core/init.c \
../lwIP/src/core/mem.c \
../lwIP/src/core/memp.c \
../lwIP/src/core/netif.c \
../lwIP/src/core/pbuf.c \
../lwIP/src/core/raw.c \
../lwIP/src/core/stats.c \
../lwIP/src/core/sys.c \
../lwIP/src/core/tcp.c \
../lwIP/src/core/tcp_in.c \
../lwIP/src/core/tcp_out.c \
../lwIP/src/core/timers.c \
../lwIP/src/core/udp.c 

OBJS += \
./lwIP/src/core/def.o \
./lwIP/src/core/dhcp.o \
./lwIP/src/core/dns.o \
./lwIP/src/core/init.o \
./lwIP/src/core/mem.o \
./lwIP/src/core/memp.o \
./lwIP/src/core/netif.o \
./lwIP/src/core/pbuf.o \
./lwIP/src/core/raw.o \
./lwIP/src/core/stats.o \
./lwIP/src/core/sys.o \
./lwIP/src/core/tcp.o \
./lwIP/src/core/tcp_in.o \
./lwIP/src/core/tcp_out.o \
./lwIP/src/core/timers.o \
./lwIP/src/core/udp.o 

C_DEPS += \
./lwIP/src/core/def.d \
./lwIP/src/core/dhcp.d \
./lwIP/src/core/dns.d \
./lwIP/src/core/init.d \
./lwIP/src/core/mem.d \
./lwIP/src/core/memp.d \
./lwIP/src/core/netif.d \
./lwIP/src/core/pbuf.d \
./lwIP/src/core/raw.d \
./lwIP/src/core/stats.d \
./lwIP/src/core/sys.d \
./lwIP/src/core/tcp.d \
./lwIP/src/core/tcp_in.d \
./lwIP/src/core/tcp_out.d \
./lwIP/src/core/timers.d \
./lwIP/src/core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
lwIP/src/core/%.o: ../lwIP/src/core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -D__USE_LPCOPEN -DDEBUG -D__CODE_RED -DCORE_M4 -D__LPC43XX__ -D__NEWLIB__ -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/Control/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/lwIP/inc/ipv4" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/freeRTOS/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/HAL/Board/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/HAL/Chip/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/HAL/Chip/inc/usbd" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/lwIP/inc" -I/usr/local/lpcxpresso_8.0.0_526/lpcxpresso/tools/arm-none-eabi/include -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


