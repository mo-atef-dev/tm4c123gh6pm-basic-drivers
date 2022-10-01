/*
 * File: IntCtrl.c
 * Created Date: 2022-07-05
 * Author: Mohamed Atef
 * -----
 * Last Modified: Tue Jul 12 2022
 * Modified By: Mohamed Atef
 * -----
 * Copyright (c) 2022
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 */


/************************************
 * INCLUDES
 ************************************/
#include "IntCtrl.h"
#include "IntCtrl_cfg.h"

/************************************
 * LOCAL FUNCTIONS
 ************************************/
void IntCtrl_EnableSpecialRegisters(uint8 priBound);

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
 void IntCtrl_Init(void)
{
    uint32 subMask;
    uint32 grpMask;
    uint32 grpShift;
    
    #if (PRIGROUP == PRIGROUP_XXX)
    subMask = 0;
    grpMask = 224;
    grpShift = 5;
    #elif (PRIGROUP == PRIGROUP_XXY)
    subMask = 32;
    grpMask = 192;
    grpShift = 6;
    #elif (PRIGROUP == PRIGROUP_XYY)
    subMask = 96;
    grpMask = 128;
    grpShift = 7;
    #elif (PRIGROUP == PRIGROUP_YYY)
    subMask = 224;
    grpMask = 0;
    grpShift = 8;
    #endif
    
    /* Configure grouping/sub-grouping system in APINT register */
    APINT = (0x05FA0000u + (PRIGROUP << 8u));
    
    /* Assign group/sub-group priority PRIx NVIC register and SYSPRIx SCB register */
    PRI0 = (PRI0 | ( (interrupt_GPIO_A.groupPriority << grpShift) &  grpMask ) | ( (interrupt_GPIO_A.subGroupPriority << 5u) &  subMask ) );
    PRI0 = (PRI0 | ( (interrupt_GPIO_B.groupPriority << (grpShift+8)) &  (grpMask << 8u) ) | ( (interrupt_GPIO_B.subGroupPriority << 13u) &  (subMask << 8u) ) );
    PRI0 = (PRI0 | ( (interrupt_GPIO_C.groupPriority << (grpShift+16)) &  (grpMask << 16u) ) | ( (interrupt_GPIO_C.subGroupPriority << 21u) &  (subMask << 16u) ) );
    PRI0 = (PRI0 | ( (interrupt_GPIO_D.groupPriority << (grpShift+24)) &  (grpMask << 24u) ) | ( (interrupt_GPIO_D.subGroupPriority << 29u) &  (subMask << 24u) ) );
    
    PRI1 = (PRI1 | ( (interrupt_GPIO_E.groupPriority << grpShift) &  grpMask ) | ( (interrupt_GPIO_E.subGroupPriority << 5) &  subMask ) );
    
    PRI4 = (PRI4 | ( (interrupt_GPT0_A.groupPriority << (grpShift+24)) &  (grpMask << 24u) ) | ( (interrupt_GPT0_A.subGroupPriority << 29u) &  (subMask << 24u) ) );
    
    /* Enable/disable interrupts in ENx and SYS registers based on user configurations */
    if(interrupt_GPIO_A.gate == ENABLE) SET_BIT(EN0, 0);
    if(interrupt_GPIO_B.gate == ENABLE) SET_BIT(EN0, 1);
    if(interrupt_GPIO_C.gate == ENABLE) SET_BIT(EN0, 2);
    if(interrupt_GPIO_D.gate == ENABLE) SET_BIT(EN0, 3);
    if(interrupt_GPIO_E.gate == ENABLE) SET_BIT(EN0, 4);
    
    if(interrupt_GPT0_A.gate == ENABLE) SET_BIT(EN0, 19);
    
    /* Enable interrupts in core registers and set priority bound */
    IntCtrl_EnableSpecialRegisters(PRIBASE);
    
}
