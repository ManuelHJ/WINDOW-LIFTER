################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/MAL/GPIO_Config.c" \
"../src/MAL/LEDS_IDLE.c" \
"../src/MAL/PCC_Config.c" \
"../src/MAL/PORT_Config.c" \
"../src/MAL/SCG_Config.c" \
"../src/MAL/WDOG_Config.c" \
"../src/MAL/time100ms.c" \
"../src/MAL/time400ms.c" \

C_SRCS += \
../src/MAL/GPIO_Config.c \
../src/MAL/LEDS_IDLE.c \
../src/MAL/PCC_Config.c \
../src/MAL/PORT_Config.c \
../src/MAL/SCG_Config.c \
../src/MAL/WDOG_Config.c \
../src/MAL/time100ms.c \
../src/MAL/time400ms.c \

OBJS_OS_FORMAT += \
./src/MAL/GPIO_Config.o \
./src/MAL/LEDS_IDLE.o \
./src/MAL/PCC_Config.o \
./src/MAL/PORT_Config.o \
./src/MAL/SCG_Config.o \
./src/MAL/WDOG_Config.o \
./src/MAL/time100ms.o \
./src/MAL/time400ms.o \

C_DEPS_QUOTED += \
"./src/MAL/GPIO_Config.d" \
"./src/MAL/LEDS_IDLE.d" \
"./src/MAL/PCC_Config.d" \
"./src/MAL/PORT_Config.d" \
"./src/MAL/SCG_Config.d" \
"./src/MAL/WDOG_Config.d" \
"./src/MAL/time100ms.d" \
"./src/MAL/time400ms.d" \

OBJS += \
./src/MAL/GPIO_Config.o \
./src/MAL/LEDS_IDLE.o \
./src/MAL/PCC_Config.o \
./src/MAL/PORT_Config.o \
./src/MAL/SCG_Config.o \
./src/MAL/WDOG_Config.o \
./src/MAL/time100ms.o \
./src/MAL/time400ms.o \

OBJS_QUOTED += \
"./src/MAL/GPIO_Config.o" \
"./src/MAL/LEDS_IDLE.o" \
"./src/MAL/PCC_Config.o" \
"./src/MAL/PORT_Config.o" \
"./src/MAL/SCG_Config.o" \
"./src/MAL/WDOG_Config.o" \
"./src/MAL/time100ms.o" \
"./src/MAL/time400ms.o" \

C_DEPS += \
./src/MAL/GPIO_Config.d \
./src/MAL/LEDS_IDLE.d \
./src/MAL/PCC_Config.d \
./src/MAL/PORT_Config.d \
./src/MAL/SCG_Config.d \
./src/MAL/WDOG_Config.d \
./src/MAL/time100ms.d \
./src/MAL/time400ms.d \


# Each subdirectory must supply rules for building sources it contributes
src/MAL/GPIO_Config.o: ../src/MAL/GPIO_Config.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/MAL/GPIO_Config.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/MAL/GPIO_Config.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MAL/LEDS_IDLE.o: ../src/MAL/LEDS_IDLE.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/MAL/LEDS_IDLE.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/MAL/LEDS_IDLE.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MAL/PCC_Config.o: ../src/MAL/PCC_Config.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/MAL/PCC_Config.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/MAL/PCC_Config.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MAL/PORT_Config.o: ../src/MAL/PORT_Config.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/MAL/PORT_Config.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/MAL/PORT_Config.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MAL/SCG_Config.o: ../src/MAL/SCG_Config.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/MAL/SCG_Config.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/MAL/SCG_Config.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MAL/WDOG_Config.o: ../src/MAL/WDOG_Config.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/MAL/WDOG_Config.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/MAL/WDOG_Config.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MAL/time100ms.o: ../src/MAL/time100ms.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/MAL/time100ms.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/MAL/time100ms.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MAL/time400ms.o: ../src/MAL/time400ms.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/MAL/time400ms.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/MAL/time400ms.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


