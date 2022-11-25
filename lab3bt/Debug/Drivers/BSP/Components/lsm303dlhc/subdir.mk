################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/lsm303dlhc/lsm303dlhc.c 

OBJS += \
./Drivers/BSP/Components/lsm303dlhc/lsm303dlhc.o 

C_DEPS += \
./Drivers/BSP/Components/lsm303dlhc/lsm303dlhc.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/lsm303dlhc/%.o Drivers/BSP/Components/lsm303dlhc/%.su: ../Drivers/BSP/Components/lsm303dlhc/%.c Drivers/BSP/Components/lsm303dlhc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"C:/Users/quann/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/BSP/STM32F429I-Discovery" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-lsm303dlhc

clean-Drivers-2f-BSP-2f-Components-2f-lsm303dlhc:
	-$(RM) ./Drivers/BSP/Components/lsm303dlhc/lsm303dlhc.d ./Drivers/BSP/Components/lsm303dlhc/lsm303dlhc.o ./Drivers/BSP/Components/lsm303dlhc/lsm303dlhc.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-lsm303dlhc

