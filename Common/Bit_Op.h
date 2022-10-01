/*
 * File: Bit_Op.h
 * Created Date: 2022-07-12
 * Author: Mohamed Atef
 * -----
 * Last Modified: Tue Jul 12 2022
 * Modified By: Mohamed Atef
 * -----
 * Copyright (c) 2022
 * -----
 * Description: Contains basic bit operations
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 */


#ifndef BIT_OP_H_INCLUDED
#define BIT_OP_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/

/************************************
 * GLOBAL FUNCTION MACROS
 ************************************/
#define SET_BIT(x, b)   (x |= (1u<<b))
#define CLR_BIT(x, b)   (x &= ~(1u<<b))
#define GET_BIT(x, b)   ((x & (1u << b) ) >> b)

/************************************
 * GLOBAL CONSTANT MACROS AND DEFINES
 ************************************/

/************************************
 * GLOBAL TYPES
 ************************************/

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
/* BIT_OP_H_INCLUDED */
