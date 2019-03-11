/*
 * Doodlebug.h
 *
 *  Created on: Feb 13, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"
class Grid;

class Doodlebug: public Organism {
private:
	int row = 0;
	int col = 0;
	int movesteps = 0;
	int hunger = 0;

public:
	Doodlebug();
	Doodlebug(int r, int c);
	void setPos(int r, int c, Grid* grid);
	bool move(Grid* grid);
	bool breed(Grid* grid);
	bool eat(Grid* grid);
	bool die(Grid* grid);
	virtual ~Doodlebug();
};

#endif /* DOODLEBUG_H_ */
