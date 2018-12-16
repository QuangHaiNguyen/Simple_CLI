/**
 * @file circular_buffer.h
 * @author Quang Hai Nguyen
 * @date 2018-12-15
 * @brief 
 *
 *
 */



#ifndef __CIRCULAR_BUFFER_H
#define __CIRCULAR_BUFFER_H



#ifdef __cplusplus
 extern "C" {
#endif



/* Include section ---------------------------------------------------*/



/* Define section ---------------------------------------------------*/



/* Global variable section -------------------------------------------*/



/* Global function prototype section ---------------------------------*/
#define BUFF_SIZE 8

typedef struct Cir_Buff
{
    int buff[BUFF_SIZE];
    int head;
    int tail;
    int count;
}cir_buff;

typedef enum CirBuff_Status
{
    OK = 0,
    ERROR,
    FULL,
    EMPTY
}CirBuff_Status;

CirBuff_Status IsCirBuffEmpty(cir_buff * _this);
CirBuff_Status IsCirBuffFull(cir_buff * _this);
CirBuff_Status PushCirBuff(cir_buff * _this, int data);
CirBuff_Status PopCirBuff(cir_buff * _this, int * data);
void FlushCirBuff(cir_buff * _this);
void InitCirBuff( cir_buff * _this);


#ifdef __cplusplus
}
#endif



#endif /* __CIRCULAR_BUFFER_H*/



/**
 * @defgroup group_lable group_title
 * @ingroup group_lable
 * Group description
 * @{
 */
/** @} */ //end group_label



