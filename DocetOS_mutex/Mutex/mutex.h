#ifndef _MUTEX_H_
#define _MUTEX_H_

#include "task.h"

typedef struct {
	OS_TCB_t * tcb;
	uint32_t counter;
} OS_mutex_t;


#endif /* _OS_H_ */
