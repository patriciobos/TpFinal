################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/lwIP/netif/subdir.mk
-include src/lwIP/lwIP_Apps/httpserver_raw/subdir.mk
-include src/lwIP/lwIP_Apps/FrasesCelebres/subdir.mk
-include src/lwIP/lwIP_Apps/BridgeTCP_UART/subdir.mk
-include src/lwIP/lwIP_Apps/subdir.mk
-include src/lwIP/core/ipv4/subdir.mk
-include src/lwIP/core/subdir.mk
-include src/lwIP/api/subdir.mk
-include src/G4intl/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: PlantillaAppLwIPFreeRTOS.axf

# Tool invocations
PlantillaAppLwIPFreeRTOS.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map=PlantillaAppLwIPFreeRTOS.map -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "PlantillaAppLwIPFreeRTOS_Debug_LPC176x.ld" -L"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\CMSISv2p00_LPC17xx\Debug" -L"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_MCU_LPC176x\Debug" -L"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_Contenedores\Debug" -L"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_API_CAPI\Debug" -L"E:\FAKU\Sistemas_Embebidos\WORKSPACES\RTOS_Teoria\Lib_FreeRTOS_7p0p1\Debug_LPC176x" -o  "PlantillaAppLwIPFreeRTOS.axf" $(OBJS) $(USER_OBJS) $(LIBS) -lCMSISv2p00_LPC17xx -lLib_API_CAPI -lLib_Contenedores -lLib_MCU_LPC176x -lLib_FreeRTOS_7p0p1
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) PlantillaAppLwIPFreeRTOS.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size PlantillaAppLwIPFreeRTOS.axf; # arm-none-eabi-objcopy -O binary PlantillaAppLwIPFreeRTOS.axf PlantillaAppLwIPFreeRTOS.bin ; checksum -p LPC1769 -d PlantillaAppLwIPFreeRTOS.bin;
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
