################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma2d.c \
../Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.c \
../Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_ltdc.c \
../Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sdram.c \
../Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_spi.c \
../Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.c 

OBJS += \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma2d.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_ltdc.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sdram.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_spi.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.o 

C_DEPS += \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma2d.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_ltdc.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sdram.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_spi.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_HAL_Driver/%.o Drivers/STM32F4xx_HAL_Driver/%.su: ../Drivers/STM32F4xx_HAL_Driver/%.c Drivers/STM32F4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/quann/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/BSP/STM32F429I-Discovery" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F4xx_HAL_Driver

clean-Drivers-2f-STM32F4xx_HAL_Driver:
	-$(RM) ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma2d.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma2d.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma2d.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_i2c.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_ltdc.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_ltdc.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_ltdc.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sdram.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sdram.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_sdram.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_spi.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_spi.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_spi.su ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.d ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.o ./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_ll_fmc.su

.PHONY: clean-Drivers-2f-STM32F4xx_HAL_Driver

