/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY                      */
/* DESCRIPTION : RCC CONFIGURATION    [RCC_cfg.h]           */
/* DATE        : AUGUST 17, 2020                            */
/************************************************************/
#ifndef RCC_CFG_H_
#define RCC_CFG_H_

/************************ Includes **************************/
#include "RCC_int.h"
/* System Clock Configurations */
/* Clock source */
RCC_SysClk_t RCC_SysClk = {
    /* RCC_ClockSource */
};
RCC_HSECfg_t RCC_HSECfg{

};
/* PLL configuration in case of PLL is chosen as a source */
RCC_PLL_t RCC_PLL = {
    /* RCC_PLLMul */
    /* RCC_PLLSource */
}RCC_PLLMul;



#endif /* RCC_CFG_H_ */
