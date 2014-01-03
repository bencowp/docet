#include "mutex.h"
#include "os.h"
#include "stm32f4xx.h"

void init_TCB(OS_mutex_t * mutex){
	mutex->counter = 0;
	mutex->tcb = 0;
}

void OS_mutex_aquire(OS_mutex_t * mutex){
	OS_TCB_t * tcb;
	//Load TCB field of the mutex...
	tcb = (OS_TCB_t *) __LDREXW((uint32_t *) mutex->tcb);
	//...If it's zero, store current TCB in the mutex's TCB field.
	if(tcb == 0) {
		uint32_t storeFail = 1;
		storeFail = __STREXW((uint32_t) OS_currentTCB(), (uint32_t *) mutex->tcb);
		if(storeFail == 1) {
			//If the store fails, try again.
			OS_mutex_aquire(mutex);
		}
	/*...If it's not zero and different TCB to the current one,
		then pause this task and try again. */
	} else if(tcb != 0 && tcb != OS_currentTCB()) {
		OS_wait(mutex);
		OS_mutex_aquire(mutex);
	}
	mutex->counter++;
}

void OS_mutex_release(OS_mutex_t * mutex){
	
}
