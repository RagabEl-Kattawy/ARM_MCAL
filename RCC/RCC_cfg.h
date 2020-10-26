/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY                      */
/* DESCRIPTION : RCC CONFIGURATION    [RCC_cfg.h]           */
/* DATE        : AUGUST 17, 2020                            */
/************************************************************/
#ifndef RCC_CFG_H_
#define RCC_CFG_H_

/************************ Includes **************************/
/* System Clock Configurations */
/* Clock source */
RCC_SysClkCfg_t RCC_SysClkCfg
{
    PLL_MUL_9, /* RCC_PLLMul */
    RCC_HSE, /* RCC_ClockSource */
    RCC_CSS_ON /* RCC_CSS */
};

RCC_BusConfig_t RCC_BusConfig
{
    BUS_AHB_NONE, /* RCC_AHBPre */
    BUS_DIV_2,/* RCC_APB1Pre Low spped 36MHz Max*/
    BUS_APB_NONE/* RCC_APB2Pre */
};

#endif /* RCC_CFG_H_ */
