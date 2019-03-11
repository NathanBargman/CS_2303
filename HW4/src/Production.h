/*
 * Production.h
 *
 *  Created on: Feb 13, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include "Grid.h"

class Production {
public:
	Production(int argc, char* argv[]);
	bool runProduction();
	virtual ~Production();
};

#endif /* PRODUCTION_H_ */
