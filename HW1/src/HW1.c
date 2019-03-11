/*
 ============================================================================
 Name        : HW1.c
 Author      : Therese Smith
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"

int main(int argc, char*argv[]) {
	bool ok=false;// Later will be set true if production runs OK
	puts("!!!Hello World We're working HW1!!!");
	if(tests())
	{
		ok=production(argc, argv);
		if (ok)
		{
			puts("Production seems to have worked.");
		}
		else
		{
			puts("Production seems not to have worked.");
		}
	}
	else
	{
		puts("Something went wrong in the tests.");
	}
	return EXIT_SUCCESS;
}
