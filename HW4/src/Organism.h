/*
 * Organism.h
 *
 *  Created on: Feb 13, 2019
 *      Author: Nathan Bargman and John Carroll
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

enum occupationStatus { empty, ant, doodlebug, edge};


class Organism {
public:
	Organism();
	Organism(bool b);
	bool isPrey();
	void setAmAnt(bool b);
	bool visited = false;
	virtual ~Organism();
};

#endif /* ORGANISM_H_ */
