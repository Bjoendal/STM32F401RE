/*
 * CUart.cpp
 *
 *  Created on: 23.04.2020
 *      Author: Lukas
 */

#include "CUart.h"
#include "stm32f4xx.h"

static void UART_EndTxTransfer(UART_HandleTypeDef *huart);
static void UART_EndRxTransfer(UART_HandleTypeDef *huart);
static void UART_DMATransmitCplt(DMA_HandleTypeDef *hdma);
//static void UART_DMAReceiveCplt(DMA_HandleTypeDef *hdma);
static void UART_DMATxHalfCplt(DMA_HandleTypeDef *hdma);
//static void UART_DMARxHalfCplt(DMA_HandleTypeDef *hdma);
static void UART_DMAError(DMA_HandleTypeDef *hdma);
//static void UART_DMAAbortOnError(DMA_HandleTypeDef *hdma);
//static void UART_DMATxAbortCallback(DMA_HandleTypeDef *hdma);
//static void UART_DMARxAbortCallback(DMA_HandleTypeDef *hdma);
//static void UART_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma);
//static void UART_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma);
//static HAL_StatusTypeDef UART_Transmit_IT(UART_HandleTypeDef *huart);
//static HAL_StatusTypeDef UART_EndTransmit_IT(UART_HandleTypeDef *huart);
//static HAL_StatusTypeDef UART_Receive_IT(UART_HandleTypeDef *huart);
//static HAL_StatusTypeDef UART_WaitOnFlagUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status, uint32_t Tickstart, uint32_t Timeout);
//static void UART_SetConfig (UART_HandleTypeDef *huart);

static CUart* pThis = NULL;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	huart->RxXferCount++;
	huart->pRxBuffPtr--;

	if(USART1 == huart->Instance)
	{
		CUart::RxIrq(UART_CHANNEL_1);
	}
	else if(USART2 == huart->Instance)
	{
		CUart::RxIrq(UART_CHANNEL_2);
	}
	else if(USART6 == huart->Instance)
	{
		CUart::RxIrq(UART_CHANNEL_6);
	}

	/* Disable the UART Parity Error Interrupt and RXNE interrupt*/
	SET_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));

	/* Disable the UART Error Interrupt: (Frame error, noise error, overrun error) */
	SET_BIT(huart->Instance->CR3, USART_CR3_EIE);

	huart->RxState = HAL_UART_STATE_BUSY_RX;
}

CUart::CUart()
{
	pThis = this;
}

BOOL CUart::Init(const UartConfig_t& config)
{
	channelOpen[UART_CHANNEL_1] = FALSE;
	channelOpen[UART_CHANNEL_2] = FALSE;
	channelOpen[UART_CHANNEL_6] = FALSE;

	return TRUE;
}

UartOpenStatus_t CUart::Open(const UartChannel_t& channel)
{
	UartOpenStatus_t uosReturn = UART_OST_FAILED;

	if(channel.channel <= UART_CHANNEL_6 )
	{
	if( (FALSE == channelOpen[channel.channel]) && (HAL_UART_STATE_READY == channel.uartHandle->gState) )
	{
		channelOpen[channel.channel] = TRUE;

//		__HAL_LOCK(channel.uartHandle);
		if (channel.uartHandle->Lock == HAL_LOCKED)
		{
			return UART_OST_FAILED;
		}
		else
		{
			channel.uartHandle->Lock = HAL_LOCKED;
		}

		channelRingbufferRx[channel.channel].SetItsBufferArray(channel.u8RxBuffer, channel.u16RxBufferLen);

		channelRingbufferTx[channel.channel].SetItsBufferArray(channel.u8TxBuffer, channel.u16TxBufferLen);

		this->channel[channel.channel] = const_cast<UartChannel_t*>(&channel);

		 /* Set the UART DMA transfer complete callback */
		channel.uartHandle->hdmatx->XferCpltCallback = UART_DMATransmitCplt;

		 /* Set the UART DMA Half transfer complete callback */
		channel.uartHandle->hdmatx->XferHalfCpltCallback = UART_DMATxHalfCplt;

		 /* Set the DMA error callback */
		channel.uartHandle->hdmatx->XferErrorCallback = UART_DMAError;

		 /* Set the DMA abort callback */
		channel.uartHandle->hdmatx->XferAbortCallback = NULL;

		channel.uartHandle->pRxBuffPtr = const_cast<U8*>(channel.u8Buffer);
		channel.uartHandle->RxXferSize = 1;
		channel.uartHandle->RxXferCount = 1;

		channel.uartHandle->ErrorCode = HAL_UART_ERROR_NONE;
		channel.uartHandle->RxState = HAL_UART_STATE_BUSY_RX;

		__HAL_UNLOCK(channel.uartHandle);

	    /* Enable the UART Error Interrupt: (Frame error, noise error, overrun error) */
	    SET_BIT(channel.uartHandle->Instance->CR3, USART_CR3_EIE);

	    /* Enable the UART Parity Error and Data Register not empty Interrupts */
	    SET_BIT(channel.uartHandle->Instance->CR1, USART_CR1_PEIE | USART_CR1_RXNEIE);

		 uosReturn = UART_OST_SUCCESS;
	}
	}
	return uosReturn;
}

void CUart::Close(const UartChannel_t& channel)
{
	if (channel.channel <= UART_CHANNEL_6)
	{
		channelOpen[channel.channel] = FALSE;

		/* Disable the UART Parity Error Interrupt and RXNE interrupt*/
		CLEAR_BIT(channel.uartHandle->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));

		/* Disable the UART Error Interrupt: (Frame error, noise error, overrun error) */
		CLEAR_BIT(channel.uartHandle->Instance->CR3, USART_CR3_EIE);

		/* Rx process is completed, restore huart->RxState to Ready */
		channel.uartHandle->RxState = HAL_UART_STATE_READY;

	}
}

U16 CUart::Read(const UartChannel_t& channel, U8* const data, const U16 numBytes)
{
	if(channel.channel > UART_CHANNEL_6)
	{
		return 0U;
	}

	if(!channelOpen[channel.channel])
	{
		return 0U;
	}

	return static_cast<U16>(channelRingbufferRx[channel.channel].Get(data, numBytes));
}

U16 CUart::Write(const UartChannel_t& channel, const U8* const data, const U16 numBytes)
{
	if(channel.channel > UART_CHANNEL_6)
	{
		return 0U;
	}

	if(!channelOpen[channel.channel])
	{
		return 0U;
	}

	channelRingbufferTx[channel.channel].Clear();

	U16 u16Sent = channelRingbufferTx[channel.channel].Add(data, numBytes);

	//		__HAL_LOCK(channel.uartHandle);
	if ((channel.uartHandle->Lock == HAL_LOCKED) || (HAL_UART_STATE_READY != channel.uartHandle->gState) )
	{
		return 0U;
	}
	else
	{
		channel.uartHandle->Lock = HAL_LOCKED;
	}

	channel.uartHandle->pTxBuffPtr = channel.u8TxBuffer;
	channel.uartHandle->TxXferSize = u16Sent;
	channel.uartHandle->TxXferCount = u16Sent;

	channel.uartHandle->gState = HAL_UART_STATE_BUSY_TX;

	/* Disable the UART Parity Error Interrupt and RXNE interrupt*/
	CLEAR_BIT(channel.uartHandle->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));

	/* Disable the UART Error Interrupt: (Frame error, noise error, overrun error) */
	CLEAR_BIT(channel.uartHandle->Instance->CR3, USART_CR3_EIE);


	/* Enable the UART transmit DMA Stream */
	 U32* tmp = (uint32_t*)&channel.u8TxBuffer;
	 HAL_DMA_Start_IT(channel.uartHandle->hdmatx, *(uint32_t*)tmp, (uint32_t)&channel.uartHandle->Instance->DR, static_cast<U32>(u16Sent));

	 /* Clear the TC flag in the SR register by writing 0 to it */
	 __HAL_UART_CLEAR_FLAG(channel.uartHandle, UART_FLAG_TC);

	__HAL_UNLOCK(channel.uartHandle);

    /* Enable the DMA transfer for transmit request by setting the DMAT bit
       in the UART CR3 register */
    SET_BIT(channel.uartHandle->Instance->CR3, USART_CR3_DMAT);

	/* Disable the UART Parity Error Interrupt and RXNE interrupt*/
	SET_BIT(channel.uartHandle->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));

	/* Disable the UART Error Interrupt: (Frame error, noise error, overrun error) */
	SET_BIT(channel.uartHandle->Instance->CR3, USART_CR3_EIE);

	return u16Sent;
}

void CUart::SetCallbackInterface(const UartCallbackId_t& id, const IUartCallback& interruptCallbackInterface)
{
	itsIUartCallback[id] = const_cast<IUartCallback*>(&interruptCallbackInterface);
}

void CUart::EnableCallback(const UartCallbackId_t& id)
{
}

void CUart::DisableCallback(const UartCallbackId_t& id)
{
}

U16 CUart::GetAmountOfReceivedItems(const UartChannel_t& channel) const
{
	if(channel.channel > UART_CHANNEL_6)
	{
		return 0U;
	}

	return static_cast<U16>(channelRingbufferRx[channel.channel].GetLen());
}

void CUart::RxIrq(const UartChannel uartChannel)
{
	pThis->channelRingbufferRx[uartChannel].Add( *(pThis->channel[uartChannel]->uartHandle->pRxBuffPtr) );

	if(NULL != pThis->itsIUartCallback[uartChannel + 3])
	{
		pThis->itsIUartCallback[uartChannel + 3]->Do();
	}
}

static void UART_DMATxHalfCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef* huart = (UART_HandleTypeDef*)((DMA_HandleTypeDef*)hdma)->Parent;

  HAL_UART_TxHalfCpltCallback(huart);
}

static void UART_DMATransmitCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef* huart = ( UART_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
  /* DMA Normal mode*/
  if((hdma->Instance->CR & DMA_SxCR_CIRC) == 0U)
  {
    huart->TxXferCount = 0U;

    /* Disable the DMA transfer for transmit request by setting the DMAT bit
       in the UART CR3 register */
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);

    /* Enable the UART Transmit Complete Interrupt */
    SET_BIT(huart->Instance->CR1, USART_CR1_TCIE);

  }
  /* DMA Circular mode */
  else
  {
    HAL_UART_TxCpltCallback(huart);
  }
}

static void UART_DMAError(DMA_HandleTypeDef *hdma)
{
  uint32_t dmarequest = 0x00U;
  UART_HandleTypeDef* huart = ( UART_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;

  /* Stop UART DMA Tx request if ongoing */
  dmarequest = HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT);
  if((huart->gState == HAL_UART_STATE_BUSY_TX) && dmarequest)
  {
    huart->TxXferCount = 0U;
    UART_EndTxTransfer(huart);
  }

  /* Stop UART DMA Rx request if ongoing */
  dmarequest = HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR);
  if((huart->RxState == HAL_UART_STATE_BUSY_RX) && dmarequest)
  {
    huart->RxXferCount = 0U;
    UART_EndRxTransfer(huart);
  }

  huart->ErrorCode |= HAL_UART_ERROR_DMA;
  HAL_UART_ErrorCallback(huart);
}

static void UART_EndRxTransfer(UART_HandleTypeDef *huart)
{
  /* Disable RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts */
  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));
  CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

  /* At end of Rx process, restore huart->RxState to Ready */
  huart->RxState = HAL_UART_STATE_READY;
}

static void UART_EndTxTransfer(UART_HandleTypeDef *huart)
{
  /* Disable TXEIE and TCIE interrupts */
  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TXEIE | USART_CR1_TCIE));

  /* At end of Tx process, restore huart->gState to Ready */
  huart->gState = HAL_UART_STATE_READY;
}

BOOL CUart::DataAvailible(const UartChannel_t& channel) const
{
	if(channel.channel > UART_CHANNEL_6)
	{
		return FALSE;
	}
	return channelRingbufferRx[channel.channel].GetLen() != 0U;
}
