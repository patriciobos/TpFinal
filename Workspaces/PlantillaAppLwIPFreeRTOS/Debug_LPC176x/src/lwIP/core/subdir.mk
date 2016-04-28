################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lwIP/core/def.c \
../src/lwIP/core/dhcp.c \
../src/lwIP/core/dns.c \
../src/lwIP/core/init.c \
../src/lwIP/core/lwip_timers.c \
../src/lwIP/core/mem.c \
../src/lwIP/core/memp.c \
../src/lwIP/core/netif.c \
../src/lwIP/core/pbuf.c \
../src/lwIP/core/raw.c \
../src/lwIP/core/stats.c \
../src/lwIP/core/sys.c \
../src/lwIP/core/tcp.c \
../src/lwIP/core/tcp_in.c \
../src/lwIP/core/tcp_out.c \
../src/lwIP/core/udp.c 

OBJS += \
./src/lwIP/core/def.o \
./src/lwIP/core/dhcp.o \
./src/lwIP/core/dns.o \
./src/lwIP/core/init.o \
./src/lwIP/core/lwip_timers.o \
./src/lwIP/core/mem.o \
./src/lwIP/core/memp.o \
./src/lwIP/core/netif.o \
./src/lwIP/core/pbuf.o \
./src/lwIP/core/raw.o \
./src/lwIP/core/stats.o \
./src/lwIP/core/sys.o \
./src/lwIP/core/tcp.o \
./src/lwIP/core/tcp_in.o \
./src/lwIP/core/tcp_out.o \
./src/lwIP/core/udp.o 

C_DEPS += \
./src/lwIP/core/def.d \
./src/lwIP/core/dhcp.d \
./src/lwIP/core/dns.d \
./src/lwIP/core/init.d \
./src/lwIP/core/lwip_timers.d \
./src/lwIP/core/mem.d \
./src/lwIP/core/memp.d \
./src/lwIP/core/netif.d \
./src/lwIP/core/pbuf.d \
./src/lwIP/core/raw.d \
./src/lwIP/core/stats.d \
./src/lwIP/core/sys.d \
./src/lwIP/core/tcp.d \
./src/lwIP/core/tcp_in.d \
./src/lwIP/core/tcp_out.d \
./src/lwIP/core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
src/lwIP/core/%.o: ../src/lwIP/core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_CMSIS=CMSISv2p00_LPC17xx -DLIB_MCU_LPC134x=134 -DLIB_MCU_LPC176x=176 -D__TARGET_PORT=LIB_MCU_LPC176x -DFreeRTOSv7p0p1=701 -D__USE_FREERTOS=FreeRTOSv7p0p1 -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\CMSISv2p00_LPC17xx\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_Contenedores\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_API_CAPI\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_MCU_LPC176x\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_MCU_LPC176x\vendor drivers\inc" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_FreeRTOS_7p0p1\demo_code" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_FreeRTOS_7p0p1\FreeRTOS_include" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_FreeRTOS_7p0p1\FreeRTOS_portable" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src\lwIP\include" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src\lwIP\include\ipv4" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src\lwIP\netif\include" -I"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\PlantillaAppLwIPFreeRTOS\src\lwIP\lwIP_Apps" -Og -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


