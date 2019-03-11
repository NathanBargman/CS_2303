/*
 * Tests2.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include <iostream>

using namespace std;

/**
 * Basic Tests2 constructor
 * Receives and outputs nothing
 */
Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}


/**
 * Tests the program
 * @return bool, whether the function ran as expected
 */
bool Tests2::doTests()
{
	bool results;
	//establish a grid
	bool ok1 = Tests2::gridTest();
	//populate it with ants and bugs
	bool ok2 = Tests2::makeOrganismTest();
	//see whether they move
	bool ok3 = Tests2::antsMoveTest();
	//see whether they breed
	bool ok4 = Tests2::antsBreedTest();
	//see whether they die to bugs eating
	bool ok5 = Tests2::antsDieFromDoodleEatTest();
	//see whether they move
	bool ok7 = Tests2::doodleMoveTest();
	//see whether they breed
	bool ok8 = Tests2::doodleBreedTest();
	//see whether they die
	bool ok10 = Tests2::doodleDietest();
	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok7 && ok8 && ok10;
	cout << "Pass? [1 if True, 0 if False] -> " << results << endl;
	return results;
}
/**
 * Tests to make sure the Grid object is working properly
 * @return bool, whether the function runs as expected
 */
bool Tests2::gridTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the grid test" << std::endl;
	Grid* myGrid = new Grid(8);
	if(myGrid->getCellOccupant(2, 3) != empty)
	{
		std::cout << "Cell not initially empty" << std::endl;
		ok1 = false;
	}
	myGrid->setCellOccupant(2, 3, ant, (Ant*)nullptr);
	if(myGrid->getCellOccupant(2, 3) != ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}

	myGrid->~Grid();
	result = ok1 && ok2;
	return result;
}

/**
 * Tests to make sure the ANT and DOODLEBUG initializers are working properly
 * @return bool, whether the function runs as expected
 */
bool Tests2::makeOrganismTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the make organism test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!=empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
		ok1 = false;
	}
	Ant* a1 = new Ant();
	a1->setPos(3, 4, myGrid_p);
	if(myGrid_p->getCellOccupant(3, 4)==empty)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	Doodlebug* d1 = new Doodlebug();
	d1->setPos(3, 4, myGrid_p);
	if(myGrid_p->getCellOccupant(3, 4)!=doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok2 = false;
	}

	myGrid_p->~Grid();
	result = ok1 && ok2;
	return result;
}

/**
 * Tests to make sure the ANT move function is working properly
 * @return bool, whether the function runs as expected
 */
bool Tests2::antsMoveTest()
{

	bool result = false;

	std::cout << "Running the move ants test" << std::endl;
	Grid* myGrid_p = new Grid(9);
	Ant* a1 = new Ant();
	a1->setPos(3, 4, myGrid_p);
	a1->move(myGrid_p);
	if(myGrid_p->getCellOccupant(3, 4) == empty)
	{
		result = true;
	}else{
		std::cout << "Ant doesn't move" << std::endl;
	}
	myGrid_p->~Grid();
	return result;
}

/**
 * Tests to make sure the ANT breed function is working properly
 * @return bool, whether the function runs as expected
 */
bool Tests2::antsBreedTest()
{
	bool result = false;
	std::cout << "Running the breed ants test" << std::endl;
	Grid* myGrid_p = new Grid(2);
	Ant* a1 = new Ant();
	a1->setPos(0, 0, myGrid_p);
	a1->move(myGrid_p);
	a1->move(myGrid_p);
	a1->move(myGrid_p);
	a1->breed(myGrid_p);
	int antCnt = 0;
	for(int r = 0; r < 2; r++){
		for(int c = 0; c < 2; c++){
			if(myGrid_p->getCellOccupant(r, c) == ant)
			{
				antCnt++;
			}
		}
	}

	if(antCnt == 2){
		result = true;
	}
	else{
		std::cout << "Ant doesn't Breed" << std::endl;
	}
	myGrid_p->~Grid();
	return result;
}

/**
 * Tests to make sure the ANT die function is working properly
 * @return bool, whether the function runs as expected
 */
bool Tests2::antsDieFromDoodleEatTest()
{
	bool result = false;
	std::cout << "Running the ants die when bugs eat them test" << std::endl;
	Grid* myGrid_p = new Grid(2);
	Ant* a1 = new Ant();
	a1->setPos(0, 0, myGrid_p);
	Doodlebug* d1 = new Doodlebug();
	d1->setPos(0, 1, myGrid_p);
	d1->eat(myGrid_p);

	if(myGrid_p->getCellOccupant(0,0) == doodlebug)
	{
	result = true;
	}
	else{
		std::cout << "Ant doesn't get eaten" << std::endl;
	}
	myGrid_p->~Grid();
	return result;
}

/**
 * Tests to make sure the Doodle move function is working properly
 * @return bool, whether the function runs as expected
 */
bool Tests2::doodleMoveTest()
{
	bool result = false;
	std::cout << "Running the move doodlebugs test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	Doodlebug* d1 = new Doodlebug();
	d1->setPos(3, 4, myGrid_p);
	d1->move(myGrid_p);
	if(myGrid_p->getCellOccupant(3, 4) == empty)
	{
		result = true;
	}else{
		std::cout << "Doodlebug doesn't move" << std::endl;
	}
	myGrid_p->~Grid();
	return result;
}

/**
 * Tests to make sure the Doodle breed function is working properly
 * @return bool, whether the function runs as expected
 */
bool Tests2::doodleBreedTest()
{
	bool result = false;
	std::cout << "Running the breed doodlebug test" << std::endl;
	Grid* myGrid_p = new Grid(2);
	Doodlebug* d1 = new Doodlebug();
	d1->setPos(0, 0, myGrid_p);
	for(int i = 0; i < 8; i++){
		if(!d1->eat(myGrid_p)){
			d1->move(myGrid_p);
		}
	}
	d1->breed(myGrid_p);
	int dodCnt = 0;
	for(int r = 0; r < 2; r++){
		for(int c = 0; c < 2; c++){
			if(myGrid_p->getCellOccupant(r, c) == doodlebug)
			{
				dodCnt++;
			}
		}
	}

	if(dodCnt == 2){
		result = true;
	}
	else{
		std::cout << "Doodlebug doesn't Breed" << std::endl;
	}
	myGrid_p->~Grid();
	return result;
}

/**
 * Tests to make sure the Doodle die function is working properly
 * @return bool, whether the function runs as expected
 */
bool Tests2::doodleDietest()
{
	bool result = false;
	std::cout << "Running the doodlebug dies test" << std::endl;
	Grid* myGrid_p = new Grid(2);
	Doodlebug* d1 = new Doodlebug();
	d1->setPos(0, 0, myGrid_p);
	for(int i = 0; i < 3; i++){
		if(!d1->eat(myGrid_p)){
			d1->move(myGrid_p);
		}
	}
	d1->die(myGrid_p);
	int dodCnt = 0;
	for(int r = 0; r < 2; r++){
		for(int c = 0; c < 2; c++){
			if(myGrid_p->getCellOccupant(r, c) == doodlebug)
			{
				dodCnt++;
			}
		}
	}

	if(dodCnt == 0){
		result = true;
	}
	else{
		std::cout << "Doodlebug doesn't Die" << std::endl;
	}
	myGrid_p->~Grid();
	return result;
}

/**
 * Destructer
 * Receives and outputs nothing
 */
Tests2::~Tests2() {
}


