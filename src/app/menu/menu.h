/**
 * @file    menu.h
 * @brief   Implementation of the munu application using a statically allocated
 * k-ary tree structure.
 *
 * @date    09/29/2014
 * @author  Harry Rostovtsev
 * @email   harry_rostovtsev@datacard.com
 * Copyright (C) 2014 Datacard. All rights reserved.
 *
 * @addtogroup groupMenu
 * @{
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MENU_H_
#define MENU_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"                                 /* For STM32F4 support */
#include "ktree.h"
#include "Shared.h"

/* Exported defines ----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

treeNode_t* MENU_init( void );

void MENU_printMenuTree( treeNode_t *node, uint8_t level, MsgSrc whereToPrint );

void MENU_printNode( treeNode_t *node, uint8_t level, MsgSrc whereToPrint );
/**
 * @}
 * end addtogroup groupMenu
 */

#ifdef __cplusplus
}
#endif

#endif                                                             /* MENU_H_ */
/******** Copyright (C) 2014 Datacard. All rights reserved *****END OF FILE****/