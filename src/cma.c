#include <application/cma.h>


extern void send_usbmessage(uint8*, int);

void printTrace(tracestruct* trace){
	int n=0;
	char msg[100];
	int sizeTrace = sizeof(tracestruct);
	for(int i=0; i<=count_traces-1 ; i++){
		n = sprintf(msg, "7E %u %d SWSystem.%s_PI_%d", trace[i].timestamp, trace[i].eventId,(char*) trace[i].InstanceId, (char*) trace[i].StateId);
		if(usb_ready()){
			usb_run();
			send_usbmessage(&msg[0], n);
			usb_run();
		}
	}
	count_traces = 0;

	return;

}


