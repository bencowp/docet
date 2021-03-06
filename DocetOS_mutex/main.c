#include "os.h"
#include <stdio.h>
#include "serial.h"
#include "simpleRoundRobin.h"

void task1(void const *const args) {
	while (1) {
		printf("Message from Task 1\r\n");
	}
}

void task2(void const *const args) {
	while (1) {
		printf("Message from Task 2\r\n");
	}
}

/* MAIN FUNCTION */

int main(void) {
	/* Initialise the serial port so printf() works */
	serial_init();

	printf("\r\nDocetOS Demo\r\n");

	/* Reserve memory for two stacks and two TCBs.
	   Remember that stacks must be 8-byte aligned. */
	__align(8)
	uint32_t stack1[64], stack2[64];
	OS_TCB_t TCB1, TCB2;

	/* Initialise the TCBs using the two functions above */
	OS_initialiseTCB(&TCB1, stack1+64, task1, NULL);
	OS_initialiseTCB(&TCB2, stack2+64, task2, NULL);

	/* Initialise and start the OS */
	OS_init(&simpleRoundRobinScheduler);
	OS_addTask(&TCB1);
	OS_addTask(&TCB2);
	OS_start();
}
