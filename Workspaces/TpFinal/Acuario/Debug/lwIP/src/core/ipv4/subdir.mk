################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwIP/src/core/ipv4/autoip.c \
../lwIP/src/core/ipv4/icmp.c \
../lwIP/src/core/ipv4/igmp.c \
../lwIP/src/core/ipv4/inet.c \
../lwIP/src/core/ipv4/inet_chksum.c \
../lwIP/src/core/ipv4/ip.c \
../lwIP/src/core/ipv4/ip_addr.c \
../lwIP/src/core/ipv4/ip_frag.c 

OBJS += \
./lwIP/src/core/ipv4/autoip.o \
./lwIP/src/core/ipv4/icmp.o \
./lwIP/src/core/ipv4/igmp.o \
./lwIP/src/core/ipv4/inet.o \
./lwIP/src/core/ipv4/inet_chksum.o \
./lwIP/src/core/ipv4/ip.o \
./lwIP/src/core/ipv4/ip_addr.o \
./lwIP/src/core/ipv4/ip_frag.o 

C_DEPS += \
./lwIP/src/core/ipv4/autoip.d \
./lwIP/src/core/ipv4/icmp.d \
./lwIP/src/core/ipv4/igmp.d \
./lwIP/src/core/ipv4/inet.d \
./lwIP/src/core/ipv4/inet_chksum.d \
./lwIP/src/core/ipv4/ip.d \
./lwIP/src/core/ipv4/ip_addr.d \
./lwIP/src/core/ipv4/ip_frag.d 


# Each subdirectory must supply rules for building sources it contributes
lwIP/src/core/ipv4/%.o: ../lwIP/src/core/ipv4/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX -D__CODE_RED -DLPC43_MULTICORE_M0APP -D__MULTICORE_MASTER -D__MULTICORE_MASTER_SLAVE_M0APP -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Base/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Chip/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Board/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Drivers/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/Control/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/arch" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/ipv4" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/lwip" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/netif" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/posix" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/ipv4/lwip" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/freeRTOS/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


