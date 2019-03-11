/*
 * Production.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#include "Production.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int gridSize = 20;
int numOfBugs = 5;
int numOfAnts = 100;
int timestepsLeft = 100;
int seed = 1;
int _pause = 0;

/**
 * Constructor for the game controller
 * @param int argc, the length of argv[]
 * @param char* argv[], an array of arguments passed into main
 */
Production::Production(int argc, char* argv[]) {
	// TODO Auto-generated constructor stub
	if(argc >= 1){
		gridSize = atoi(argv[1]);
	}
	if(argc >= 2){
		numOfBugs = atoi(argv[2]);
	}
	if(argc >= 3){
		numOfAnts = atoi(argv[3]);
	}
	if(argc >= 4){
		timestepsLeft = atoi(argv[4]);
	}
	if(argc >= 5){
		seed = atoi(argv[5]);
	}
	if(argc >= 6){
		_pause = atoi(argv[6]);
		_pause = abs(_pause);
	}

	cout << "Grid Size " << gridSize << endl;
	cout << "Number of Bugs " << numOfBugs << endl;
	cout << "Number of Ants " << numOfAnts << endl;
	cout << "Starting Time Steps " << timestepsLeft << endl;
	cout << "Seed " << seed << endl;
	cout << "Pause? " << _pause << endl;

	srand(seed);
}

/**
 * runs the program, i.e. the game control
 * @returns bool, if the game completed
 */
bool Production::runProduction()
{
	int holdTime = timestepsLeft;
	cout << endl << "Production Started" << endl;
	bool result = true;

	int r;
	int c;

	Grid *grid = new Grid(gridSize);
	cout << "Grid Made" << endl;
	Ant antArray[numOfAnts];
	cout << "Ants Made" << endl;
	Doodlebug bugArray[numOfBugs];
	cout << "Bugs Made" << endl;

	// Make Ants and Doodlebugs
	for(int a = 0; a < numOfAnts; a++){

		r = rand() % gridSize;
		c = rand() % gridSize;
		while (grid->getCellOccupant(r, c) != empty){
			r = rand() % gridSize;
			c = rand() % gridSize;
		}
		antArray[a].setPos(r, c, grid);
	}

	for(int b = 0; b < numOfBugs; b++){
		r = rand() % gridSize;
		c = rand() % gridSize;
		while (grid->getCellOccupant(r, c) != empty){
			r = rand() % gridSize;
			c = rand() % gridSize;
		}
		bugArray[b].setPos(r, c, grid);

	}

	int ants = 0;
	int bugs = 0;
	while(timestepsLeft-- > 0)
	{
		//Print Grid each round
		grid->printGrid();
		cout << "Ants: " << ants << " Bugs: " << bugs << endl;

		//pause for keypress or wait 1 sec
		if(_pause == 0){
			usleep(100000);
		}else if(timestepsLeft % _pause == 0){
			cout << "Press Enter to Continue";
			cin.ignore();
		}
		ants = 0;
		bugs = 0;

		//Resolve Doodlebugs
		for(int y = 0; y < gridSize; y++){
			for(int x = 0; x < gridSize; x++){
				if(grid->getCellOccupant(y, x) == doodlebug){
					Doodlebug* fndBug = (Doodlebug*)grid->getCellPointer(y, x);
					if(!(fndBug->visited)){ //Make sure you dont resolve one twice
						if (!(fndBug->eat(grid))){
							fndBug->move(grid);
						}
						fndBug->breed(grid);
						fndBug->die(grid);
						bugs ++;
					}
				}
			}
		}

		//Resolve Ants
		for(int y = 0; y < gridSize; y++){
			for(int x = 0; x < gridSize; x++){
				if(grid->getCellOccupant(y, x) == ant){
					Ant* fndAnt = (Ant*)grid->getCellPointer(y, x);
					if(!(fndAnt->visited)){ //Make sure you dont resolve one twice
						fndAnt->move(grid);
						fndAnt->breed(grid);
						ants ++;
					}
				}
			}
		}

		//Clean ants and bugs so we can resolve them next round.
		for(int y = 0; y < gridSize; y++){
			for(int x = 0; x < gridSize; x++){
				if(grid->getCellOccupant(y, x) == ant || grid->getCellOccupant(y, x) == doodlebug){
					Organism* org = (Organism*)grid->getCellPointer(y, x);
					org->visited = false;

				}
			}
		}

	}
	//Terminate
	cout << endl << endl << "./PA4_nmbargman_jccarroll "<< gridSize << " " << numOfBugs << " " << numOfAnts << " " << holdTime << " " << seed << " " << _pause << endl;
	cout << "Grid Size " << gridSize << endl;
	cout << "Number of Bugs " << numOfBugs << endl;
	cout << "Number of Ants " << numOfAnts << endl;
	cout << "Starting Time Steps " << timestepsLeft << endl;
	cout << "Seed " << seed << endl;
	cout << "Pause? " << _pause << endl;
	cout << "Final Grid" << endl;
	grid->printGrid();
	cout << "Ants: " << ants << " Doodlebugs: " << bugs << endl;
	//Free Grid
	grid->~Grid();
	return result;
}

/**
 * Destructer
 * Receives and outputs nothing
 */
Production::~Production() {
}

