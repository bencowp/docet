#ifndef _MUTEX_H_
#define _MUTEX_H_

#include "task.h"

uint32_t __LDREXW ( uint32_t * addr );
uint32_t __STREXW ( uint32_t value , uint32_t * addr );

typedef struct {
	OS_TCB_t * tcb;
	uint32_t counter;
} OS_mutex_t;


#endif /* _OS_H_ */
