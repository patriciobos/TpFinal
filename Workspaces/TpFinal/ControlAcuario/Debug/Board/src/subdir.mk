################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Board/src/board.c \
../Board/src/board_sysinit.c \
../Board/src/lpc_phy_smsc87x0.c 

OBJS += \
./Board/src/board.o \
./Board/src/board_sysinit.o \
./Board/src/lpc_phy_smsc87x0.o 

C_DEPS += \
./Board/src/board.d \
./Board/src/board_sysinit.d \
./Board/src/lpc_phy_smsc87x0.d 


# Each subdirectory must supply rules for building sources it contributes
Board/src/%.o: ../Board/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX__ -D__REDLIB__ -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/arch" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/ipv4" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/lwip" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/netif" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc/posix" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/Board/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/freeRTOS/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/lwIP/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/lpc_chip_43xx/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/lpc_chip_43xx/inc/usbd" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


