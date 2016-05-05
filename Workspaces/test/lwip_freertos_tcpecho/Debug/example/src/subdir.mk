################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/cr_startup_lpc43xx.c \
../example/src/freertos_tcpecho.c \
../example/src/sysinit.c \
../example/src/tcpecho.c 

OBJS += \
./example/src/cr_startup_lpc43xx.o \
./example/src/freertos_tcpecho.o \
./example/src/sysinit.o \
./example/src/tcpecho.o 

C_DEPS += \
./example/src/cr_startup_lpc43xx.d \
./example/src/freertos_tcpecho.d \
./example/src/sysinit.d \
./example/src/tcpecho.d 


# Each subdirectory must supply rules for building sources it contributes
example/src/%.o: ../example/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -D__REDLIB__ -DCORE_M4 -I"/home/pato/Embebidos/TpFinal/Workspaces/test/lpc_chip_43xx/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/lwip_freertos_tcpecho/example/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/lwip_freertos_tcpecho/lwip/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/lwip_freertos_tcpecho/lwip/inc/ipv4" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/lwip_freertos_tcpecho/freertos/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


