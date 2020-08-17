/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY                      */
/* DESCRIPTION : SANDARD TYPES    [ STD_types.h]            */
/* DATE        : AUGUST 17, 2020                            */
/************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char           uint_8;
typedef signed   char           int_8;

typedef unsigned short int      uint_16;
typedef signed   short int      int_16;

typedef unsigned long int       uint_32;
typedef signed   long int       int_32;

typedef unsigned long long int  uint_64;
typedef signed   long long int  int_64;

typedef float                   f_32;
typedef double                  f_64;

typedef long double             f_96;

typedef enum
{
    OK		= 0x00,
    NOK	= 0xCF,
}Error_t;


#endif /* STD_TYPES_H_ */
