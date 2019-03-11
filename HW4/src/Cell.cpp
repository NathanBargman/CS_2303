/*
 * Cell.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#include "Cell.h"

/**
 * This is the default constructor
 * @return an empty cell object
 */
Cell::Cell() {
	guest = empty;
	org = 0;
}

Cell::Cell(Organism* ptr){
	org = ptr;
	if(org->isPrey()){
		guest = ant;
	}
	else{
		guest = doodlebug;
	}
}

/*
 * Changes the tag of the occupant of the cell
 * @param occupationStatus g, The occupant of the cell
 * @Organism* ptr, A pointer to the organism
 * @return bool, true if the function ran completely
 */
bool Cell::setOccupant(occupationStatus g, Organism* ptr)
{
	bool result = true;
	guest = g;
	org = ptr;
	return result;
}

/*
 * Moves the doodlebug to an ant or up, down, left or right
 * @return occupationStatus, the tag of object in the cell
 */
occupationStatus Cell::getOccupant()
{
	return guest;
}

Organism* Cell::getOrg(){
	return org;
}

/**
 * Destructer
 * Receives and outputs nothing
 */
Cell::~Cell() {
	org = (Organism*)nullptr;
}

