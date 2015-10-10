

//*****************************************************************************
//
// Forward declaration of the default fault handlers.
//
//*****************************************************************************
/* System exception vector handler */
void __attribute__ ((weak)) Reset_Handler(void);
void __attribute__ ((weak)) NMI_Handler(void);
void __attribute__ ((weak)) HardFault_Handler(void);
void __attribute__ ((weak)) MemManage_Handler(void);
void __attribute__ ((weak)) BusFault_Handler(void);
void __attribute__ ((weak)) UsageFault_Handler(void);
void __attribute__ ((weak)) SVC_Handler(void);
void __attribute__ ((weak)) DebugMon_Handler(void);
void __attribute__ ((weak)) PendSV_Handler(void);
void __attribute__ ((weak)) SysTick_Handler(void);

/* External interrupt vector handler */
void __attribute__ ((weak)) WWDG_IRQHandler(void);
void __attribute__ ((weak)) PVD_IRQHandler(void);
void __attribute__ ((weak)) TAMPER_STAMP_IRQHandler(void);
void __attribute__ ((weak)) RTC_WKUP_IRQHandler(void);
void __attribute__ ((weak)) FLASH_IRQHandler(void);
void __attribute__ ((weak)) RCC_IRQHandler(void);
void __attribute__ ((weak)) EXTI0_IRQHandler(void);
void __attribute__ ((weak)) EXTI1_IRQHandler(void);
void __attribute__ ((weak)) EXTI2_IRQHandler(void);
void __attribute__ ((weak)) EXTI3_IRQHandler(void);
void __attribute__ ((weak)) EXTI4_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Channel1_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Channel2_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Channel3_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Channel4_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Channel5_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Channel6_IRQHandler(void);
void __attribute__ ((weak)) DMA1_Channel7_IRQHandler(void);
void __attribute__ ((weak)) ADC1_IRQHandler(void);
void __attribute__ ((weak)) USB_HP_IRQHandler(void);
void __attribute__ ((weak)) USB_LP_IRQHandler(void);
void __attribute__ ((weak)) DAC_IRQHandler(void);
void __attribute__ ((weak)) COMP_IRQHandler(void);
void __attribute__ ((weak)) EXTI9_5_IRQHandler(void);
void __attribute__ ((weak)) LCD_IRQHandler(void);
void __attribute__ ((weak)) TIM9_IRQHandler(void);
void __attribute__ ((weak)) TIM10_IRQHandler(void);
void __attribute__ ((weak)) TIM11_IRQHandler(void);
void __attribute__ ((weak)) TIM2_IRQHandler(void);
void __attribute__ ((weak)) TIM3_IRQHandler(void);
void __attribute__ ((weak)) TIM4_IRQHandler(void);
void __attribute__ ((weak)) I2C1_EV_IRQHandler(void);
void __attribute__ ((weak)) I2C1_ER_IRQHandler(void);
void __attribute__ ((weak)) I2C2_EV_IRQHandler(void);
void __attribute__ ((weak)) I2C2_ER_IRQHandler(void);
void __attribute__ ((weak)) SPI1_IRQHandler(void);
void __attribute__ ((weak)) SPI2_IRQHandler(void);
void __attribute__ ((weak)) USART1_IRQHandler(void);
void __attribute__ ((weak)) USART2_IRQHandler(void);
void __attribute__ ((weak)) USART3_IRQHandler(void);
void __attribute__ ((weak)) EXTI15_10_IRQHandler(void);
void __attribute__ ((weak)) RTC_Alarm_IRQHandler(void);
void __attribute__ ((weak)) USB_FS_WKUP_IRQHandler(void);
void __attribute__ ((weak)) TIM6_IRQHandler(void);
void __attribute__ ((weak)) TIM7_IRQHandler(void);

/* Exported types --------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
extern unsigned long __etext;
extern unsigned long _sidata;			/* start address for the initialization values of the .data section. defined in linker script */
extern unsigned long _sdata;	/* start address for the .data section. defined in linker script */
extern unsigned long _edata;		/* end address for the .data section. defined in linker script */

extern unsigned long __bss_start__;		/* start address for the .bss section. defined in linker script */
extern unsigned long __bss_end__;		/* end address for the .bss section. defined in linker script */

extern unsigned long *_estack;				/* init value for the stack pointer. defined in linker script */

extern void SystemInit(void);

/* Private typedef -----------------------------------------------------------*/
/* function prototypes ------------------------------------------------------*/
void Reset_Handler(void) __attribute__((__interrupt__));
extern int main(void);
extern void _CPUregTestPOST (void);

__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{	
	(void *)&_estack,
	Reset_Handler,
	NMI_Handler,
	HardFault_Handler,
	MemManage_Handler,
	BusFault_Handler,
	UsageFault_Handler,
	0,
	0,
	0,
	0,
	SVC_Handler,
	DebugMon_Handler,
	0,
	PendSV_Handler,
	SysTick_Handler,
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMPER_STAMP_IRQHandler,
	RTC_WKUP_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	ADC1_IRQHandler,
	USB_HP_IRQHandler,
	USB_LP_IRQHandler,
	DAC_IRQHandler,
	COMP_IRQHandler,
	EXTI9_5_IRQHandler,
	LCD_IRQHandler,
	TIM9_IRQHandler,
	TIM10_IRQHandler,
	TIM11_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTC_Alarm_IRQHandler,
	USB_FS_WKUP_IRQHandler,
	TIM6_IRQHandler,
	TIM7_IRQHandler,
};

/*******************************************************************************
* Function Name	: Reset_Handler
* Description	: This is the code that gets called when the processor first starts execution
*				following a reset event.	Only the absolutely necessary set is performed,
*				after which the application supplied main() routine is called.
* Input			:
* Output		:
* Return		:
*******************************************************************************/
void Reset_Handler(void) {
	unsigned long *pulSrc, *pulDest;

	/*
	* This used for cleaning AHBRAM0 section
	*/
#if 0
	for (pulDest = ((unsigned long *)AHBRAM0_BASE); \
					pulDest < ((unsigned long *)(AHBRAM0_BASE + AHBRAM0_SIZE)); \
					pulDest++){
		*(pulDest++) = 0;
	}
#endif

	/*
	* This used for cleaning AHBRAM1 section
	*/
#if 0
	for (pulDest = ((unsigned long *)AHBRAM1_BASE); \
					pulDest < ((unsigned long *)(AHBRAM1_BASE + AHBRAM1_SIZE)); \
					pulDest++){
		*(pulDest++) = 0;
	}
#endif

	//
	// Copy the data segment initializers from flash to SRAM in ROM mode
	//
#if (__RAM_MODE__==0)
	pulSrc = &_sidata;
	for(pulDest = &_sdata; pulDest < &_edata; )
	{
		*(pulDest++) = *(pulSrc++);
	}
#endif


	//
	// Zero fill the bss segment.
	//
	for(pulDest = &__bss_start__; pulDest < &__bss_end__; )
	{
		*(pulDest++) = 0;
	}

	//
	//	Call IEC60335 CPU register tests POST
	//
//	__ASM volatile ("bl _CPUregTestPOST \t\n");

	SystemInit();

	//
	// Call the application's entry point.
	//
	main();
}

//*****************************************************************************
//
// Provide weak aliases for each Exception handler to the Default_Handler.
// As they are weak aliases, any function with the same name will override
// this definition.
//
//*****************************************************************************

#pragma weak MemManage_Handler = Default_Handler
#pragma weak BusFault_Handler = Default_Handler
#pragma weak UsageFault_Handler = Default_Handler
#pragma weak SVC_Handler = Default_Handler
#pragma weak DebugMon_Handler = Default_Handler
#pragma weak PendSV_Handler = Default_Handler
#pragma weak SysTick_Handler = Default_Handler
#pragma weak WWDG_IRQHandler = Default_Handler
#pragma weak PVD_IRQHandler = Default_Handler
#pragma weak TAMPER_STAMP_IRQHandler = Default_Handler
#pragma weak RTC_WKUP_IRQHandler = Default_Handler
#pragma weak FLASH_IRQHandler = Default_Handler
#pragma weak RCC_IRQHandler = Default_Handler
#pragma weak EXTI0_IRQHandler = Default_Handler
#pragma weak EXTI1_IRQHandler = Default_Handler
#pragma weak EXTI2_IRQHandler = Default_Handler
#pragma weak EXTI3_IRQHandler = Default_Handler
#pragma weak EXTI4_IRQHandler = Default_Handler
#pragma weak DMA1_Channel1_IRQHandler = Default_Handler
#pragma weak DMA1_Channel2_IRQHandler = Default_Handler
#pragma weak DMA1_Channel3_IRQHandler = Default_Handler
#pragma weak DMA1_Channel4_IRQHandler = Default_Handler
#pragma weak DMA1_Channel5_IRQHandler = Default_Handler
#pragma weak DMA1_Channel6_IRQHandler = Default_Handler
#pragma weak DMA1_Channel7_IRQHandler = Default_Handler
#pragma weak ADC1_IRQHandler = Default_Handler
#pragma weak USB_HP_IRQHandler = Default_Handler
#pragma weak USB_LP_IRQHandler = Default_Handler
#pragma weak DAC_IRQHandler = Default_Handler
#pragma weak COMP_IRQHandler = Default_Handler
#pragma weak EXTI9_5_IRQHandler = Default_Handler
#pragma weak LCD_IRQHandler = Default_Handler
#pragma weak TIM9_IRQHandler = Default_Handler
#pragma weak TIM10_IRQHandler = Default_Handler
#pragma weak TIM11_IRQHandler = Default_Handler
#pragma weak TIM2_IRQHandler = Default_Handler
#pragma weak TIM3_IRQHandler = Default_Handler
#pragma weak TIM4_IRQHandler = Default_Handler
#pragma weak I2C1_EV_IRQHandler = Default_Handler
#pragma weak I2C1_ER_IRQHandler = Default_Handler
#pragma weak I2C2_EV_IRQHandler = Default_Handler
#pragma weak I2C2_ER_IRQHandler = Default_Handler
#pragma weak SPI1_IRQHandler = Default_Handler
#pragma weak SPI2_IRQHandler = Default_Handler
#pragma weak USART1_IRQHandler = Default_Handler
#pragma weak USART2_IRQHandler = Default_Handler
#pragma weak USART3_IRQHandler = Default_Handler
#pragma weak EXTI15_10_IRQHandler = Default_Handler
#pragma weak RTC_Alarm_IRQHandler = Default_Handler
#pragma weak USB_FS_WKUP_IRQHandler = Default_Handler
#pragma weak TIM6_IRQHandler = Default_Handler
#pragma weak TIM7_IRQHandler = Default_Handler

//*****************************************************************************
//
// This is the code that gets called when the processor receives an unexpected
// interrupt.	This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
void Default_Handler(void) {
	while (1) {}
}
