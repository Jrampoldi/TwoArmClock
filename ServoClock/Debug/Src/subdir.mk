################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/UART_handler.c \
../Src/coordinate_handler.c \
../Src/main.c \
../Src/pwm_handler.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/tim_handler.c 

OBJS += \
./Src/UART_handler.o \
./Src/coordinate_handler.o \
./Src/main.o \
./Src/pwm_handler.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/tim_handler.o 

C_DEPS += \
./Src/UART_handler.d \
./Src/coordinate_handler.d \
./Src/main.d \
./Src/pwm_handler.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/tim_handler.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4=1 -DSTM32 -DSTM32F4 -DSTM32F411CEUx -c -I../Inc -I/Users/jourdanrampoldi/workspace/CMSIS/Include -I/Users/jourdanrampoldi/workspace/CMSIS/Device/ST/STM32F4xx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/UART_handler.cyclo ./Src/UART_handler.d ./Src/UART_handler.o ./Src/UART_handler.su ./Src/coordinate_handler.cyclo ./Src/coordinate_handler.d ./Src/coordinate_handler.o ./Src/coordinate_handler.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/pwm_handler.cyclo ./Src/pwm_handler.d ./Src/pwm_handler.o ./Src/pwm_handler.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/tim_handler.cyclo ./Src/tim_handler.d ./Src/tim_handler.o ./Src/tim_handler.su

.PHONY: clean-Src

