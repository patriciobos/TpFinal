################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lwIP/src/netif/subdir.mk
-include lwIP/src/core/ipv4/subdir.mk
-include lwIP/src/core/subdir.mk
-include lwIP/src/arch/subdir.mk
-include lwIP/src/api/subdir.mk
-include freeRTOS/src/subdir.mk
-include HAL/Drivers/src/subdir.mk
-include HAL/Chip/src/subdir.mk
-include HAL/Board/src/subdir.mk
-include HAL/Base/src/subdir.mk
-include Control/src/subdir.mk
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
all: Acuario.axf

# Tool invocations
Acuario.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="Acuario.map" -Xlinker --gc-sections -mcpu=cortex-m4 -mthumb -T "Acuario_Debug.ld" -o "Acuario.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Acuario.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Acuario.axf"; # arm-none-eabi-objcopy -v -O binary "Acuario.axf" "Acuario.bin" ; # checksum -p LPC4337 -d "Acuario.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
