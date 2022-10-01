/*
 * File: DIO_Types.h
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


#ifndef DIO_TYPES_H_INCLUDED
#define DIO_TYPES_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/
#include "Std_Types.h"
#include "Port_Types.h"

/************************************
 * GLOBAL CONSTANT MACROS AND DEFINES
 ************************************/

/************************************
 * GLOBAL FUNCTION MACROS
 ************************************/

/************************************
 * GLOBAL TYPES
 ************************************/
typedef Port_PinType DIO_ChannelType;

typedef Port_PortType DIO_PortType;

typedef enum
{
    LOW,
    HIGH
} DIO_LevelType;

typedef uint8 DIO_PortLevelType;

/************************************
 * GLOBAL DATA PROTOTYPES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

/************************************
 * EXTERNAL VARIABLES
 ************************************/

#endif
/* DIO_TYPES_H_INCLUDED */
