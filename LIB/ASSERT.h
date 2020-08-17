/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY                      */
/* DESCRIPTION : Assert Macros    [ ASSERT.h]               */
/* DATE        : AUGUST 17, 2020                            */
/************************************************************/
#ifndef ASSERT_H_
#define ASSERT_H_

#define ERRORCODE NOK

#define assert_param(expr) ((expr) ? (void)0 : return ERRORCODE)


#endif /* ASSERT_H_ */
