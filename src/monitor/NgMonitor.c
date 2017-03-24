/*
 ============================================================================
 Name        : NgMonitor.c
 Author      : heidsoft
 Version     :
 Copyright   : heidsoft
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <event.h>
#include "utils.h"

int main(void) {
	printf("Hello World %d \r\n",SIGINT); /* prints Hello World */

	//创建一个event_base
	struct event_base *base = event_base_new();
	if(base != NULL){
		printf("new event_base \r\n");
	}

	signal(SIGINT,test1);

	/*   pause - wait for signal */
	pause();

	test2();
	return EXIT_SUCCESS;
}
