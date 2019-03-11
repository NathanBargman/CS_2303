/*
 * production.c
 *
 *  Created on: Feb 4, 2019
 *      Author: Nathan Bargam
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "production.h"
#include <math.h>
#include <string.h>

/**
 * Production begins the program and initializes the generations
 * @param int argc, the number of arguments in the command line call. Must be greater than 5.
 * @param char* argv[], the array of the passed arguments in the command line call
 * @return True if production completed, False if otherwise
 */
bool production(int argc, char* argv[])
{
	bool results = false;
	bool ok2; //for opening file
	bool done = false;
	int nRows=-1;
	int nCols = -1;
	int gens = 0; //number of generations to play
	int howManyLinesInFile = 0;
	int maximumWidth = 0;
	char filename[100], c;
	for(int i= 0; i<100; i++)
	{
		filename[i]='\0';
	}
	char print = 'n';
	char pause = 'n';
	//etc.
	//get the NR NC gens input [print] [pause], Usage as needed.
	if(argc<5)//not all mandatory args provided
	{
		usage();
		done=true;
	}
	else if (argc >= 7)
	{
		pause = argv[6][0];
	}
	if (!done && (argc >= 6))
	{
		print = argv[5][0];
	}

	if(!done)//must be greater than or equal to 5, so get the mandatory vals
	{

		char* ptr=0;
		long nr_l = strtol(argv[1],&ptr, 10);//get the NR
		nRows = (int)nr_l;
		long nc_l = strtol(argv[2], &ptr, 10);//get the NC
		nCols = (int)nc_l;
		long g_l = strtol(argv[3], &ptr, 10);//get the number of Generations
		gens = (int)g_l;
		if(nRows<1 || nCols<1)
		{
			printf("Usage: Rows and Columns should be greater than 0, received %d and %d.\n", nRows, nCols);
			done = true;
		}
		if(gens<1){
			printf("Usage: The number of Generations should be greater than 0, received %d.\n", gens);
			done = true;
		}

		strcpy(filename, argv[4]);
		//now we have the command line
		//Let's read the input file
		FILE* fp = fopen(filename, "r"); //we try to read it
		if (fp != false)
		{//it opened, yay!
			printf("Opened %s.\n",filename);
			ok2 = true;
			//can we read the data?
			char oRow[100];
			//Let's find out how many lines there are, and
			//find out the maximum width

			bool doneReadingFile = false;
			while(!doneReadingFile)
			{
				oRow[0]='\0';
				fscanf(fp, "%s", oRow);
				if(strlen(oRow)!=0)//there was something there
				{
					howManyLinesInFile++;
					if(strlen(oRow) > maximumWidth){
						maximumWidth = strlen(oRow);
					}
				}
				else
				{
					doneReadingFile = true;
					fclose(fp);
				}
			}

		}//can read filename
		else
		{
			puts("Cannot find that file,");
			done = true;
		}
		if(!done)
		{
			char A[nRows][nCols];
			char B[nRows][nCols];
			char C[nRows][nCols];
			char* old_p=&A[0][0];
			char* new_p=&B[0][0];
			char* other_p=&C[0][0];

			//Initialize arrays
			for(int row = 0; row< nRows; row++)
			{
				for(int col = 0; col<nCols; col++)
				{
					A[row][col] = 0;
					B[row][col] = 0;
					C[row][col] = 0;
				}
			}

			FILE* fp = fopen(filename, "r");//we read it before, we expect we can read it again
			readFileIntoArray(nRows, nCols, howManyLinesInFile,  maximumWidth, old_p, fp);

			int howManyGens = generate(gens,  nRows,  nCols,  old_p, new_p, other_p, print, pause); //begin the game
			printf("Ran %d generations\n", howManyGens);
		}

	}//not done
	results = !done;
	return results;

}
/**
 * PlayOne carries out one generation
 * @param unsigned int nr, the number of rows in the petri dish
 * @param unsigned int nc, the number of columns in the petri dish
 * @param char* Old, the location of the upper left of starting petri dish
 * @param char* New, the location of the upper left of the ending petri dish
 * @return There is none, because results are in New array
 */
void PlayOne (unsigned int nr, unsigned int nc, char* Old, char* New)
{
	int nRows = nr;
	int nCols = nc;
	//loop over all locations in the new dish
	//figure out whether occupied or not
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			//There are three rules,
			// use occupied in old
			//use neighbors in old
			bool occupied = true;
			occupied = 	(getLetter(row,col,nCols, Old)=='x');

			if(occupied
					&&((HowManyNeighbors(row, col, nRows, nCols, Old)<2)
							|| (HowManyNeighbors(row, col, nRows, nCols, Old)>3)))
			{//Death rule
				*(New + (row * nCols) + col)='o';
			}
			else if(occupied)
			{//Survival rule
				*(New + (row * nCols) + col)='x';
			}
			else if(HowManyNeighbors(row, col, nRows, nCols, Old)==3)
			{//Birth rule
				*(New + (row * nCols) + col)='x';

			}
			else
			{
				*(New + (row * nCols) + col)='o';
			}
		}
	}
}

void usage(void)
{
	puts("Usage: HW2 NR NC gens input [print] [pause]");
}

/**
 * getLetter gets the char at the given position in the given array
 * @param int row, row of desired char
 * @param int col, column of desired char
 * @param int nCols, the number of columns in the game
 * @param char* Old, the array to get the character from
 * @return the char at the given position in the given array
 */
char getLetter(int row, int col, int nCols, char* Old)
{
	return *(Old+ (row*nCols)+col);
}

/**
 * HowManyNeighbors is a helper function to find out how many Xs are adjecent
 * @param int row, row of desired char
 * @param int col, column of desired char
 * @param int nRows, the number of rows in the game
 * @param int nCols, the number of columns in the game
 * @param char* Old, the array to compare the character from
 * @return the number of Xs that are next to the given position in any cardinal direction
 */
int HowManyNeighbors(int row, int col, int nRows, int nCols, char* Old)
{
	int howManyN = 0;
	//there could be as many as 8 neighbors
	//cells on an edge or corner have fewer neighbors
	//we will search for neighbors clockwise from NorthWest
	if (row>0)
	{
		if(col>0)
		{
			if(getLetter(row-1, col-1,nCols, Old)=='x')//NW
			{
				howManyN++;
			}
		}
		if(getLetter(row-1, col,nCols, Old)=='x')//N
		{
			howManyN++;
		}
		if(col<(nCols-1))
		{
			if(getLetter(row-1, col+1,nCols, Old)=='x')//NE
			{
				howManyN++;
			}
		}
	}//can look north
	if(col>0)
	{
		if(getLetter(row, col-1,nCols, Old)=='x')//W
		{
			howManyN++;
		}
	}
	if(col<(nCols-1))
	{
		if(getLetter(row, col+1,nCols, Old)=='x')//E
		{
			howManyN++;
		}
	}
	if(row<nRows-1)
	{
		if(col>0)
		{
			if(getLetter(row+1, col-1,nCols, Old)=='x')//SW
			{
				howManyN++;
			}
		}
		if(getLetter(row+1, col,nCols, Old)=='x')//S
		{
			howManyN++;
		}
		if(col<(nCols-1))
		{
			if(getLetter(row+1, col+1,nCols, Old)=='x')//SE
			{
				howManyN++;
			}
		}
	}//can look south

	return howManyN;
}

/**
 * readFileIntoArray turns the file into an array
 * @param int nRows, the number of rows in the game
 * @param int nCols, the number of columns in the game
 * @param int howManyLinesInFile, the number of lines in the original file
 * @param int maximumWidth, the number of characters long the original file
 * @param char* ar_p, the array to put the characters from the file into
 * @param FILE* fp, the file designated as the starting game board
 */
void readFileIntoArray(int nRows, int nCols, int howManyLinesInFile, int maximumWidth, char* ar_p, FILE* fp)
{
	//Initialize the array
	for(int row = 0; row< nRows; row++)
	{
		for(int col = 0; col<nCols; col++)
		{
			*(ar_p+(row*nCols)+col) = 'o';

		}
	}

	//Insert Xs
	for(int frow=0; frow< howManyLinesInFile; frow++)
	{
		char fromFile[maximumWidth];

		for(int i = 0; i<maximumWidth; i++)
		{
			fromFile[i]='o';
		}
		fscanf(fp, "%s", fromFile);
		for(int fcol=0; fcol<maximumWidth; fcol++)
		{
			if(fromFile[fcol]=='x')
			{
				int targetRow = frow+(nRows-howManyLinesInFile)/2;
				int targetCol = fcol+(nCols-maximumWidth)/2;
				*(ar_p+(targetRow*nCols)+targetCol) = 'x';
			}
		}
	}
	printThis(nRows, nCols, ar_p);
}

/**
 * generate runs the game for the designated amount of rounds and checks if the game should end
 * @param int gens, the number rounds the game will try and run for
 * @param int nRows, the number of rows in the game
 * @param int nCols, the number of columns in the game
 * @param char* old_p, the pointer to the old array
 * @param char* new_p, the pointer to the new array
 * @param char* other_p, the pointer to the third array
 * @param char print, character to decide if the game should print after each generation ('y' for yes, 'n' for no)
 * @param char pause, character to decide of the game should pause after each generation ('y' for yes, 'n' for no)
 * @return the number of rounds the game ran
 */
int generate(int gens,  int nRows,  int nCols,  char* old_p, char* new_p, char* other_p, char print, char pause)
{
	int g = 0;
	bool allOrganismsDead = false;
	bool patternRepeated = false;
	bool done = false;
	bool firstTime = true;

	for(int gensDone = 0; !done && (gensDone<gens); gensDone++)
	{
		if(!anyX(old_p, nRows, nCols))
		{//all organisms are dead
			done = true;
			puts("All organisms dead.");
			printThis(nRows, nCols, old_p);
		}
		if(!done){
			PlayOne(nRows, nCols, old_p, new_p);
			g++;
			if(sameContent(new_p, old_p, nRows, nCols))
			{//see if this generation was the same as the last
				done = true;
				puts("Pattern repeated in one generation.");
				printThis(nRows, nCols, old_p);
			}
			if(firstTime)
			{
				firstTime = false;
			}
			else
			{
				if(sameContent(new_p, other_p, nRows, nCols))
				{//see if the generation after last was the same as the new one
					puts("Pattern repeated after two generations.");
					printThis(nRows, nCols, other_p);
					done= true;
				}
			}
		}
		if(!done)
		{
			if(print=='y')
			{
				puts("New generation");
				printThis(nRows, nCols, new_p);
			}
			if(pause=='y')
			{
				puts("Paused waiting for input.");
				getc(stdin);//just waits for user input
			}
			//swap pointers
			swapPntr(&other_p, &old_p, &new_p);
		}


	}//end of generations

	return g;
}

/**
 * swapPntr plays musical chairs with the pointers to continue the game and swap the arrays A, B and C
 * @param char** other_p, the pointer to the array pointer controlling the game
 * @param char** old_p, the pointer to the array pointer controlling the game
 * @param char** new_p, the pointer to the array pointer controlling the game
 */
void swapPntr(char** other_p, char** old_p, char** new_p){
	char *temp = *other_p;
	*other_p = *old_p;
	*old_p = *new_p;
	*new_p = temp;
	return;
}

/**
 * anyX is a helper function to find out if the array has any X chars
 * @param int nRows, the number of rows in the game
 * @param int nCols, the number of columns in the game
 * @param char* arr, the pointer to the target array
 * @return True if the array contains 'x' False if not
 */
bool anyX(char* arr, int nRows, int nCols)
{
	bool any = false;
	for(int row=0; !any && (row<nRows); row++)
	{
		for(int col=0; !any && (col< nCols); col++)
		{
			if(*(((char*) arr) + (row * nCols) + col) == 'x') //check to see if there are any 'x's
			{
				any=true;
			}
		}
	}
	return any;
}

/**
 * sameContent is a helper function that compares two arrays
 * @param int nRows, the number of rows in the game
 * @param int nCols, the number of columns in the game
 * @param char* one_p, the pointer to the first target array
 * @param char* another_p, the pointer to the second target array
 * @return True if the arrays are identical, False if otherwise
 */
bool sameContent(char* one_p, char* another_p, int nRows, int nCols)
{
	bool same = true; //for all the comparisons that have been made so far

	for(int row=0; same && (row<nRows); row++)
	{
		for(int col=0; same && (col< nCols); col++)
		{
			if(getLetter(row, col, nCols, one_p) != getLetter(row, col, nCols, another_p))
			{
				same=false;
			}
		}
	}
	return same;

}

/**
 * printThis prints an array
 * @param int nRows, the number of rows in the game
 * @param int nCols, the number of columns in the game
 * @param char* old_p, the pointer to the target array
 */
void printThis(int nRows, int nCols, char* old_p)
{
	for(int row=0;row<nRows;row++)
	{
		for(int col=0;col<nCols;col++)
		{
			if(getLetter(row, col, nCols, old_p) == 'x'){
				printf("x"); //print the 'x's
			}else{
				printf(" "); //empty space if there is an 'o'
			}
		}
		printf("\n");
	}
}
