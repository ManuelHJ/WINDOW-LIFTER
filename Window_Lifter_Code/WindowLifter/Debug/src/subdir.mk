################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/Mode_Routine.c" \
"../src/initproyect.c" \
"../src/main.c" \

C_SRCS += \
../src/Mode_Routine.c \
../src/initproyect.c \
../src/main.c \

OBJS_OS_FORMAT += \
./src/Mode_Routine.o \
./src/initproyect.o \
./src/main.o \

C_DEPS_QUOTED += \
"./src/Mode_Routine.d" \
"./src/initproyect.d" \
"./src/main.d" \

OBJS += \
./src/Mode_Routine.o \
./src/initproyect.o \
./src/main.o \

OBJS_QUOTED += \
"./src/Mode_Routine.o" \
"./src/initproyect.o" \
"./src/main.o" \

C_DEPS += \
./src/Mode_Routine.d \
./src/initproyect.d \
./src/main.d \


# Each subdirectory must supply rules for building sources it contributes
src/Mode_Routine.o: ../src/Mode_Routine.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/Mode_Routine.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/Mode_Routine.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/initproyect.o: ../src/initproyect.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/initproyect.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/initproyect.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/main.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


