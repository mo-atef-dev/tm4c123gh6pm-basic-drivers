/*
 * File: RCC.c
 * Created Date: 2022-07-18
 * Author: Mohamed Atef
 * -----
 * Last Modified: Mon Jul 18 2022
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
#include "RCC.h"
#include "RCC_cfg.h"

/************************************
 * LOCAL FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
 void RCC_Init(void)
 {
     RCC_SetOSCSource(RCC_OSC_SOURCE, RCC_USE_PLL, RCC_DIV_SYSCLK);
 }
 
 void RCC_SetOSCSource(uint8 oscSource, uint8 usePLL, uint8 sysClkDiv)
 {
     if(oscSource == RCC_OSC_SOURCE_MOSC)
     {
         /* Set MOSCDIS before changing the source to MOSC */
         SET_BIT(RCC, 1);
         
         RCC = (RCC & 0xFFFFFFCFu);
         RCC = (RCC | (RCC_OSC_SOURCE_MOSC << 4u));
     }
     else if(oscSource == RCC_OSC_SOURCE_PIOSC)
     {
         RCC = (RCC & 0xFFFFFFCFu);
         RCC = (RCC | (RCC_OSC_SOURCE_PIOSC << 4u));
     }
     else if(oscSource == RCC_OSC_SOURCE_PIOSCdiv4)
     {
         RCC = (RCC & 0xFFFFFFCFu);
         RCC = (RCC | (RCC_OSC_SOURCE_PIOSCdiv4 << 4u));
     }
     else if(oscSource == RCC_OSC_SOURCE_LFIOSC)
     {
         RCC = (RCC & 0xFFFFFFCF);
         RCC = (RCC | (RCC_OSC_SOURCE_LFIOSC << 4u));
     }
     else if(oscSource == RCC_OSC_SOURCE_32KHOSC)
     {
         
     }
     
     if(sysClkDiv >= RCC_DIV_SYSCLK_BY_1 && sysClkDiv <= RCC_DIV_SYSCLK_BY_16)
     {
         RCC = (RCC & 0xF87FFFFFu);
         RCC = (RCC | (sysClkDiv << 23u));
     }
 }
