################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lwIP/api/api_lib.c \
../src/lwIP/api/api_msg.c \
../src/lwIP/api/err.c \
../src/lwIP/api/netbuf.c \
../src/lwIP/api/netdb.c \
../src/lwIP/api/netifapi.c \
../src/lwIP/api/sockets.c \
../src/lwIP/api/tcpip.c 

OBJS += \
./src/lwIP/api/api_lib.o \
./src/lwIP/api/api_msg.o \
./src/lwIP/api/err.o \
./src/lwIP/api/netbuf.o \
./src/lwIP/api/netdb.o \
./src/lwIP/api/netifapi.o \
./src/lwIP/api/sockets.o \
./src/lwIP/api/tcpip.o 

C_DEPS += \
./src/lwIP/api/api_lib.d \
./src/lwIP/api/api_msg.d \
./src/lwIP/api/err.d \
./src/lwIP/api/netbuf.d \
./src/lwIP/api/netdb.d \
./src/lwIP/api/netifapi.d \
./src/lwIP/api/sockets.d \
./src/lwIP/api/tcpip.d 


# Each subdirectory must supply rules for building sources it contributes
src/lwIP/api/%.o: ../src/lwIP/api/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_CMSIS=CMSISv2p00_LPC17xx -DLIB_MCU_LPC134x=134 -DLIB_MCU_LPC176x=176 -D__TARGET_PORT=LIB_MCU_LPC176x -DFreeRTOSv7p0p1=701 -D__USE_FREERTOS=FreeRTOSv7p0p1 -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\CMSISv2p00_LPC17xx\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_Contenedores\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_API_CAPI\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_MCU_LPC176x\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_MCU_LPC176x\vendor drivers\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_FreeRTOS_7p0p1\demo_code" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_FreeRTOS_7p0p1\FreeRTOS_include" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_FreeRTOS_7p0p1\FreeRTOS_portable" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src\lwIP\include" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src\lwIP\include\ipv4" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src\lwIP\netif\include" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src\lwIP\lwIP_Apps" -Og -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


