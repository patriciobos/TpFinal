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
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -DCORE_M4 -D__LPC43XX__ -D__NEWLIB__ -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/Control/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/lwIP/inc/ipv4" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/freeRTOS/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/HAL/Board/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/HAL/Chip/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/HAL/Chip/inc/usbd" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/Webserver/lwIP/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


