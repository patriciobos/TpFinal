################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freeRTOS/src/FreeRTOSCommonHooks.c \
../freeRTOS/src/croutine.c \
../freeRTOS/src/event_groups.c \
../freeRTOS/src/heap_4.c \
../freeRTOS/src/list.c \
../freeRTOS/src/port.c \
../freeRTOS/src/queue.c \
../freeRTOS/src/redlib_memfix.c \
../freeRTOS/src/tasks.c \
../freeRTOS/src/timers.c 

OBJS += \
./freeRTOS/src/FreeRTOSCommonHooks.o \
./freeRTOS/src/croutine.o \
./freeRTOS/src/event_groups.o \
./freeRTOS/src/heap_4.o \
./freeRTOS/src/list.o \
./freeRTOS/src/port.o \
./freeRTOS/src/queue.o \
./freeRTOS/src/redlib_memfix.o \
./freeRTOS/src/tasks.o \
./freeRTOS/src/timers.o 

C_DEPS += \
./freeRTOS/src/FreeRTOSCommonHooks.d \
./freeRTOS/src/croutine.d \
./freeRTOS/src/event_groups.d \
./freeRTOS/src/heap_4.d \
./freeRTOS/src/list.d \
./freeRTOS/src/port.d \
./freeRTOS/src/queue.d \
./freeRTOS/src/redlib_memfix.d \
./freeRTOS/src/tasks.d \
./freeRTOS/src/timers.d 


# Each subdirectory must supply rules for building sources it contributes
freeRTOS/src/%.o: ../freeRTOS/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -DCORE_M4 -D__USE_LPCOPEN -D__LPC43XX -D__CODE_RED -DLPC43_MULTICORE_M0APP -D__MULTICORE_MASTER -D__MULTICORE_MASTER_SLAVE_M0APP -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Base/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Chip/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Board/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/HAL/Drivers/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/Control/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/arch" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/ipv4" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/lwip" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/netif" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/posix" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc/ipv4/lwip" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/lwIP/inc" -I"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/Acuario/freeRTOS/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


