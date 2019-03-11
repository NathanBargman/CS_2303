/*
 * Grid.h
 *
 *  Created on: Feb 13, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#ifndef GRID_H_
#define GRID_H_

#include "Cell.h"

class Grid {

private:
	Cell** grid;

public:
	Grid();
	Grid(int nSquaresOnASide);
	bool setCellOccupant(int r, int c, occupationStatus g, Organism* ptr);
	bool removeCellOccupant(int r, int c);
	occupationStatus getCellOccupant(int r, int c);
	Organism* getCellPointer(int r, int c);
	int findAdjWithStatus(int r, int c, occupationStatus g);
	void printGrid();
	virtual ~Grid();
};

#endif /* GRID_H_ */
