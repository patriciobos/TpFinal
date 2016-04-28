################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/G4intl/G4intl.c 

OBJS += \
./src/G4intl/G4intl.o 

C_DEPS += \
./src/G4intl/G4intl.d 


# Each subdirectory must supply rules for building sources it contributes
src/G4intl/%.o: ../src/G4intl/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_CMSIS=CMSISv2p00_LPC17xx -DLIB_MCU_LPC134x=134 -DLIB_MCU_LPC176x=176 -D__TARGET_PORT=LIB_MCU_LPC176x -DFreeRTOSv7p0p1=701 -D__USE_FREERTOS=FreeRTOSv7p0p1 -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\CMSISv2p00_LPC17xx\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_Contenedores\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_API_CAPI\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_MCU_LPC176x\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_MCU_LPC176x\vendor drivers\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_FreeRTOS_7p0p1\demo_code" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_FreeRTOS_7p0p1\FreeRTOS_include" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_FreeRTOS_7p0p1\FreeRTOS_portable" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src\lwIP\include" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src\lwIP\include\ipv4" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src\lwIP\netif\include" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src\lwIP\lwIP_Apps" -Og -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


