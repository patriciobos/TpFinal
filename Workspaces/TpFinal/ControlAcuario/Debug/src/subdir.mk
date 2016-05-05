################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ControlAcuario.c \
../src/cr_startup_lpc43xx.c \
../src/crp.c \
../src/sysinit.c 

OBJS += \
./src/ControlAcuario.o \
./src/cr_startup_lpc43xx.o \
./src/crp.o \
./src/sysinit.o 

C_DEPS += \
./src/ControlAcuario.d \
./src/cr_startup_lpc43xx.d \
./src/crp.d \
./src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_LPCOPEN -DNO_BOARD_LIB -D__LPC43XX__ -D__REDLIB__ -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/ControlAcuario/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/lpc_chip_43xx/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/lpc_chip_43xx/inc/usbd" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


