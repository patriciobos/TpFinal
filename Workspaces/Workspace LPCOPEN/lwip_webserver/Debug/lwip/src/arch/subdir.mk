################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwip/src/arch/lpc18xx_43xx_emac.c \
../lwip/src/arch/lpc18xx_43xx_systick_arch.c \
../lwip/src/arch/lpc_debug.c 

OBJS += \
./lwip/src/arch/lpc18xx_43xx_emac.o \
./lwip/src/arch/lpc18xx_43xx_systick_arch.o \
./lwip/src/arch/lpc_debug.o 

C_DEPS += \
./lwip/src/arch/lpc18xx_43xx_emac.d \
./lwip/src/arch/lpc18xx_43xx_systick_arch.d \
./lwip/src/arch/lpc_debug.d 


# Each subdirectory must supply rules for building sources it contributes
lwip/src/arch/%.o: ../lwip/src/arch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -D__REDLIB__ -DCORE_M4 -I"/home/pato/Embebidos/TpFinal/Workspaces/Workspace LPCOPEN/lpc_chip_43xx/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/Workspace LPCOPEN/lpc_board_nxp_lpcxpresso_4337/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/Workspace LPCOPEN/lwip_webserver/example/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/Workspace LPCOPEN/lwip_webserver/lwip/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/Workspace LPCOPEN/lwip_webserver/lwip/inc/ipv4" -I"/home/pato/Embebidos/TpFinal/Workspaces/Workspace LPCOPEN/lwip_webserver/fatfs/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


