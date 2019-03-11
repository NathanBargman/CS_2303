#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "mystruct.h"
#include <time.h>

/** Runs the program
 * Takes no useful parameters
 */
int main(int argc, char *argv[]) {
	srand(time(0));
	puts("!!!Hello, this is HW3B!!!\n"); /* prints !!!Hello World!!! */
	if(tests())
	{
		puts("Tests succeeded.");
		if(production(argc, argv))
		{
			puts("Production successful.");
		}
		else
		{
			puts("Tests succeeded, but production didn't");
		}
	}
	else
	{
		puts("Tests did not succeed.");
	}

	return EXIT_SUCCESS;
}
