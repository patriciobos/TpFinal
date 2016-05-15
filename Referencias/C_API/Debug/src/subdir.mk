################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/C_API_FUNCTIONAL_TEST.c \
../src/adcs.c \
../src/board.c \
../src/dacs.c \
../src/delays.c \
../src/gpios.c \
../src/irqs.c \
../src/leds.c \
../src/pwms.c \
../src/rgbs.c \
../src/rits.c \
../src/sysinit.c \
../src/teclas.c \
../src/uarts.c 

OBJS += \
./src/C_API_FUNCTIONAL_TEST.o \
./src/adcs.o \
./src/board.o \
./src/dacs.o \
./src/delays.o \
./src/gpios.o \
./src/irqs.o \
./src/leds.o \
./src/pwms.o \
./src/rgbs.o \
./src/rits.o \
./src/sysinit.o \
./src/teclas.o \
./src/uarts.o 

C_DEPS += \
./src/C_API_FUNCTIONAL_TEST.d \
./src/adcs.d \
./src/board.d \
./src/dacs.d \
./src/delays.d \
./src/gpios.d \
./src/irqs.d \
./src/leds.d \
./src/pwms.d \
./src/rgbs.d \
./src/rits.d \
./src/sysinit.d \
./src/teclas.d \
./src/uarts.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -I"/home/pato/Embebidos/tpfinal/test/lpc_chip_43xx/inc" -I"/home/pato/Embebidos/tpfinal/test/lpc_chip_43xx/inc/usbd" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


