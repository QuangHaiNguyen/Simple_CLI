/**
 * @file cli.c
 * @author Quang Hai Nguyen
 * @date 2018-12-16
 * @brief 
 *
 *
 */



/* Include section ---------------------------------------------------*/
#include "circular_buffer.h"
#include "cli.h"

/* Define section ---------------------------------------------------*/



/* Local variable section --------------------------------------------*/



/* Local function prototype section ----------------------------------*/
CLI_Status CLI_PushDataToBuff( CLI * self, char data);
CLI_Status CLI_ProcessData(CLI *self);
CLI_Status CLI_PrintData(CLI * self); //test


/* Global function  section ----------------------------------*/
CLI_Status CLI_Init(CLI * self)
{
	InitCirBuff(&(self->mybuff));
	self->CLI_PushDataToBuff = &CLI_PushDataToBuff;
	self->CLI_ProcessData = &CLI_ProcessData;
	self->CLI_PrintData = &CLI_PrintData;
	return CLI_OK;
}

/* Local function  section ----------------------------------*/

CLI_Status CLI_PushDataToBuff( CLI * self, char data)
{
	return PushCirBuff(&(self->mybuff), data);
}

CLI_Status CLI_PrintData(CLI * self)
{
	char data;
	CirBuff_Status status = CLI_OK;
	do
	{
		status = PopCirBuff(&(self->mybuff), &data);
		if(CIR_OK != status)
			return status;
		printf("%c", data);
	}
	while(data != '\n');
	return status;
}


CLI_Status CLI_ProcessData(CLI *self)
{
	if(CIR_EMPTY != IsCirBuffEmpty(&(self->mybuff)))
	{
		self->CLI_PrintData(self);
	}
	return CLI_OK;
}
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
/** @} */ //end group_label



