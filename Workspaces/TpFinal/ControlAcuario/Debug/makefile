################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include lwIP/src/netif/subdir.mk
-include lwIP/src/core/ipv4/subdir.mk
-include lwIP/src/core/subdir.mk
-include lwIP/src/arch/subdir.mk
-include lwIP/src/api/subdir.mk
-include freeRTOS/src/subdir.mk
-include Board/src/subdir.mk
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
all: ControlAcuario.axf

# Tool invocations
ControlAcuario.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/pato/Embebidos/TpFinal/Workspaces/TpFinal/lpc_chip_43xx/Debug" -Xlinker -Map="ControlAcuario.map" -Xlinker --gc-sections -mcpu=cortex-m4 -mthumb -T "ControlAcuario_Debug.ld" -o "ControlAcuario.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ControlAcuario.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "ControlAcuario.axf"; # arm-none-eabi-objcopy -v -O binary "ControlAcuario.axf" "ControlAcuario.bin" ; # checksum -p LPC4337 -d "ControlAcuario.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
