################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Base/cr_startup_lpc43xx.c \
../HAL/Base/crp.c \
../HAL/Base/sysinit.c 

OBJS += \
./HAL/Base/cr_startup_lpc43xx.o \
./HAL/Base/crp.o \
./HAL/Base/sysinit.o 

C_DEPS += \
./HAL/Base/cr_startup_lpc43xx.d \
./HAL/Base/crp.d \
./HAL/Base/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Base/%.o: ../HAL/Base/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -D__USE_LPCOPEN -DDEBUG -D__CODE_RED -DCORE_M4 -D__LPC43XX__ -D__NEWLIB__ -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/Control/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/lwIP/inc/ipv4" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/freeRTOS/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/HAL/Board/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/HAL/Chip/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/HAL/Chip/inc/usbd" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Webserver/lwIP/inc" -I/usr/local/lpcxpresso_8.0.0_526/lpcxpresso/tools/arm-none-eabi/include -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


