################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Drivers/src/ciaaAIN.c \
../HAL/Drivers/src/ciaaAOUT.c \
../HAL/Drivers/src/ciaaI2C.c \
../HAL/Drivers/src/ciaaIO.c \
../HAL/Drivers/src/ciaaNVM.c \
../HAL/Drivers/src/ciaaUART.c 

OBJS += \
./HAL/Drivers/src/ciaaAIN.o \
./HAL/Drivers/src/ciaaAOUT.o \
./HAL/Drivers/src/ciaaI2C.o \
./HAL/Drivers/src/ciaaIO.o \
./HAL/Drivers/src/ciaaNVM.o \
./HAL/Drivers/src/ciaaUART.o 

C_DEPS += \
./HAL/Drivers/src/ciaaAIN.d \
./HAL/Drivers/src/ciaaAOUT.d \
./HAL/Drivers/src/ciaaI2C.d \
./HAL/Drivers/src/ciaaIO.d \
./HAL/Drivers/src/ciaaNVM.d \
./HAL/Drivers/src/ciaaUART.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Drivers/src/%.o: ../HAL/Drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX -D__CODE_RED -DLPC43_MULTICORE_M0APP -D__MULTICORE_NONE -D__REDLIB__ -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Base/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Chip/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Board/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Drivers/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/Control/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/arch" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/ipv4" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/lwip" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/netif" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/posix" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/ipv4/lwip" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc" -I"/home/patricio/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/freeRTOS/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


