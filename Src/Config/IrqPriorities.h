/*
 * IrqPriorities.h
 *
 *  Created on: 25.04.2020
 *      Author: Lukas
 */

#ifndef SRC_CONFIG_IRQPRIORITIES_H_
#define SRC_CONFIG_IRQPRIORITIES_H_

#include "types.h"

typedef struct
{
	U32	u32PrePrio;
	U32 u32SubPrio;
}IrqPrio_t;

const IrqPrio_t IRQ_PRIORITY_CONFIG[85] =
{
		 {0,0},      /*!<0 Window WatchDog Interrupt                                         */
		 {0,0},      /*!<1 PVD through EXTI Line detection Interrupt                         */
		 {0,0},      /*!<2 Tamper and TimeStamp interrupts through the EXTI line             */
		 {0,0},      /*!<3 RTC Wakeup interrupt through the EXTI line                        */
		 {0,0},      /*!<4 FLASH global Interrupt                                            */
		 {0,0},      /*!<5 RCC global Interrupt                                              */
		 {0,0},      /*!<6 EXTI Line0 Interrupt                                              */
		 {0,0},      /*!<7 EXTI Line1 Interrupt                                              */
		 {0,0},      /*!<8 EXTI Line2 Interrupt                                              */
		 {0,0},      /*!<9 EXTI Line3 Interrupt                                              */
		 {0,0},     /*!<10 EXTI Line4 Interrupt                                              */
		 {0,0},     /*!<11 DMA1 Stream 0 global Interrupt                                    */
		 {0,0},     /*!<12 DMA1 Stream 1 global Interrupt                                    */
		 {0,0},     /*!<13 DMA1 Stream 2 global Interrupt                                    */
		 {0,0},     /*!<14 DMA1 Stream 3 global Interrupt                                    */
		 {0,0},     /*!<15 DMA1 Stream 4 global Interrupt                                    */
		 {0,0},     /*!<16 DMA1 Stream 5 global Interrupt                                    */
		 {0,0},     /*!<17 DMA1 Stream 6 global Interrupt                                    */
		 {0,0},     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
		 {0,0},     /*!< External Line[9:5] Interrupts                                     */
		 {0,0},     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
		 {0,0},     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
		 {0,0},     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
		 {0,0},     /*!< TIM1 Capture Compare Interrupt                                    */
		 {0,0},     /*!< TIM2 global Interrupt                                             */
		 {0,0},     /*!< TIM3 global Interrupt                                             */
		 {0,0},     /*!< TIM4 global Interrupt                                             */
		 {0,0},     /*!< I2C1 Event Interrupt                                              */
		 {0,0},     /*!< I2C1 Error Interrupt                                              */
		 {0,0},     /*!< I2C2 Event Interrupt                                              */
		 {0,0},     /*!< I2C2 Error Interrupt                                              */
		 {0,0},     /*!< SPI1 global Interrupt                                             */
		 {0,0},     /*!< SPI2 global Interrupt                                             */
		 {0,0},     /*!< USART1 global Interrupt                                           */
		 {0,0},     /*!< USART2 global Interrupt                                           */
		 {0,0},     /*!< External Line[15:10] Interrupts                                   */
		 {0,0},     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
		 {0,0},     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
		 {0,0},     /*!< DMA1 Stream7 Interrupt                                            */
		 {0,0},     /*!< SDIO global Interrupt                                             */
		 {0,0},     /*!< TIM5 global Interrupt                                             */
		 {0,0},     /*!< SPI3 global Interrupt                                             */
		 {0,0},     /*!< DMA2 Stream 0 global Interrupt                                    */
		 {0,0},     /*!< DMA2 Stream 1 global Interrupt                                    */
		 {0,0},     /*!< DMA2 Stream 2 global Interrupt                                    */
		 {0,0},     /*!< DMA2 Stream 3 global Interrupt                                    */
		 {0,0},     /*!< DMA2 Stream 4 global Interrupt                                    */
		 {0,0},     /*!< USB OTG FS global Interrupt                                       */
		 {0,0},     /*!< DMA2 Stream 5 global interrupt                                    */
		 {0,0},     /*!< DMA2 Stream 6 global interrupt                                    */
		 {0,0},     /*!< DMA2 Stream 7 global interrupt                                    */
		 {0,0},     /*!< USART6 global interrupt                                           */
		 {0,0},     /*!< I2C3 event interrupt                                              */
		 {0,0},     /*!< I2C3 error interrupt                                              */
		 {0,0},     /*!< FPU global interrupt                                              */
		 {0,0}      /*!< SPI4 global Interrupt*/
};


#endif /* SRC_CONFIG_IRQPRIORITIES_H_ */
