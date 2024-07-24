/*
 * BIT_MATH.h
 *
 * Created: 10/2/2023 5:35:32 PM
 *  Author: karim
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)
#define TGL_BIT(REG,BIT) REG^=(1<<BIT)
#define GET_BIT(REG,BIT) ((REG>>BIT)&0x01)

#endif /* BIT_MATH_H_ */