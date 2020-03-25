#ifndef APPLICATION_CMA_H_
#define APPLICATION_CMA_H_


#include <application/SM_Mote02_v1.h>

#define app1 "application_1"
#define app2 "application_2"
#define MAX_TRACE 20

int count_traces;
uint32 sysTime0;

typedef enum
{
	RUNNING = 0,
	READY 	= 1,
	BLOCKED = 2,
	SLEEP 	= 3,
	WAKEUP 	= 4,
} eventId;							

typedef struct
{
	uint32 timestamp;
	SM_StatusTypeDef StateId;		
	eventId eventId;
	char* InstanceId;
} tracestruct;

tracestruct tracesArray[100];


void printTrace(tracestruct* trace);

#endif /* APPLICATION_CMA_H_ */
