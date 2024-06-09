#include "rte_app1_can_rx.h"

uint8_t g_u8IgState = 0U;
uint8_t g_u8PowerGearState = 0U;

uint8_t GetSystemPowerState()
{
    uint8_t state = SYSTEM_POWER_OFF;
    uint8_t ig_state = GetIgState();
    uint8_t power_gear_state = GetPowerGearState();
    if (power_gear_state == POWER_GEAR_ACC || power_gear_state == POWER_GEAR_ON 
     || ig_state == IG_ON)
    {
        state = SYSTEM_POWER_ON;
    }
    return state;
}

/**
 * @brief 获取 IG 状态。Get the Ig State object.
 * @return IgState 
 * 
 * @par Change log: creat at 2024-06-08 by strongnine
 * Date-Version-Author-Description
 */
uint8_t GetIgState()
{
    return g_u8IgState;
}

/**
 * @brief 获取电源档位。Get the Power Gear State object.
 * @return PowerGearState 
 * 
 * @par Change log: creat at 2024-06-08 by strongnine
 * Date-Version-Author-Description
 */
uint8_t GetPowerGearState()
{
    return g_u8PowerGearState;
}