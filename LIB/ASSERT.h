/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY                      */
/* DESCRIPTION : Assert Macros    [ ASSERT.h]               */
/* DATE        : AUGUST 17, 2020                            */
/************************************************************/
#ifndef ASSERT_H_
#define ASSERT_H_

#define ERRORCODE NOK

#define assert_param(expr) ((expr)?  (Error_t)OK : While(1))


#endif /* ASSERT_H_ */
