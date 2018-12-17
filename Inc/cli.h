/**
 * @file cli.h
 * @author Quang Hai Nguyen
 * @date 2018-12-16
 * @brief 
 *
 *
 */



#ifndef __CLI_H
#define __CLI_H



#ifdef __cplusplus
 extern "C" {
#endif



/* Include section ---------------------------------------------------*/
#include "circular_buffer.h"


/* Define section ---------------------------------------------------*/
#define MAX_COMMAND_LEN (10)
#define COMMAND_TABLE_SIZE (4)


/* Global variable section -------------------------------------------*/
 typedef enum CLI_Status
 {
    CLI_OK = 0,
 	CLI_ERROR,
 	CLI_BUFF_FULL,
 	CLI_BUFF_EMPTY
 }CLI_Status;

typedef struct CLI
{
	cir_buff mybuff;
	CLI_Status (*CLI_PushDataToBuff)(struct CLI * self, char data);
	CLI_Status (*CLI_ProcessData)(struct CLI *self);
	CLI_Status (*CLI_PrintData)(struct CLI * self);
}CLI;


typedef struct
{
	char const *name;
	void (*function)(void);
} command_t;



/* Global function prototype section ---------------------------------*/
CLI_Status CLI_Init(CLI * self);
void CommandHelp(void);
void CommandLed(void);
void CommandBuzzer(void);



#ifdef __cplusplus
}
#endif



#endif /* __CLI_H*/



/**
 * @defgroup group_lable group_title
 * @ingroup group_lable
 * Group description
 * @{
 */
/** @} */ //end group_label



