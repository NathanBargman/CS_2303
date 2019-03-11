/*
 * Organism.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#include "Organism.h"
bool amAnt = false;

/**
 * This is the default constructor
 * It has no parameters and returns nothing
 */
Organism::Organism() {
	// TODO Auto-generated constructor stub
}

/**
 * Constructor
 * @param bool b, if the organism is an ant or not
 * @return an organism with the requested value
 */
Organism::Organism(bool b) {
	amAnt = b;

}

/**
 * Checks to see if this object is an ANT (does not check to see if this is an actual ANT object)
 * @return bool, true if it is an ANT otherwise false
 */
bool Organism::isPrey()
{
	return amAnt;
}

/**
 * Sets this object to an ANT or not an ANT (not an ant object)
 * @param bool b, the desired condition
 */
void Organism::setAmAnt(bool b)
{
	amAnt = b;
}

/**
 * Destructer
 * Receives and outputs nothing
 */
Organism::~Organism() {
}

