/*
 * tests.c
 *
 *  Created on: Feb 4, 2019
 *      Author: ciaraldi
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystruct.h"

/** Used to test the functionality of this code
 * @return true if the program ran as intended
 */
bool tests(void)
{
	bool ok = false;

	bool ok1 = testPrintEmployee();
	if (ok1) {
		puts("printEmployee() passed\n");
	}

	bool ok2 = testMakeEmployee();
	if (ok2) {
		puts("makeEmployee() passed\n");
	}

	bool ok3 = testMakeRndAndPrint();
	if(ok3){
		puts("Created and Printed a random array of Employee\n");
	}

	bool ok4 = testShallowCopy();
	if(ok4){
		puts("Created and Printed a copy of an Employee array\n");
	}

	bool ok5 = testDeallocate();
	if(ok5){
		puts("Ran Deallocation\n");
	}

	bool ok6 = testDeepCopy();
	if(ok6){
		puts("Created and Printed a deep copy of an Employee array\n");
	}

	ok = ok1 && ok2 && ok2 && ok4 && ok5 && ok6; // Did all tests pass?
	return ok;
}

/**
 * Test the printEmployee() function by creating a known struct and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */

bool testPrintEmployee() {

	struct Employee e; // Variable to hold employee
	e.birth_year = 1952; // Put data into numeric fields
	e.start_year = 1999;
	// Copy into string field. Be sure not to overflow it.
	strncpy(e.name, "Mike Ciaraldi", MAX_NAME);
	e.name[MAX_NAME] = '\0'; // Be sure string is terminated.

	printEmployee(&e);

	return true;
}


/** Test the make Employee() function by making an employee with known data and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testMakeEmployee() {
	struct Employee *e;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(e);

	return true;
}

/** Test the makeRndEmployee and printEmployee functions
 * @return true. The only way to tell if it succeeds is to look at the output
 */
bool testMakeRndAndPrint(){
	struct Employee** e;

	e = makeRandomArray(5);
	printAllEmployee(e, 5);

	return true;
}

/** Test the makeShallowCopy function
 * @return true. The only way to tell if it succeeds is to look at the output
 */
bool testShallowCopy(){
	struct Employee** e;
	struct Employee** e2;

	printf("Printing first array:\n");
	e = makeRandomArray(2);
	printAllEmployee(e, 2);
	printf("Employee Address: %p\n", *e);
	printf("Array Address: %p\n", e);

	printf("Printing copied array:\n");
	e2 = makeShallowCopy(e, 2);
	printAllEmployee(e2, 2);
	printf("Employee Address: %p\n", *e2);
	printf("Array Address: %p\n", e2);

	return true;
}

/** Test the destructArray function, it is either pass or error.
 * @return true
 */
bool testDeallocate(){
	struct Employee** e;
	e = makeRandomArray(5);
	destructArray(e, 5);

	return true;
}

/** Test the makeDeepCopy fuction
 * @return true. The only way to tell if it succeeds is to look at the output
 */
bool testDeepCopy(){
	struct Employee** e;
	struct Employee** e2;

	printf("Printing first array:\n");
	e = makeRandomArray(2);
	printAllEmployee(e, 2);
	printf("Employee Address: %p\n", *e);
	printf("Array Address: %p\n", e);

	printf("Printing copied array:\n");
	e2 = makeDeepCopy(e, 2);
	printAllEmployee(e2, 2);
	printf("Employee Address: %p\n", *e2);
	printf("Array Address: %p\n", e2);

	return true;
}
