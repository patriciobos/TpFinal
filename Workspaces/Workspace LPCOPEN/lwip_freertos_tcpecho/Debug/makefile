################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lwip/src/netif/subdir.mk
-include lwip/src/core/ipv4/subdir.mk
-include lwip/src/core/subdir.mk
-include lwip/src/arch/subdir.mk
-include lwip/src/api/subdir.mk
-include freertos/src/subdir.mk
-include example/src/subdir.mk
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
all: lwip_freertos_tcpecho.axf

# Tool invocations
lwip_freertos_tcpecho.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/pato/Embebidos/TpFinal/Workspaces/Workspace LPCOPEN/lpc_chip_43xx/Debug" -L"/home/pato/Embebidos/TpFinal/Workspaces/Workspace LPCOPEN/ciaa_board_nxp_lpcxpresso_4337/Debug" -Xlinker -Map="lwip_freertos_tcpecho.map" -Xlinker --gc-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -T "lwip_freertos_tcpecho_Debug.ld" -o "lwip_freertos_tcpecho.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) lwip_freertos_tcpecho.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "lwip_freertos_tcpecho.axf"; # arm-none-eabi-objcopy -v -O binary "lwip_freertos_tcpecho.axf" "lwip_freertos_tcpecho.bin" ; # checksum -p LPC4337 -d "lwip_freertos_tcpecho.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
