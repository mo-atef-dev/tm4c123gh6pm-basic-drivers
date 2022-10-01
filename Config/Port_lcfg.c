/*
 * File: Port_lcfg.c
 * Created Date: 2022-07-25
 * Author: Mohamed Atef
 * -----
 * Last Modified: Mon Jul 25 2022
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
#include "Port_Types.h"
#include "Port.h"
#include "tm4c123gh6pm_hw.h"

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * PRIVATE TYPEDEFS
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/

/************************************
 * GLOBAL VARIABLES
 ************************************/
extern const Port_ConfigType portConfig[NUM_PINS] =
{
    /* Pin          Direction           Mode            Attach Type         Output Current */
    { PIN_A0,      	PIN_OUTPUT,        	PIN_DIO,       	PIN_PULLDOWN,      	PIN_CURRENT_2mA},
    { PIN_A1,      	PIN_OUTPUT,        	PIN_DIO,       	PIN_PULLDOWN,      	PIN_CURRENT_2mA},
    { PIN_A2,      	PIN_OUTPUT,        	PIN_DIO,       	PIN_PULLDOWN,     	PIN_CURRENT_2mA},
    { PIN_A3,      	PIN_OUTPUT,        	PIN_DIO,       	PIN_PULLDOWN,      	PIN_CURRENT_2mA},
    { PIN_A4,      	PIN_OUTPUT,        	PIN_DIO,       	PIN_PULLDOWN,      	PIN_CURRENT_2mA},
	{ PIN_F0,      	PIN_INPUT,        	PIN_DIO,       	PIN_PULLUP,      	PIN_CURRENT_2mA},
    { PIN_F1,      	PIN_OUTPUT,        	PIN_DIO,       	PIN_PULLDOWN,      	PIN_CURRENT_2mA},
    { PIN_F2,      	PIN_OUTPUT,        	PIN_DIO,       	PIN_PULLDOWN,      	PIN_CURRENT_2mA},
    { PIN_F3,      	PIN_OUTPUT,        	PIN_DIO,       	PIN_PULLDOWN,      	PIN_CURRENT_2mA},
	{ PIN_F4,      	PIN_INPUT,        	PIN_DIO,       	PIN_PULLUP,      	PIN_CURRENT_2mA},
    
    /* This is the sentinel terminating element of the array and should never be changed */
    { PIN_NC,      0,        0,       0,      0}
};


/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
