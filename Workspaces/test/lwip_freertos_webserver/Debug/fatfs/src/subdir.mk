################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../fatfs/src/ff.c \
../fatfs/src/fs_mci.c \
../fatfs/src/rtc.c 

OBJS += \
./fatfs/src/ff.o \
./fatfs/src/fs_mci.o \
./fatfs/src/rtc.o 

C_DEPS += \
./fatfs/src/ff.d \
./fatfs/src/fs_mci.d \
./fatfs/src/rtc.d 


# Each subdirectory must supply rules for building sources it contributes
fatfs/src/%.o: ../fatfs/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -D__REDLIB__ -DCORE_M4 -I"/home/pato/Embebidos/TpFinal/Workspaces/test/lpc_chip_43xx/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/lpc_board_nxp_lpcxpresso_4337/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/lwip_freertos_webserver/example/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/lwip_freertos_webserver/lwip/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/lwip_freertos_webserver/lwip/inc/ipv4" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/lwip_freertos_webserver/fatfs/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/test/lwip_freertos_webserver/freertos/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


