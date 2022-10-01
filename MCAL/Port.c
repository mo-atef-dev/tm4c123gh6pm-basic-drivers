/*
 * File: Port.c
 * Created Date: 2022-07-19
 * Author: Mohamed Atef
 * -----
 * Last Modified: Tue Jul 19 2022
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
#include "Port.h"
#include "Bit_Op.h"

/************************************
 * LOCAL DATA
 ************************************/


/************************************
 * LOCAL FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
 void Port_EnablePortClock(Port_PortType port)
 {
     /* Set the ports to use the AHB */
     GPIOHBCTL = GPIOHBCTL | 0x0000003Fu;
     
     /* Enable the clock gate of the parameter port*/
     RCGCGPIO = RCGCGPIO | (1u << port);
     
     /* Wait for 3 clock cycles before continuing to allow modification of GPIO registers */
     __asm
     (
         "NOP \t\n"
         "NOP \t\n"
         "NOP \t\n"
     );
 }
 
 void Port_Init()
 {
     Port_ConfigType currentConfig;
     uint8 i = 0;
     
     /* Loop until either the sentinel value is reached to detect the end of array or until maximum number of pins is reached */
     for(i = 0; i < NUM_PINS; i++)
     {
         /* Get the values of the current iteration of the array  */
         currentConfig = portConfig[i];     
         
         /* Exit if this is the PORT_NC pin*/
         if(currentConfig.pin == PIN_NC)
         {
             break;
         }
         
         /* Enable the clock gate of the port */
         Port_EnablePortClock((uint8)currentConfig.pin / 8u);    
		 
		 /* Unlock the pin if it is locked */
		 #warning "The driver only supports unlocking pin f0, any other locked pins (eg. JTAG pins) must be unlocked manually"
		 if(currentConfig.pin == PIN_F0)
		 {
			 GPIOLOCK_AHB_F = 0x4C4F434Bu;
			 GPIOCR_AHB_F = 0x01u;
		 }
             
         /* Adjust the pin direction */
         switch(((uint8)currentConfig.pin / 8u))
         {
             /* Case Port A */
             case 0:
                 if(currentConfig.direction == PIN_OUTPUT)
                     SET_BIT(GPIODIR_AHB_A, (currentConfig.pin % 8));
                 else
                     CLR_BIT(GPIODIR_AHB_A, (currentConfig.pin % 8));
                 break;
             /* Case Port B */
             case 1:
                 if(currentConfig.direction == PIN_OUTPUT)
                     SET_BIT(GPIODIR_AHB_B, (currentConfig.pin % 8));
                 else
                     CLR_BIT(GPIODIR_AHB_B, (currentConfig.pin % 8));
                 break;
             /* Case Port C */
             case 2:
                 if(currentConfig.direction == PIN_OUTPUT)
                     SET_BIT(GPIODIR_AHB_C, (currentConfig.pin % 8));
                 else
                     CLR_BIT(GPIODIR_AHB_C, (currentConfig.pin % 8));
                 break;
             /* Case Port F */
             case 5:
                 if(currentConfig.direction == PIN_OUTPUT)
                     SET_BIT(GPIODIR_AHB_F, (currentConfig.pin % 8));
                 else
                     CLR_BIT(GPIODIR_AHB_F, (currentConfig.pin % 8));
                 break;
         }
         
         /* Adjust the pin function */
         switch(((uint8)currentConfig.pin / 8u))
         {
             /* Case Port A */
             case 0:
                 if(currentConfig.mode == PIN_DIO)
                     CLR_BIT(GPIOAFSEL_AHB_A, (currentConfig.pin % 8));
                 else
                     SET_BIT(GPIOAFSEL_AHB_A, (currentConfig.pin % 8));
                 break;
             /* Case Port B */
             case 1:
                 if(currentConfig.mode == PIN_DIO)
                     CLR_BIT(GPIOAFSEL_AHB_B, (currentConfig.pin % 8));
                 else
                     SET_BIT(GPIOAFSEL_AHB_B, (currentConfig.pin % 8));
                 break;
             /* Case Port C */
             case 2:
                 if(currentConfig.mode == PIN_DIO)
                     CLR_BIT(GPIOAFSEL_AHB_C, (currentConfig.pin % 8));
                 else
                     SET_BIT(GPIOAFSEL_AHB_C, (currentConfig.pin % 8));
                 break;
             /* Case Port F */
             case 5:
                 if(currentConfig.mode == PIN_DIO)
                     CLR_BIT(GPIOAFSEL_AHB_F, (currentConfig.pin % 8));
                 else
                     SET_BIT(GPIOAFSEL_AHB_F, (currentConfig.pin % 8));
                 break;
         }
         
         /* Adjust the pin mode */
         switch(((uint8)currentConfig.pin / 8u))
         {
             /* Case Port A */
             case 0:
                 if(currentConfig.mode == PIN_DIO)
                     SET_BIT(GPIODEN_AHB_A, (currentConfig.pin % 8));
                 else
                     CLR_BIT(GPIODEN_AHB_A, (currentConfig.pin % 8));
                 break;
             /* Case Port B */
             case 1:
                 if(currentConfig.mode == PIN_DIO)
                     SET_BIT(GPIODEN_AHB_B, (currentConfig.pin % 8));
                 else
                     CLR_BIT(GPIODEN_AHB_B, (currentConfig.pin % 8));
                 break;
             /* Case Port C */
             case 2:
                 if(currentConfig.mode == PIN_DIO)
                     SET_BIT(GPIODEN_AHB_C, (currentConfig.pin % 8));
                 else
                     CLR_BIT(GPIODEN_AHB_C, (currentConfig.pin % 8));
                 break;
             /* Case Port F */
             case 5:
                 if(currentConfig.mode == PIN_DIO)
                     SET_BIT(GPIODEN_AHB_F, (currentConfig.pin % 8));
                 else
                     CLR_BIT(GPIODEN_AHB_F, (currentConfig.pin % 8));
                 break;
         }
         
         
         /* Adjust the pin attachement */
         switch(((uint8)currentConfig.pin / 8u))
         {
             /* Case Port A */
             case 0:
                 if(currentConfig.internalAttach == PIN_PULLUP)
                     SET_BIT(GPIOPUR_AHB_A, (currentConfig.pin % 8));
                 else
                     CLR_BIT(GPIOPUR_AHB_A, (currentConfig.pin % 8));
                 break;
             /* Case Port B */
             case 1:
                 if(currentConfig.internalAttach == PIN_PULLUP)
                     SET_BIT(GPIOPUR_AHB_B, (currentConfig.pin % 8));
                 else
                     CLR_BIT(GPIOPUR_AHB_B, (currentConfig.pin % 8));
                 break;
             /* Case Port C */
             case 2:
                 if(currentConfig.internalAttach == PIN_PULLUP)
                     SET_BIT(GPIOPUR_AHB_C, (currentConfig.pin % 8));
                 else
                     CLR_BIT(GPIOPUR_AHB_C, (currentConfig.pin % 8));
                 break;
             /* Case Port F */
             case 5:
                 if(currentConfig.internalAttach == PIN_PULLUP)
                     SET_BIT(GPIOPUR_AHB_F, (currentConfig.pin % 8));
                 else
                     CLR_BIT(GPIOPUR_AHB_F, (currentConfig.pin % 8));
                 break;
         }
		 
		 /* Lock the pin if it was originally locked */
		 if(currentConfig.pin == PIN_F0)
		 {
			 GPIOLOCK_AHB_F = 0x4C4F434Bu;
			 GPIOCR_AHB_F = 0x00u;
		 }
     }
 }

