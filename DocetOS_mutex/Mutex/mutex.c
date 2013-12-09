#include "mutex.h"

uint32_t __LDREXW ( uint32_t * addr );
uint32_t __STREXW ( uint32_t value , uint32_t * addr );

void init_TCB(OS_mutex_t * mutex){
	mutex->counter = 0;
	mutex->tcb = 0;
}

void OS_mutex_aquire(){
	
}

void OS_mutex_release(){
	
}
