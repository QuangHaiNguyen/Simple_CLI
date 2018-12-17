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
#include "string.h"
/* Define section ---------------------------------------------------*/



/* Local variable section --------------------------------------------*/
typedef enum STATE_MACHINE
{
	INIT = 0,
	IDLE,
	PROCESS,
	ERROR,
}State_Machine;

command_t const gCommandTable[COMMAND_TABLE_SIZE] =
{
		{"help", CommandHelp,},
		{"led", CommandLed, },
		{"buzz", CommandBuzzer, },
		{NULL, NULL }
};

static State_Machine state = INIT;
static char gCommandBuffer[MAX_COMMAND_LEN + 1];

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
	static uint8_t index = 0;
	char data;

	CirBuff_Status status = CLI_OK;
	do
	{
		status = PopCirBuff(&(self->mybuff), &data);

		//buffer is empty, nothing to copy
		if(CIR_OK != status)
			return status;

		/* Don't store any new line characters or spaces. */
		if ((data == '\r') || (data == ' ') || (data == '\t'))
		{
			status = CLI_ERROR;
			return status;
		}

		gCommandBuffer[index] = data;
		++index;
	}
	while(data != '\n');

	//we find what we need, reset the index
	gCommandBuffer[index - 1] = '\0';
	index = 0;

	return status;
}


CLI_Status CLI_ProcessData(CLI *self)
{
	uint8_t bCommandFound = 0;
	uint8_t idx;
	switch(state)
	{
		case INIT:
			//not sure what we want to initialize, just put it here for further usage
			state = IDLE;
			break;//case INIT

		case IDLE:
			if(CIR_EMPTY != IsCirBuffEmpty(&(self->mybuff)))
			{
				if(self->CLI_PrintData(self) == CLI_OK)
				{
					state = PROCESS;
				}
				else
				{
					state = IDLE;
				}

			}
			else
			{
				state = IDLE;
			}
			break;//case IDLE

		case PROCESS:

			//Scan thru the list of command
			for (idx = 0; gCommandTable[idx].name != NULL; idx++)
			{
				if (strcmp(gCommandTable[idx].name, gCommandBuffer) == 0)
				{
					bCommandFound = 1;
					break;
				}
			}
			/* If the command was found, call the command function. Otherwise,
			* output an error message. */
			if (bCommandFound == 1)
			{
				(*gCommandTable[idx].function)( );
			}
			else
				printf("Command not found.\n");

			memset((void *)gCommandBuffer, 0, MAX_COMMAND_LEN + 1);
			state = IDLE;
			break;//case PROCESS

		case ERROR:
			state = IDLE;
			break;//case ERROR

		default:
			state = IDLE;
			break;//case default
	}
	return CLI_OK;
}

void CommandHelp(void)
{
	printf("help\n");
}
void CommandLed(void)
{
	printf("led\n");
}
void CommandBuzzer(void)
{
	printf("buzz\n");
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



