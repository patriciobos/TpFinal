################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwip/src/core/def.c \
../lwip/src/core/dhcp.c \
../lwip/src/core/dns.c \
../lwip/src/core/init.c \
../lwip/src/core/mem.c \
../lwip/src/core/memp.c \
../lwip/src/core/netif.c \
../lwip/src/core/pbuf.c \
../lwip/src/core/raw.c \
../lwip/src/core/stats.c \
../lwip/src/core/sys.c \
../lwip/src/core/tcp.c \
../lwip/src/core/tcp_in.c \
../lwip/src/core/tcp_out.c \
../lwip/src/core/timers.c \
../lwip/src/core/udp.c 

OBJS += \
./lwip/src/core/def.o \
./lwip/src/core/dhcp.o \
./lwip/src/core/dns.o \
./lwip/src/core/init.o \
./lwip/src/core/mem.o \
./lwip/src/core/memp.o \
./lwip/src/core/netif.o \
./lwip/src/core/pbuf.o \
./lwip/src/core/raw.o \
./lwip/src/core/stats.o \
./lwip/src/core/sys.o \
./lwip/src/core/tcp.o \
./lwip/src/core/tcp_in.o \
./lwip/src/core/tcp_out.o \
./lwip/src/core/timers.o \
./lwip/src/core/udp.o 

C_DEPS += \
./lwip/src/core/def.d \
./lwip/src/core/dhcp.d \
./lwip/src/core/dns.d \
./lwip/src/core/init.d \
./lwip/src/core/mem.d \
./lwip/src/core/memp.d \
./lwip/src/core/netif.d \
./lwip/src/core/pbuf.d \
./lwip/src/core/raw.d \
./lwip/src/core/stats.d \
./lwip/src/core/sys.d \
./lwip/src/core/tcp.d \
./lwip/src/core/tcp_in.d \
./lwip/src/core/tcp_out.d \
./lwip/src/core/timers.d \
./lwip/src/core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
lwip/src/core/%.o: ../lwip/src/core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -D__REDLIB__ -DCORE_M4 -I"/home/patricio/Embebidos/tpfinal/Workspace LPCOPEN/lpc_chip_43xx/inc" -I"/home/patricio/Embebidos/tpfinal/Workspace LPCOPEN/lpc_board_nxp_lpcxpresso_4337/inc" -I"/home/patricio/Embebidos/tpfinal/Workspace LPCOPEN/lwip_freertos_webserver/example/inc" -I"/home/patricio/Embebidos/tpfinal/Workspace LPCOPEN/lwip_freertos_webserver/lwip/inc" -I"/home/patricio/Embebidos/tpfinal/Workspace LPCOPEN/lwip_freertos_webserver/lwip/inc/ipv4" -I"/home/patricio/Embebidos/tpfinal/Workspace LPCOPEN/lwip_freertos_webserver/fatfs/inc" -I"/home/patricio/Embebidos/tpfinal/Workspace LPCOPEN/lwip_freertos_webserver/freertos/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


