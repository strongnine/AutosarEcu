/**
 * @file can_rx.h
 * @brief CAN 信号接收
 * @author strongnine (strongnine@163.com)
 * @version 0.1
 * @date 2024-06-08
 * @copyright Copyright (c) 2024 strongnine
 * 
 * @par Change log: 
 * Date-Version-Author-Description
 */

#ifndef RTE_APP1_CAN_RX_H
#define RTE_APP1_CAN_RX_H

#include <stdint.h>

#define SYSTEM_POWER_ON  ((uint8_t)1U)
#define SYSTEM_POWER_OFF ((uint8_t)0U)

typedef enum IgState_t
{
    IG_ON  = 0U,
    IG_OFF = 1U,
} IgState;

typedef enum PowerGearState_t
{
    POWER_GEAR_ACC = 0U,
    POWER_GEAR_ON  = 1U,
    POWER_GEAR_OFF = 2U,
} PowerGearState;

uint8_t GetIgState();
uint8_t GetPowerGearState();
uint8_t GetSystemPowerState();

#endif  // RTE_APP1_CAN_RX_H