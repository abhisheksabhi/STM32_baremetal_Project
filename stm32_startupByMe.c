#include <stdint.h>

#define SRAM_START 0x20000000U

#define SRAM_SIZE (128*1024) //128k
#define SRAM_END  ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END

int main(void);
void __libc_init_array();

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _loadaddrss_data;
extern uint32_t _estack;

void Reset_Handler   (void) __attribute__((noreturn));

/* Default_Handler must be defined before any alias that references it */
void Default_Handler(void)
{
	while(1);
}

/* Declare each IRQ handler as a noreturn weak alias of Default_Handler.
 * Putting noreturn on the alias itself satisfies GCC 14 -Wmissing-attributes. */
#define IRQ_HANDLER(name) \
    void name(void) __attribute__((noreturn, weak, alias("Default_Handler")))

IRQ_HANDLER(NMI_Handler);
IRQ_HANDLER(HardFault_Handler);
IRQ_HANDLER(MemManage_Handler);
IRQ_HANDLER(BusFault_Handler);
IRQ_HANDLER(UsageFault_Handler);
IRQ_HANDLER(SVC_Handler);
IRQ_HANDLER(DebugMon_Handler);
IRQ_HANDLER(PendSV_Handler);
IRQ_HANDLER(SysTick_Handler);
IRQ_HANDLER(WWDG_IRQHandler);
IRQ_HANDLER(PVD_IRQHandler);
IRQ_HANDLER(TAMP_STAMP_IRQHandler);
IRQ_HANDLER(RTC_WKUP_IRQHandler);
IRQ_HANDLER(RCC_IRQHandler);
IRQ_HANDLER(EXTI0_IRQHandler);
IRQ_HANDLER(EXTI1_IRQHandler);
IRQ_HANDLER(EXTI2_IRQHandler);
IRQ_HANDLER(EXTI3_IRQHandler);
IRQ_HANDLER(EXTI4_IRQHandler);
IRQ_HANDLER(DMA1_Stream0_IRQHandler);
IRQ_HANDLER(DMA1_Stream1_IRQHandler);
IRQ_HANDLER(DMA1_Stream2_IRQHandler);
IRQ_HANDLER(DMA1_Stream3_IRQHandler);
IRQ_HANDLER(DMA1_Stream4_IRQHandler);
IRQ_HANDLER(DMA1_Stream5_IRQHandler);
IRQ_HANDLER(DMA1_Stream6_IRQHandler);
IRQ_HANDLER(ADC_IRQHandler);
IRQ_HANDLER(CAN1_TX_IRQHandler);
IRQ_HANDLER(CAN1_RX0_IRQHandler);
IRQ_HANDLER(CAN1_RX1_IRQHandler);
IRQ_HANDLER(CAN1_SCE_IRQHandler);
IRQ_HANDLER(EXTI9_5_IRQHandler);
IRQ_HANDLER(TIM1_BRK_TIM9_IRQHandler);
IRQ_HANDLER(TIM1_UP_TIM10_IRQHandler);
IRQ_HANDLER(TIM1_TRG_COM_TIM11_IRQHandler);
IRQ_HANDLER(TIM1_CC_IRQHandler);
IRQ_HANDLER(TIM2_IRQHandler);
IRQ_HANDLER(TIM3_IRQHandler);
IRQ_HANDLER(TIM4_IRQHandler);
IRQ_HANDLER(I2C1_EV_IRQHandler);
IRQ_HANDLER(I2C1_ER_IRQHandler);
IRQ_HANDLER(I2C2_EV_IRQHandler);
IRQ_HANDLER(I2C2_ER_IRQHandler);
IRQ_HANDLER(SPI1_IRQHandler);
IRQ_HANDLER(SPI2_IRQHandler);
IRQ_HANDLER(USART1_IRQHandler);
IRQ_HANDLER(USART2_IRQHandler);
IRQ_HANDLER(USART3_IRQHandler);
IRQ_HANDLER(EXTI15_10_IRQHandler);
IRQ_HANDLER(RTC_Alarm_IRQHandler);
IRQ_HANDLER(OTG_FS_WKUP_IRQHandler);
IRQ_HANDLER(TIM8_BRK_TIM12_IRQHandler);
IRQ_HANDLER(TIM8_UP_TIM13_IRQHandler);
IRQ_HANDLER(TIM8_TRG_COM_TIM14_IRQHandler);
IRQ_HANDLER(TIM8_CC_IRQHandler);
IRQ_HANDLER(DMA1_Stream7_IRQHandler);
IRQ_HANDLER(FSMC_IRQHandler);
IRQ_HANDLER(SDIO_IRQHandler);
IRQ_HANDLER(TIM5_IRQHandler);
IRQ_HANDLER(SPI3_IRQHandler);
IRQ_HANDLER(UART4_IRQHandler);
IRQ_HANDLER(UART5_IRQHandler);
IRQ_HANDLER(TIM6_DAC_IRQHandler);
IRQ_HANDLER(TIM7_IRQHandler);
IRQ_HANDLER(DMA2_Stream0_IRQHandler);
IRQ_HANDLER(DMA2_Stream1_IRQHandler);
IRQ_HANDLER(DMA2_Stream2_IRQHandler);
IRQ_HANDLER(DMA2_Stream3_IRQHandler);
IRQ_HANDLER(DMA2_Stream4_IRQHandler);
IRQ_HANDLER(ETH_IRQHandler);
IRQ_HANDLER(ETH_WKUP_IRQHandler);
IRQ_HANDLER(CAN2_TX_IRQHandler);
IRQ_HANDLER(CAN2_RX0_IRQHandler);
IRQ_HANDLER(CAN2_RX1_IRQHandler);
IRQ_HANDLER(CAN2_SCE_IRQHandler);
IRQ_HANDLER(OTG_FS_IRQHandler);
IRQ_HANDLER(DMA2_Stream5_IRQHandler);
IRQ_HANDLER(DMA2_Stream6_IRQHandler);
IRQ_HANDLER(DMA2_Stream7_IRQHandler);
IRQ_HANDLER(USART6_IRQHandler);
IRQ_HANDLER(I2C3_EV_IRQHandler);
IRQ_HANDLER(I2C3_ER_IRQHandler);
IRQ_HANDLER(OTG_HS_EP1_OUT_IRQHandler);
IRQ_HANDLER(OTG_HS_EP1_IN_IRQHandler);
IRQ_HANDLER(OTG_HS_WKUP_IRQHandler);
IRQ_HANDLER(OTG_HS_IRQHandler);
IRQ_HANDLER(DCMI_IRQHandler);
IRQ_HANDLER(CRYP_IRQHandler);
IRQ_HANDLER(HASH_RNG_IRQHandler);
IRQ_HANDLER(FPU_IRQHandler);

/* On Cortex-M (32-bit), function pointers and data pointers are the same size.
 * Cast: fn-ptr -> uintptr_t (pointer-sized uint) -> uint32_t.
 * The double cast is the portable idiom that suppresses strict-alias/size warnings. */
#define HANDLER(fn)  ((uint32_t)(uintptr_t)(void(*)(void))(fn))

__attribute__((used, section (".isr_vector"))) const uint32_t vectors[] = {
	STACK_START,                              /* Initial stack pointer        */
	HANDLER(Reset_Handler),
	HANDLER(NMI_Handler),
	HANDLER(HardFault_Handler),
	HANDLER(MemManage_Handler),
	HANDLER(BusFault_Handler),
	HANDLER(UsageFault_Handler),
	0,                                        /* Reserved                     */
	0,                                        /* Reserved                     */
	0,                                        /* Reserved                     */
	0,                                        /* Reserved                     */
	HANDLER(SVC_Handler),
	HANDLER(DebugMon_Handler),
	0,                                        /* Reserved                     */
	HANDLER(PendSV_Handler),
	HANDLER(SysTick_Handler),
	/* External interrupts */
	HANDLER(WWDG_IRQHandler),
	HANDLER(PVD_IRQHandler),
	HANDLER(TAMP_STAMP_IRQHandler),
	HANDLER(RTC_WKUP_IRQHandler),
	0,                                        /* Reserved                     */
	HANDLER(RCC_IRQHandler),
	HANDLER(EXTI0_IRQHandler),
	HANDLER(EXTI1_IRQHandler),
	HANDLER(EXTI2_IRQHandler),
	HANDLER(EXTI3_IRQHandler),
	HANDLER(EXTI4_IRQHandler),
	HANDLER(DMA1_Stream0_IRQHandler),
	HANDLER(DMA1_Stream1_IRQHandler),
	HANDLER(DMA1_Stream2_IRQHandler),
	HANDLER(DMA1_Stream3_IRQHandler),
	HANDLER(DMA1_Stream4_IRQHandler),
	HANDLER(DMA1_Stream5_IRQHandler),
	HANDLER(DMA1_Stream6_IRQHandler),
	HANDLER(ADC_IRQHandler),
	HANDLER(CAN1_TX_IRQHandler),
	HANDLER(CAN1_RX0_IRQHandler),
	HANDLER(CAN1_RX1_IRQHandler),
	HANDLER(CAN1_SCE_IRQHandler),
	HANDLER(EXTI9_5_IRQHandler),
	HANDLER(TIM1_BRK_TIM9_IRQHandler),
	HANDLER(TIM1_UP_TIM10_IRQHandler),
	HANDLER(TIM1_TRG_COM_TIM11_IRQHandler),
	HANDLER(TIM1_CC_IRQHandler),
	HANDLER(TIM2_IRQHandler),
	HANDLER(TIM3_IRQHandler),
	HANDLER(TIM4_IRQHandler),
	HANDLER(I2C1_EV_IRQHandler),
	HANDLER(I2C1_ER_IRQHandler),
	HANDLER(I2C2_EV_IRQHandler),
	HANDLER(I2C2_ER_IRQHandler),
	HANDLER(SPI1_IRQHandler),
	HANDLER(SPI2_IRQHandler),
	HANDLER(USART1_IRQHandler),
	HANDLER(USART2_IRQHandler),
	HANDLER(USART3_IRQHandler),
	HANDLER(EXTI15_10_IRQHandler),
	HANDLER(RTC_Alarm_IRQHandler),
	HANDLER(OTG_FS_WKUP_IRQHandler),
	HANDLER(TIM8_BRK_TIM12_IRQHandler),
	HANDLER(TIM8_UP_TIM13_IRQHandler),
	HANDLER(TIM8_TRG_COM_TIM14_IRQHandler),
	HANDLER(TIM8_CC_IRQHandler),
	HANDLER(DMA1_Stream7_IRQHandler),
	HANDLER(FSMC_IRQHandler),
	HANDLER(SDIO_IRQHandler),
	HANDLER(TIM5_IRQHandler),
	HANDLER(SPI3_IRQHandler),
	HANDLER(UART4_IRQHandler),
	HANDLER(UART5_IRQHandler),
	HANDLER(TIM6_DAC_IRQHandler),
	HANDLER(TIM7_IRQHandler),
	HANDLER(DMA2_Stream0_IRQHandler),
	HANDLER(DMA2_Stream1_IRQHandler),
	HANDLER(DMA2_Stream2_IRQHandler),
	HANDLER(DMA2_Stream3_IRQHandler),
	HANDLER(DMA2_Stream4_IRQHandler),
	HANDLER(ETH_IRQHandler),
	HANDLER(ETH_WKUP_IRQHandler),
	HANDLER(CAN2_TX_IRQHandler),
	HANDLER(CAN2_RX0_IRQHandler),
	HANDLER(CAN2_RX1_IRQHandler),
	HANDLER(CAN2_SCE_IRQHandler),
	HANDLER(OTG_FS_IRQHandler),
	HANDLER(DMA2_Stream5_IRQHandler),
	HANDLER(DMA2_Stream6_IRQHandler),
	HANDLER(DMA2_Stream7_IRQHandler),
	HANDLER(USART6_IRQHandler),
	HANDLER(I2C3_EV_IRQHandler),
	HANDLER(I2C3_ER_IRQHandler),
	HANDLER(OTG_HS_EP1_OUT_IRQHandler),
	HANDLER(OTG_HS_EP1_IN_IRQHandler),
	HANDLER(OTG_HS_WKUP_IRQHandler),
	HANDLER(OTG_HS_IRQHandler),
	HANDLER(DCMI_IRQHandler),
	HANDLER(CRYP_IRQHandler),
	HANDLER(HASH_RNG_IRQHandler),
	HANDLER(FPU_IRQHandler),
};

void Reset_Handler(void)
{
	// Enable FPU: set CP10 and CP11 to full access in CPACR
	// Must be done before any FP instructions or main()
	*((volatile uint32_t*)0xE000ED88U) |= (0xFUL << 20);

	// Copy .data section from FLASH to SRAM (word copy)
	uint32_t *pDst = (uint32_t *)&_sdata;
	uint32_t *pSrc = (uint32_t *)&_loadaddrss_data;
	uint32_t data_words = (&_edata - &_sdata); // number of 32-bit words
	for (uint32_t i = 0; i < data_words; ++i)
		pDst[i] = pSrc[i];

	// Zero initialize .bss (word clear)
	uint32_t *pBss = (uint32_t *)&_sbss;
	uint32_t bss_words = (&_ebss - &_sbss);
	for (uint32_t i = 0; i < bss_words; ++i)
		pBss[i] = 0;

	// Initialize libc (constructors)
	__libc_init_array();

	// Call main()
	main();

	// If main returns, loop forever
	while (1)
	{
		;
	}
}

