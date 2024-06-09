/**
 * @file ecu_state_manage.h
 * @brief ECU 状态管理
 * @author strongnine (strongnine@163.com)
 * @version 0.1
 * @date 2024-06-05
 * @copyright Copyright (c) 2024 strongnine
 * 
 * @par Change log:
 * Date-Version-Author-Description
 */

#ifndef RTE_APP1_STATE_MANAGE_H
#define RTE_APP1_STATE_MANAGE_H

#include <stdint.h>

#define ECU_PRESLEEP_TIMEOUT_CNT ((uint8_t)5U)
#define NM_TIMEOUT_CNT           ((uint8_t)5U)
#define WAIT_BUS_SLEEP_CNT       ((uint8_t)5U)

/**
 * @brief ECU 状态枚举值
 * 
 * @par Change log: creat at 2024-06-05 by strongnine
 * Date-Version-Author-Description
 */
typedef enum EcuState_t
{
    ECU_INIT_STATE,
    ECU_PRESLEEP_STATE,
    ECU_SLEEP_STATE,
    ECU_SELFCHECK_FAULT_STATE,
    ECU_RUN_APP_MODE,
    ECU_VDS_MODE,
    ECU_POWER_OFF_STATE
} EcuState;

typedef enum NmState_t
{
    NM_INIT_STATE,
    NM_PRESLEEP_STATE,
    NM_SLEEP_STATE,
    NM_NORMAL_STATE
} NmState;

void StateManagerInit();
void StateManagerMain();
void ResetTimer(uint8_t *timer);

/* ECU 状态管理相关函数 */
EcuState GetEcuState();
void SetEcuState(EcuState state);
void EcuInitStateManage();
void EcuPresleepStateManage();
void EcuSleepStateManage();
void EcuSelfCheckFaultStateMange();
void EcuRunAppModeManage();
void EcuVdsModeManage();
void EcuPowerOffStateManage();
void EcuStateManagerInit();
void EcuStateManagerMain();

/* 网络管理相关函数 */
NmState GetNmState();
void SetNmState(NmState state);
void NmInitStateManage();
void NmPresleppStateManage();
void NmSleepStateManage();
void NmNormalStateManage();
void NmStateManagerInit();
void NmStateManagerMain();

#endif  // RTE_APP1_STATE_MANAGE_H