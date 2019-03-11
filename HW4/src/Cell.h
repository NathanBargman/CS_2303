/*
 * Cell.h
 *
 *  Created on: Feb 10, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#ifndef CELL_H_
#define CELL_H_

#include "Ant.h"
#include "Doodlebug.h"



class Cell {
public:
	Cell();
	Cell(Organism* ptr);
	bool setOccupant(occupationStatus g, Organism* ptr);
	occupationStatus getOccupant();
	Organism* getOrg();
	virtual ~Cell();

private:
	Organism* org;
	occupationStatus guest;

};

#endif /* CELL_H_ */
