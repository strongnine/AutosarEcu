#include <stdio.h>
#include <stdint.h>

#include "bsw_if.h"

#include "rte_app1_state_manage.h"
#include "rte_app1_nvm_manage.h"
#include "rte_app1_can_rx.h"

extern uint8_t g_u8IgState;
extern uint8_t g_u8PowerGearState;

static uint8_t Timer_EcuPresleepTimeOut;
static uint8_t Timer_NmTimeOut;
static uint8_t Timer_WaitBusSleep;

EcuState g_EcuState;
NmState g_NmState;

void ResetTimer(uint8_t *timer)
{
    *timer = 0U;
}

/**
 * @brief 获取当前 ECU 状态。Get the Ecu State. 
 * @return EcuState 当前 ECU 状态
 * 
 * @par Change log: creat at 2024-06-05 by strongnine
 * Date-Version-Author-Description
 */
EcuState GetEcuState()
{
    return g_EcuState;
}

/**
 * @brief 设置 ECU 状态。Set Ecu State.
 * @param state 待设置的 ECU 状态
 * 
 * @par Change log: creat at 2024-06-05 by strongnine
 * Date-Version-Author-Description
 */
void SetEcuState(EcuState state)
{
    g_EcuState = state;
}

/**
 * @brief 获取当前网络状态。Get the Network State.
 * @return NmState 当前网络状态
 * 
 * @par Change log: creat at 2024-06-05 by strongnine
 * Date-Version-Author-Description
 */
NmState GetNmState()
{
    return g_NmState;
}

/**
 * @brief 设置网络状态。Set the Network State.
 * @param state 待设置的网络状态
 * 
 * @par Change log: creat at 2024-06-05 by strongnine
 * Date-Version-Author-Description
 */
void SetNmState(NmState state)
{
    g_NmState = state;
}

/**
 * @brief ECU 状态转移管理 - 初始化状态
 * 
 * @par Change log: creat at 2024-06-08 by strongnine
 * Date-Version-Author-Description
 */
void EcuInitStateManage()
{
    PowerOnReadNvmData();  // 上电读取数据
    SetEcuState(ECU_PRESLEEP_STATE);
}

/**
 * @brief ECU 状态管理 - 待休眠状态
 * 
 * @par Change log: creat at 2024-06-08 by strongnine
 * Date-Version-Author-Description
 */
void EcuPresleepStateManage()
{
    if (Timer_EcuPresleepTimeOut > ECU_PRESLEEP_TIMEOUT_CNT)
    {
        ResetTimer(&Timer_EcuPresleepTimeOut);
        PowerOffWriteNvmData();
        EcuReqPowerOff();
        SetEcuState(ECU_SLEEP_STATE);
    }
    else if (GetSystemPowerState() == SYSTEM_POWER_ON)
    {
        ResetTimer(&Timer_EcuPresleepTimeOut);
        SetEcuState(ECU_RUN_APP_MODE);
    }
    else 
    {
        Timer_EcuPresleepTimeOut++;
    }
}

/**
 * @brief ECU 状态管理 - 休眠状态
 * 
 * @par Change log: creat at 2024-06-08 by strongnine
 * Date-Version-Author-Description
 */
void EcuSleepStateManage()
{
    if (GetSystemPowerState() == SYSTEM_POWER_ON)
    {
        SetEcuState(ECU_INIT_STATE);
    }
}

void EcuSelfCheckFaultStateMange()
{
    ;
}

void EcuRunAppModeManage()
{
    ;
}

void EcuVdsModeManage()
{
    ;
}

void EcuPowerOffStateManage()
{
    ;
}

/**
 * @brief 网络管理状态管理 - 初始化状态
 * 
 * @par Change log: creat at 2024-06-08 by strongnine
 * Date-Version-Author-Description
 */
void NmInitStateManage()
{
    SetNmState(NM_PRESLEEP_STATE);
}

void NmPresleppStateManage()
{
    ;
}

void NmSleepStateManage()
{
    ;
}

void NmNormalStateManage()
{
    ;
}

/**
 * @brief ECU 状态管理主函数
 * 
 * @par Change log: creat at 2024-06-05 by strongnine
 * Date-Version-Author-Description
 */
void EcuStateManagerMain()
{
    switch (g_EcuState)
    {
    case ECU_INIT_STATE:
        EcuInitStateManage();
        break;
    case ECU_PRESLEEP_STATE:
        EcuPresleepStateManage();
        break;
    case ECU_SLEEP_STATE:
        EcuSleepStateManage();
        break;
    case ECU_SELFCHECK_FAULT_STATE:
        EcuSelfCheckFaultStateMange();
        break;
    case ECU_RUN_APP_MODE:
        EcuRunAppModeManage();
        break;
    case ECU_VDS_MODE:
        EcuVdsModeManage();
        break;
    case ECU_POWER_OFF_STATE:
        EcuPowerOffStateManage();
        break;
    default:
        break;
    }
}

/**
 * @brief 网络管理主函数
 * 
 * @par Change log: creat at 2024-06-08 by strongnine
 * Date-Version-Author-Description
 */
void NmStateManagerMain()
{
    switch (g_NmState)
    {
    case NM_INIT_STATE:
        NmInitStateManage();
        break;
    case NM_PRESLEEP_STATE:
        NmPresleppStateManage();
        break;
    case NM_SLEEP_STATE:
        NmSleepStateManage();
        break;
    case NM_NORMAL_STATE:
        NmNormalStateManage();
        break;
    default:
        break;
    }
}

/**
 * @brief 网络管理初始化
 * 
 * @par Change log: creat at 2024-06-08 by strongnine
 * Date-Version-Author-Description
 */
void NmStateManagerInit()
{
    Timer_NmTimeOut = 0;
    Timer_WaitBusSleep = 0;
    SetNmState(NM_INIT_STATE);
}

/**
 * @brief ECU 状态管理初始化
 * 
 * @par Change log: creat at 2024-06-08 by strongnine
 * Date-Version-Author-Description
 */
void EcuStateManagerInit()
{
    Timer_EcuPresleepTimeOut = 0;
    SetEcuState(ECU_INIT_STATE);
}

/**
 * @brief 状态管理初始化
 * 
 * @par Change log: creat at 2024-06-08 by strongnine
 * Date-Version-Author-Description
 */
void StateManagerInit()
{
    EcuStateManagerInit();
    NmStateManagerInit();
}

/**
 * @brief 状态管理主函数
 * 
 * @par Change log: creat at 2024-06-08 by strongnine
 * Date-Version-Author-Description
 */
void StateManagerMain()
{
    int i = 0;

    StateManagerInit();
    while (i < 5)
    {
        printf("Input current IG state: ");
        scanf("%hhu", &g_u8IgState);
        fflush(stdin);

        printf("Input current Power Gear state: ");
        scanf("%hhu", &g_u8PowerGearState);
        fflush(stdin);

        printf("Power state: %d, %d\n", g_u8IgState, g_u8PowerGearState);
        printf("Current State: %d, %d\n", g_EcuState, g_NmState);

        EcuStateManagerMain();
        NmStateManagerMain();

        printf("Timer_EcuPresleepTimeOut: %d\n", Timer_EcuPresleepTimeOut);

        printf("====================\n");
        // 线程延迟固定周期

        i++;
    }
    
}