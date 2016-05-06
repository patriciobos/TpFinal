################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Control/src/cr_redlib_heap_fix.c \
../Control/src/lwip_tcpecho_freertos.c \
../Control/src/newlib_stubs.c \
../Control/src/tcpecho.c 

OBJS += \
./Control/src/cr_redlib_heap_fix.o \
./Control/src/lwip_tcpecho_freertos.o \
./Control/src/newlib_stubs.o \
./Control/src/tcpecho.o 

C_DEPS += \
./Control/src/cr_redlib_heap_fix.d \
./Control/src/lwip_tcpecho_freertos.d \
./Control/src/newlib_stubs.d \
./Control/src/tcpecho.d 


# Each subdirectory must supply rules for building sources it contributes
Control/src/%.o: ../Control/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX -D__CODE_RED -DLPC43_MULTICORE_M0APP -D__MULTICORE_MASTER -D__MULTICORE_MASTER_SLAVE_M0APP -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Base/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Chip/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Board/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Drivers/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/Control/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/arch" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/ipv4" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/lwip" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/netif" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/posix" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/ipv4/lwip" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/freeRTOS/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


