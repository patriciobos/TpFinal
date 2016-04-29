################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
all: ciaa_periph_blinky.axf

# Tool invocations
ciaa_periph_blinky.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/patricio/Embebidos/tpfinal/Workspace LPCOPEN/lpc_chip_43xx/Debug" -L"/home/patricio/Embebidos/tpfinal/Workspace LPCOPEN/ciaa_board_nxp_lpcxpresso_4337/Debug" -Xlinker -Map="ciaa_periph_blinky.map" -Xlinker --gc-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -T "periph_blinky_Debug.ld" -o "ciaa_periph_blinky.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ciaa_periph_blinky.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "ciaa_periph_blinky.axf"; # arm-none-eabi-objcopy -v -O binary "ciaa_periph_blinky.axf" "ciaa_periph_blinky.bin" ; # checksum -p LPC4337 -d "ciaa_periph_blinky.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
