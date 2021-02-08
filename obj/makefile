################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include TYIOT/subdir.mk
-include Libraries/wch_libraries/Startup/subdir.mk
-include Libraries/wch_libraries/Peripheral/subdir.mk
-include Libraries/wch_libraries/Core/subdir.mk
-include Libraries/seekfree_peripheral/subdir.mk
-include Libraries/seekfree_libraries/subdir.mk
-include Libraries/board/subdir.mk
-include Libraries/Motor/subdir.mk
-include Libraries/Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
IOT_tuya.hex \

SECONDARY_LIST += \
IOT_tuya.lst \

SECONDARY_SIZE += \
IOT_tuya.siz \


# All Target
all: IOT_tuya.elf secondary-outputs

# Tool invocations
IOT_tuya.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -T .ld -nostartfiles -Xlinker --gc-sections -L"../" -Wl,-Map,"IOT_tuya.map" --specs=nano.specs --specs=nosys.specs -o "IOT_tuya.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
IOT_tuya.hex: IOT_tuya.elf
	@	riscv-none-embed-objcopy -O ihex "IOT_tuya.elf"  "IOT_tuya.hex"
	@	@
IOT_tuya.lst: IOT_tuya.elf
	@	riscv-none-embed-objdump --source --all-headers --demangle --line-numbers --wide "IOT_tuya.elf" > "IOT_tuya.lst"
	@	@
IOT_tuya.siz: IOT_tuya.elf
	@	riscv-none-embed-size --format=berkeley "IOT_tuya.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) IOT_tuya.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
