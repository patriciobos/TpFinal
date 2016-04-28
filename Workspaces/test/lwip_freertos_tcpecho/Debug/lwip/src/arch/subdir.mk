################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwip/src/arch/lpc18xx_43xx_emac.c \
../lwip/src/arch/lpc_debug.c \
../lwip/src/arch/sys_arch_freertos.c 

OBJS += \
./lwip/src/arch/lpc18xx_43xx_emac.o \
./lwip/src/arch/lpc_debug.o \
./lwip/src/arch/sys_arch_freertos.o 

C_DEPS += \
./lwip/src/arch/lpc18xx_43xx_emac.d \
./lwip/src/arch/lpc_debug.d \
./lwip/src/arch/sys_arch_freertos.d 


# Each subdirectory must supply rules for building sources it contributes
lwip/src/arch/%.o: ../lwip/src/arch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -D__REDLIB__ -DCORE_M4 -I"/home/pato/Embebidos/tpfinal/test/lpc_chip_43xx/inc" -I"/home/pato/Embebidos/tpfinal/test/lpc_board_nxp_lpcxpresso_4337/inc" -I"/home/pato/Embebidos/tpfinal/test/lwip_freertos_tcpecho/example/inc" -I"/home/pato/Embebidos/tpfinal/test/lwip_freertos_tcpecho/lwip/inc" -I"/home/pato/Embebidos/tpfinal/test/lwip_freertos_tcpecho/lwip/inc/ipv4" -I"/home/pato/Embebidos/tpfinal/test/lwip_freertos_tcpecho/freertos/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


