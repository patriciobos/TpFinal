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
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -D__REDLIB__ -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/lpc_chip_43xx/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/lpc_chip_43xx/inc/usbd" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/Control/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/Board/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/lwip" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/freeRTOS/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/arch" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/ipv4" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/ipv4/lwip" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/netif" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/posix" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/posix/sys" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


