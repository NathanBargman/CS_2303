/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#include "Doodlebug.h"
#include "Grid.h"
#include <cstdlib>
#include <iostream>

/**
 * This is the default constructor
 * It has no parameters and returns nothing
 */
Doodlebug::Doodlebug():Organism(false) {}

/**
 * Constructor of the Doodlebug class
 * @param r, the staring x position
 * @param c, the starting y position
 */
Doodlebug::Doodlebug(int r, int c):Organism(false) {
	row = r;
	col = c;
}

/**
 * This sets the x and y position of the object
 * @param int r, y position
 * @param int c, x position
 * @param Grid* grid, a pointer to the grid
 */
void Doodlebug::setPos(int r, int c, Grid* grid){
	row = r;
	col = c;
	Doodlebug* rtn = this;
	grid->setCellOccupant(r, c, doodlebug, rtn);
}

/*
 * Moves the doodlebug to an ant or up, down, left or right
 * @param Grid* grid, A pointer to the grid
 * @return bool, true if the function ran completely
 */
bool Doodlebug::move(Grid* grid)
{
	Doodlebug* rtn = this;
	int index = grid->findAdjWithStatus(row, col, empty);
	if(index < 0){
		return false;
	}
	grid->removeCellOccupant(row, col);
	switch(index){
	case 0:
		row++;
		break;
	case 1:
		row--;
		break;
	case 2:
		col++;
		break;
	case 3:
		col--;
		break;
	}
	movesteps++;
	hunger++;
	grid->setCellOccupant(row, col, doodlebug, rtn);
	return true;
}

/*
 * Adds an additional doodlebug to the grid in an adjacent position
 * @param Grid* grid, A pointer to the grid
 * @return bool, true if the function ran completely
 */
bool Doodlebug::breed(Grid* grid)
{
	bool status = false;
	int r = row;
	int c = col;
	if(movesteps >= 8){
		int index = grid->findAdjWithStatus(row, col, empty);
		if(index < 0){
			return false;
		}
		switch(index){
		case 0:
			r++;
			break;
		case 1:
			r--;
			break;
		case 2:
			c++;
			break;
		case 3:
			c--;
			break;
		}
		Doodlebug* rtn = new Doodlebug();
		rtn->setPos(r, c, grid);
		grid->setCellOccupant(r, c, doodlebug, rtn);
		movesteps = 0;
		status = true;
	}
	return status;
}

/*
 * If there is an ant in the same position eat it
 * @param Grid* grid, A pointer to the grid
 * @return bool, true if the function ran completely
 */
bool Doodlebug::eat(Grid* grid)
{
	Doodlebug* rtn = this;
	visited = true;
	int index = grid->findAdjWithStatus(row, col, ant);
	if(index < 0){
		return false;
	}
	grid->removeCellOccupant(row, col);
	switch(index){
	case 0:
		row++;
		break;
	case 1:
		row--;
		break;
	case 2:
		col++;
		break;
	case 3:
		col--;
		break;
	}
	movesteps++;
	hunger = 0;
	grid->removeCellOccupant(row, col);
	grid->setCellOccupant(row, col, doodlebug, rtn);
	return true;
}

/**
 * Kills a Doodlebug
 * @param Grid* grid, A pointer to the grid
 * @return Whether or not the Doodlebug died
 */
bool Doodlebug::die(Grid* grid){
	if(hunger >= 3){
		grid->removeCellOccupant(row, col);
		return true;
	}
	return false;
}

/**
 * Destructer
 * Receives and outputs nothing
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

