################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/coordinate_handler.c \
../Src/main.c \
../Src/pwm_handler.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/coordinate_handler.o \
./Src/main.o \
./Src/pwm_handler.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/coordinate_handler.d \
./Src/main.d \
./Src/pwm_handler.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411CEUx -c -I../Inc -I/Users/jourdanrampoldi/workspace/CMSIS/Include -I/Users/jourdanrampoldi/workspace/CMSIS/Device/ST/STM32F4xx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/coordinate_handler.cyclo ./Src/coordinate_handler.d ./Src/coordinate_handler.o ./Src/coordinate_handler.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/pwm_handler.cyclo ./Src/pwm_handler.d ./Src/pwm_handler.o ./Src/pwm_handler.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

