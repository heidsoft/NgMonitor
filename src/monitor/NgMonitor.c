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
#include <event.h>
#include "utils.h"

int main(void) {
	puts("Hello World"); /* prints Hello World */

	//创建一个event_base
	struct event_base *base = event_base_new();
	if(base != NULL){
		printf("new event_base\n");
	}



	test1();
	test2();
	return EXIT_SUCCESS;
}
