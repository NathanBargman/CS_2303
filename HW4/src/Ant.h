/*
 * Ant.h
 *
 *  Created on: Feb 13, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"
class Grid;
class Cell;

class Ant: public Organism {
private:
	int row = 0;
	int col = 0;
	int movesteps = 0;

public:
	Ant();
	Ant(int r, int c);
	void setPos(int r, int c, Grid* grid);
	bool move(Grid* grid);
	bool breed(Grid* grid);
	 ~Ant();
};

#endif /* ANT_H_ */
