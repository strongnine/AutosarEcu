#include <stdio.h>
#include <stdint.h>

#include "bsw_if.h"
#include "rte_app1_nvm_manage.h"

/**
 * @brief 上电读取数据
 * @return ErrCode : SUCCESS (0), ERROR (1)
 * 
 * @par Change log: creat at 2024-06-09 by strongnine
 * Date-Version-Author-Description
 */
ErrCode PowerOnReadNvmData()
{
    printf("Power on read NVM data success! \n");

    return SUCCESS;
}

/**
 * @brief 下电写入数据
 * @return ErrCode : SUCCESS (0), ERROR (1)
 * 
 * @par Change log: creat at 2024-06-09 by strongnine
 * Date-Version-Author-Description
 */
ErrCode PowerOffWriteNvmData()
{
    printf("Power off write NUM data success! \n");

    return SUCCESS;
}