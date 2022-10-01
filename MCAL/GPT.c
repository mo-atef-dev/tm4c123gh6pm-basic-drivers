/*
 * File: GPT.c
 * Created Date: 2022-07-26
 * Author: Mohamed Atef
 * -----
 * Last Modified: Tue Jul 26 2022
 * Modified By: Mohamed Atef
 * -----
 * Copyright (c) 2022
 * -----
 * Description:
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 */


/************************************
 * INCLUDES
 ************************************/
#include "GPT.h"
#include "Bit_Op.h"

/************************************
 * LOCAL DATA
 ************************************/
 static void (*isr_timer0A)(void);
 static void (*isr_timer1A)(void);
 
 /************************************
 * Interrupt Service Routines
 ************************************/
void TIMER0A_Handler(void)
{
    isr_timer0A();
    /* Clear the timeout interrupt flag */
    ACCESS_GPTMICR(GPT_0_BASE) |= 0x01;
}

void TIMER1A_Handler(void)
{
    isr_timer1A();
    /* Clear the timeout interrupt flag */
    ACCESS_GPTMICR(GPT_1_BASE) |= 0x01;
}

/************************************
 * LOCAL FUNCTIONS
 ************************************/
 static uint32 GPT_GetTimerBaseAdr(GPT_ChannelType gptChannelid)
 {
     uint32 baseAdr = GPT_0_BASE;
     switch(gptChannelid)
     {
         case GPT_CHNL_TIMER0:
             baseAdr = GPT_0_BASE;
             break;
         case GPT_CHNL_TIMER1:
             baseAdr = GPT_1_BASE;
             break;
         case GPWT_CHNL_TIMER0:
             baseAdr = GPWT_0_BASE;
             break;
     }
     
     return baseAdr;
 }

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
 void GPT_EnableNotification(void (*fun_ptr)(void), GPT_ChannelType gptChannelid)
 {
     uint32 baseAdr;
     
     baseAdr = GPT_GetTimerBaseAdr(gptChannelid);
     
     isr_timer0A = fun_ptr;
     
     /* Clear the timeout interrupt flag */
     ACCESS_GPTMICR(baseAdr) |= 0x01;
         
     /* Enable time-out interrupt for timer A */
     ACCESS_GPTMIMR(baseAdr) |= 0x01;
 }
 
 void GPT_Init()
 {
     uint32 baseAdr;
     uint8 i = 0;
     
     for(i = 0; i < NUM_TIMER; i++)
     {
         baseAdr = GPT_GetTimerBaseAdr(gptConfig[i].gptChannelid);
         
         /* Enable the timer clock gate */
         if(gptConfig->channelMode < GPWT_CHNL_TIMER0)
         {
             SET_BIT(RCGCTIMER, gptConfig->channelMode);
         }
         else if(gptConfig->channelMode <= GPWT_CHNL_TIMER5)
         {
             SET_BIT(RCGCWTIMER, ((gptConfig->channelMode)-5));
         }
         else
         {
             return;
         }
     
         /* Disable the timer before any operation */
         CLR_BIT(ACCESS_GPTMCTL(baseAdr), 0u);
         
         /* Use the timer in 16 bit mode (or 32 bit mode in wide timers) */
         ACCESS_GPTMCFG(baseAdr) &= 0xFFFFFFF1;
         ACCESS_GPTMCFG(baseAdr) |= 0x04;
         
         /* Set the timer mode */
         CLR_BIT(ACCESS_GPTMTAMR(baseAdr), 4);  /* Set to count down mode*/
         
         if(gptConfig->channelMode == GPT_CH_MODE_CONTINUOUS)
            ACCESS_GPTMTAMR(baseAdr) |= 0x02;  /* Set to periodic mode*/
         else if(gptConfig->channelMode == GPT_CH_MODE_ONESHOT)
            ACCESS_GPTMTAMR(baseAdr) |= 0x01;  /* Set to one shot mode*/
         
         /* Set the prescale value */
         ACCESS_GPTMTAPR(baseAdr) = gptConfig->prescaler;
     }
 }
 
 void GPT_StartTimer(const GPT_ChannelType gptChannelid, const GPT_ValueType value)
 {
     uint32 baseAdr;
     baseAdr = GPT_GetTimerBaseAdr(gptChannelid);
     
     /* Set the value of timer A */
     ACCESS_GPTMTAILR(baseAdr) = value;
     
     /* Start the timer */
     ACCESS_GPTMCTL(baseAdr) |= 0x01;
 }
