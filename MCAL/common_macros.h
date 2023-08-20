 /******************************************************************************
 *
 * Module: Common - Macros
 *
 * File Name: Common_Macros.h
 *
 * Description: Commonly used Macros
 *
 * Author: Youssef Khaled
 *
 *******************************************************************************/

#ifndef COMMON_MACROS
#define COMMON_MACROS

#define GET_BIT(REG , BIT_NUM) ((REG>>BIT_NUM) & 0x01)
#define SET_BIT(REG , BIT_NUM) (REG |= (1<<BIT_NUM))
#define CLEAR_BIT(REG , BIT_NUM) (REG &= ~(1<<BIT_NUM))
#define TOGGLE_BIT(REG , BIT_NUM) (REG ^= (1<<BIT_NUM))
#define ROR(REG , BIT_NUM) (REG = (REG >> BIT_NUM) | (REG<<(sizeof(REG)*8 - BIT_NUM)))
#define ROL(REG , BIT_NUM) (REG = (REG << BIT_NUM) | (REG>>(sizeof(REG)*8 - BIT_NUM)))
#define BIT_IS_SET(REG , BIT_NUM) (REG & (1<<BIT_NUM))
#define BIT_IS_CLEAR(REG , BIT_NUM) (!(REG &(1<<BIT_NUM)))

#endif
