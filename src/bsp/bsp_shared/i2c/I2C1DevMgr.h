/*****************************************************************************
* Model: I2C1DevMgr.qm
* File:  ./I2C1DevMgr_gen.h
*
* This code has been generated by QM tool (see state-machine.com/qm).
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*****************************************************************************/
/*${.::I2C1DevMgr_gen.h} ...................................................*/
/**
 * @file    I2C1DevMgr.h
 * @brief   Declarations for functions for the I2C1DevMgr AO.
 * This state machine handles any device that is attached to the I2C1 bus.
 * This AO doesn't handle the low level I2C commands and instead communicates
 * with I2CBusMgr AO to send the events that kick off the low level I2C cmds.
 * The rationale behind this is that different I2C devices require different
 * I2C commands in different order.  Some EEPROMs request 2 Start bits, some
 * other devices have different timeouts for their write/read commands. This
 * way, the I2C bus logic can stay common and any device differences are
 * handled in the device specific AOs.
 *
 * @note 1: If editing this file, please make sure to update the I2C1DevMgr.qm
 * model.  The generated code from that model should be very similar to the
 * code in this file.
 *
 * @date    10/24/2014
 * @author  Harry Rostovtsev
 * @email   harry_rostovtsev@datacard.com
 * Copyright (C) 2014 Datacard. All rights reserved.
 *
 * @addtogroup groupI2C
 * @{
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef I2C1DEVMGR_H_
#define I2C1DEVMGR_H_

/* Includes ------------------------------------------------------------------*/
#include "qp_port.h"                                        /* for QP support */
#include "Shared.h"                                   /*  Common Declarations */
#include "i2c.h"

/* Exported defines ----------------------------------------------------------*/
#define MAX_BUS_RETRIES   100 /**< Max number of retries for I2C bus for busy flag */
#define MAX_I2C_TIMEOUT 10000 /**< Max number of retries for I2C bus for busy flag */
/* Exported macros -----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/

/**
 * @brief Event struct type for specifying a raw memory read request.
 */
/*${Events::I2CEEPROMReadReqEvt} ...........................................*/
typedef struct {
/* protected: */
    QEvt super;

    /**< Internal memory address of the I2C device*/
    uint16_t addr;

    /**< Specify how many bytes to read */
    uint16_t bytes;
} I2CEEPROMReadReqEvt;

/**
 * @brief Event struct type for specifying a memory write request.
 */
/*${Events::I2CEEPROMWriteReqEvt} ..........................................*/
typedef struct {
/* protected: */
    QEvt super;

    /**< Internal memory address of the I2C device*/
    uint16_t addr;

    /**< Specify how many bytes to read */
    uint16_t bytes;

    /**< Buffer that holds the data. */
    uint8_t dataBuf[MAX_I2C_READ_LEN];
} I2CEEPROMWriteReqEvt;


/* Exported constants --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/**
 * @brief C "constructor" for I2C1DevMgr "class".
 * Initializes all the timers and queues used by the AO, sets up a deferral
 * queue, and sets of the first state.
 * @param [in]: none.
 * @retval: none
 */
/*${AOs::I2C1DevMgr_ctor} ..................................................*/
void I2C1DevMgr_ctor(void);


/**< "opaque" pointer to the Active Object */
extern QActive * const AO_I2C1DevMgr;


/**
 * @} end addtogroup groupI2C
 */
#endif                                                       /* I2C1DEVMGR_H_ */
/******** Copyright (C) 2014 Datacard. All rights reserved *****END OF FILE****/
