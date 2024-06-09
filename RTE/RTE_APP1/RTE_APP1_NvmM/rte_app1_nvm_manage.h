/**
 * @file nvm_manage.h
 * @brief NVM 内存管理
 * @author strongnine (strongnine@163.com)
 * @version 0.1
 * @date 2024-06-08
 * @copyright Copyright (c) 2024 strongnine
 * 
 * @par Change log: 
 * Date-Version-Author-Description
 */

#ifndef RTE_APP1_NVM_MANAGE_H
#define RTE_APP1_NVM_MANAGE_H

;  // 2024-06-08 不加这一行就会报错

/**
 * @brief 错误码枚举值
 * 
 * @par Change log: creat at 2024-06-08 by strongnine
 * Date-Version-Author-Description
 */
typedef enum ErrCode_t
{
    SUCCESS,
    ERROR,
} ErrCode;

ErrCode PowerOnReadNvmData();
ErrCode PowerOffWriteNvmData();

#endif  // RTE_APP1_NVM_MANAGE_H