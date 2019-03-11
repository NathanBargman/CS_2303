/*
 * Ant.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#include "Ant.h"
#include "Grid.h"
#include <cstdlib>
#include <iostream>



using namespace std;
/**
 * This is the default constructor
 * It has no parameters and returns nothing
 */
Ant::Ant():Organism(true){}

/**
 * Constructor of the ANT class
 * @param r, the staring x position
 * @param c, the starting y position
 */
Ant::Ant(int r, int c):Organism(true)
{
	row = r;
	col = c;
}

/**
 * This sets the x and y position of the object
 * @param int r, y position
 * @param int c, x position
 */
void Ant::setPos(int r, int c, Grid* grid){
	row = r;
	col = c;
	Ant* rtn = this;
	grid->setCellOccupant(r, c, ant, rtn);
}

/*
 * Moves the ant up, down, left or right
 * @param Grid* grid, A pointer to the current playing grid
 * @return bool, true if the function ran completely
 */
bool Ant::move(Grid* grid)
{
	Ant* rtn = this;
	visited = true;
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
	grid->setCellOccupant(row, col, ant, rtn);
	return true;
}

/*
 * Adds an additional ANT to the grid in an adjacent position
 * @param Grid *grid, A pointer to the current playing grid
 * @return bool, true if the function ran completely
 */
bool Ant::breed(Grid *grid)
{
	bool status = false;
	int r = row;
	int c = col;
	if(movesteps >= 3){
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
		Ant* rtn = new Ant();
		rtn->setPos(r, c, grid);
		grid->setCellOccupant(r, c, ant, rtn);
		status = true;
		movesteps = 0;
	}
	return status;
}

/**
 * Destructer
 * Receives and outputs nothing
 */
Ant::~Ant() {
}

