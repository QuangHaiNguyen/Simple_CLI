/**
 * @file circular_buffer.c
 * @author Quang Hai Nguyen
 * @date 2018-12-15
 * @brief 
 *
 *
 */



/* Include section ---------------------------------------------------*/
#include "circular_buffer.h"
#include <stdio.h>
#include <string.h>

/* Define section ---------------------------------------------------*/


/* Global variable section -------------------------------------------*/

/* Local variable section --------------------------------------------*/

/* Global function section ---------------------------------*/

/**
 * @brief Initilize a circular buffer
 * 
 * @param cir_buff a circular buffer struct 
 *    
 * @return void
 */
void InitCirBuff( cir_buff * _this)
{
    _this->head = 0;
    _this->tail = 0;
    memset(_this, 0, sizeof(*_this));
    
}

/**
 * @brief Check if the buffer is empty
 * 
 * @param cir_buff a circular buffer struct 
 *    
 * @return Status of the buffer
 *          + OK (not empty)
 *          + EMPTY
 */
CirBuff_Status IsCirBuffEmpty(cir_buff * _this)
{
    return (0 == _this->count) ? CIR_EMPTY : CIR_OK;
}

/**
 * @brief Check if the buffer is full
 * 
 * @param cir_buff a circular buffer struct 
 *    
 * @return Status of the buffer
 *          + OK (not full)
 *          + FULL
 */
CirBuff_Status IsCirBuffFull(cir_buff * _this)
{
    return (_this->count == BUFF_SIZE) ? CIR_FULL : CIR_OK;
}

/**
 * @brief Push data into buffer
 * 
 * @param cir_buff  a circular buffer struct
 *        data      data pushed into buffer 
 *    
 * @return Status of the buffer
 *          + OK
 *          + FULL (buffer is full, data will be discarded)
 */
CirBuff_Status PushCirBuff(cir_buff * _this, char data)
{
    CirBuff_Status status;
    if(_this->count < BUFF_SIZE)//we still have space
    {
        _this->buff[_this->head] = data;
        _this->head = (++_this->head < BUFF_SIZE) ? _this->head : 0;
        _this->count = (++_this->count < BUFF_SIZE) ? _this->count : BUFF_SIZE;
        status = CIR_OK;
    }
    else
    {
        status = CIR_FULL;
    }
    return status;
}

/**
 * @brief Pop data out of buffer
 * 
 * @param cir_buff  a circular buffer struct
 *        data      a variable to store data popped out of buffer
 *    
 * @return Status of the buffer
 *          + OK
 *          + EMPTY (buffer is empty)
 */
CirBuff_Status PopCirBuff(cir_buff * _this, char * data)
{
    CirBuff_Status status;
    if(_this->count > 0)
    {
        *data = _this->buff[_this->tail];
        _this->tail = (++_this->tail < BUFF_SIZE) ? _this->tail : 0;
        _this->count = (--_this->count > 0) ? _this->count : 0;
        status = CIR_OK;
    }
    else
    {
        status = CIR_EMPTY;
    }
    return status;
}

/**
 * @brief Clear the buffer
 * 
 * @param cir_buff a circular buffer struct 
 *    
 * @return void
 */
void FlushCirBuff(cir_buff * _this)
{
    _this->head = 0;
    _this->tail = 0;
    _this->count = 0;
    memset(_this, 0, sizeof(* _this));
}



/* Local function section ----------------------------------*/


/**
 * @brief Function brief
 *        more on function brief
 * Some detail
 * @param param_name param_description
 *                   + param_value
 * @return void
 */



/**
 * @defgroup group_lable group_title
 * @ingroup group_lable
 * Group description
 * @{
 */
 
 
 
 /** @} */   



