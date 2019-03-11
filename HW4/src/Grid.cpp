/*
 * Grid.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#include <iostream>
#include <cstdlib>
#include "Grid.h"

int n=0; //this initial value will be changed when the program is invoked

/**
 * This is the default constructor
 * @return a grid with a null ptr
 */
Grid::Grid() {
	grid = (Cell**)nullptr;
}

/**
 * Grid Constructor
 * @param the size of 1 side of the grid (it is a square)
 * @return a grid of the given size
 */
Grid::Grid(int nSquaresOnASide)
{
	n = nSquaresOnASide; //initialize size of grid

	grid = new Cell* [n];  //first allocate array of row pointers

	for(int i=0 ; i < n ; i++)
	{
		grid[i] = new Cell[n]; // allocate memory for columns in each row
	}
}

/**
 * Sets the tag of a certain cell to a specific organism
 * @param int r, the given x position
 * @param int c, the given y position
 * @param occupationStatus g, the occupationStatus tag of the organism
 * @return Whether or not the occupant was set
 *
 */
bool Grid::setCellOccupant(int r, int c, occupationStatus g, Organism* ptr)
{
	return grid[r][c].setOccupant(g, ptr);
}

/**
 * Removes an occupant from a cell
 * @param int r, the given x position
 * @param int c, the given y position
 * return Whether or not the occupant was removed
 */
bool Grid::removeCellOccupant(int r, int c)
{
	return grid[r][c].setOccupant(empty, (Organism*)nullptr);
}

/**
 * Gets the occupation status of a cell
 * @param int r, the given x position
 * @param int c, the given y position
 * @return the occupationStatus of the given position
 */
occupationStatus Grid::getCellOccupant(int r, int c)
{
	if(r >= n || c >= n || r < 0 || c < 0){
		return edge;
	}
	return grid[r][c].getOccupant();
}

/**
 * Return the pointer to a cell
 * @param int r, the given x position
 * @param int c, the given y position
 * @return The pointer to the cell on the grid
 */
Organism* Grid::getCellPointer(int r, int c){
	return grid[r][c].getOrg();
}

/**
 * Finds adjacent cell to move into
 * @param int r, The given x position
 * @param in c, The given y position
 * @param occupationStatus g, The occupant of the cell
 * @return 0 if the adjacent cell is above, 1 if the cell is below, 2 if the cell is to the right, and
 * 3 if the cell is to the left.
 */
int Grid::findAdjWithStatus(int r, int c, occupationStatus g){
	int rnd = rand() % 4;
	int rounds = 0;
	//Not perfectly random but close enough for the purposes of the program
	while(rounds < 2){
		if(rnd <= 0 && Grid::getCellOccupant((r + 1), c) == g) //North
		{
			return 0;
		}
		if(rnd <= 1 && Grid::getCellOccupant((r - 1), c) == g) //South
		{
			return 1;
		}
		if(rnd <= 2 && Grid::getCellOccupant(r, (c + 1)) == g) //East
		{
			return 2;
		}
		if(rnd <= 3 && Grid::getCellOccupant(r, (c - 1)) == g) //West
		{
			return 3;
		}
		rounds++;
		rnd = -1;
	}
	return -1;
}

/**
 * Prints the grid, Ants are O, Doodlebugs are X
 */
void Grid::printGrid(){
	for (int i = 0; i < n; i++){
		std::cout << "_";
	}
	std::cout << std::endl;
	for (int r = 0; r < n; r++){
		for (int c = 0; c < n; c++){
			occupationStatus temp = grid[r][c].getOccupant();
			if(temp == empty){
				std::cout << " ";
			}else if (temp == ant){
				std::cout << "O";
			}else if (temp == doodlebug){
				std::cout << "X";
			}else{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

/**
 * Destructer
 * Receives and outputs nothing
 */
Grid::~Grid() {

	for(int r=0; r < n; r++)
	{
		for(int c=0; c < n; c++)
		{
			grid[r][c].~Cell(); // free memory for columns in each row
		}
	}
	grid = (Cell**)nullptr;
}
