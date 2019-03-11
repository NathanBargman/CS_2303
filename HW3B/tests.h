/*
 * tests.h
 *
 *  Created on: Feb 4, 2019
 *      Author: ciaraldi
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <stdbool.h>
#include "production.h"

// Function prototypes:
bool tests(void);
bool testPrintEmployee(void);
bool testMakeEmployee();
bool testMakeRndAndPrint();
bool testShallowCopy();
bool testDeallocate();
bool testDeepCopy();

#endif /* TESTS_H_ */
