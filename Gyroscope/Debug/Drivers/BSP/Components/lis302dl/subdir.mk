################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/lis302dl/lis302dl.c 

OBJS += \
./Drivers/BSP/Components/lis302dl/lis302dl.o 

C_DEPS += \
./Drivers/BSP/Components/lis302dl/lis302dl.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/lis302dl/%.o Drivers/BSP/Components/lis302dl/%.su: ../Drivers/BSP/Components/lis302dl/%.c Drivers/BSP/Components/lis302dl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -IC:/Users/quann/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/quann/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/quann/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/quann/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/quann/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/BSP/STM32F429I-Discovery" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-lis302dl

clean-Drivers-2f-BSP-2f-Components-2f-lis302dl:
	-$(RM) ./Drivers/BSP/Components/lis302dl/lis302dl.d ./Drivers/BSP/Components/lis302dl/lis302dl.o ./Drivers/BSP/Components/lis302dl/lis302dl.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-lis302dl

