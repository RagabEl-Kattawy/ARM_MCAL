/**
 * @file RCC_cfg.h
 * @author Ragab R. Elkattawy (r.elkattawy@gmail.com)
 * @brief 
 * @version 0.1
 * @date 10-26-2020
 * 
 * @copyright Ragab Elkattawy (c) 2020
 * 
 */

#ifndef RCC_CFG_H_
#define RCC_CFG_H_

/************************ Includes **************************/
/* System Clock Configurations */

/**
 * @brief System configuration Structure.
 * 
 */
RCC_SysClkCfg_t RCC_SysClkCfg
{
    PLL_MUL_9,  
    RCC_HSE,
    RCC_CSS_ON
};

/**
 * @brief Bus prescalers structure
 * 
 */
RCC_BusConfig_t RCC_BusConfig
{
    BUS_AHB_NONE,
    BUS_DIV_2,
    BUS_APB_NONE
};

#endif /* RCC_CFG_H_ */
