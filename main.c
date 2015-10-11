#include <stdio.h>
#include <stdint.h>

#include "stm32l1xx_conf.h"
#include "stm32l1xx.h"
#include "hw_config.h"

#define BLINK_DELAY_MS	(500)

volatile uint32_t tickMs = 0;

void init() {
	// ---------- SysTick timer -------- //
	if (SysTick_Config(SystemCoreClock / 1000)) {
		// Capture error
		while (1){};
	}

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	GPIO_Init(GPIOA, &(GPIO_InitTypeDef){GPIO_Pin_15, GPIO_Mode_OUT, GPIO_Speed_40MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL});

	Set_System();
	Set_USBClock();
	USB_Interrupts_Config();
	USB_Init();
}

int main(void) {
	uint32_t nextBlink;
	uint32_t blinkState = 0;
	init();

	nextBlink = tickMs + BLINK_DELAY_MS;
	for(;;) {

		if(tickMs > nextBlink) {
			nextBlink = tickMs + BLINK_DELAY_MS;
			if(blinkState) {
				GPIO_SetBits(GPIOA, GPIO_Pin_15);
			} else {
				GPIO_ResetBits(GPIOA, GPIO_Pin_15);
			}
			blinkState ^= 1;
		}

		__WFI();
	}

	return 0;
}

void SysTick_Handler(void)
{
	tickMs++;
}

/**
  * @brief  Configures COM port.
  * @param  COM: Specifies the COM port to be configured.
  *   This parameter can be one of following parameters:    
  *     @arg COM1
  * @param  USART_InitStruct: pointer to a USART_InitTypeDef structure that
  *   contains the configuration information for the specified USART peripheral.
  * @retval None
  */
void STM_EVAL_COMInit(USART_InitTypeDef* USART_InitStruct)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIO clock */
  RCC_AHBPeriphClockCmd(EVAL_COM1_TX_GPIO_CLK | EVAL_COM1_RX_GPIO_CLK, ENABLE);

  /* Enable USART1 clock */
  RCC_APB2PeriphClockCmd(EVAL_COM1_CLK, ENABLE); 

  /* Connect PXx to USARTx_Tx */
  GPIO_PinAFConfig(EVAL_COM1_TX_GPIO_PORT, EVAL_COM1_TX_SOURCE, EVAL_COM1_TX_AF);

  /* Connect PXx to USARTx_Rx */
  GPIO_PinAFConfig(EVAL_COM1_RX_GPIO_PORT, EVAL_COM1_RX_SOURCE, EVAL_COM1_RX_AF);
  
  /* Configure USART Tx as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = EVAL_COM1_TX_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_40MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(EVAL_COM1_TX_GPIO_PORT, &GPIO_InitStructure);
    
  /* Configure USART Rx as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = EVAL_COM1_RX_PIN;
  GPIO_Init(EVAL_COM1_RX_GPIO_PORT, &GPIO_InitStructure);

  /* USART configuration */
  USART_Init(EVAL_COM1, USART_InitStruct);
    
  /* Enable USART */
  USART_Cmd(EVAL_COM1, ENABLE);
}
