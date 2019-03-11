/** mystruct.c
 * @author Mike Ciaraldi
*/


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mystruct.h"

/** Creates an employ with random values between 1919 and 2019 and a random string of length 3 - 20
 * @return the pointer to the above Employee
 */
struct Employee *makerndEmployee(){
	return makeEmployee(rndint(1919, 2019), rndint(1919, 2019), rndstr(rndint(3, 20)));
}

/** Creates a random string made of letters a - z starting with an upper case letter A - Z
 * @param length, the size of the string to be created
 * @return the created string
 */
char* rndstr(size_t length){
	static char* ucharSet = "QWERTYUIOPLKJHGFDSAZXCVBNM";
	static char* charSet = "qwertyuioplkjhgfdsazxcvbnm";

	char* rndString;
	if(length){
		rndString = malloc(length + 1); //Allocate space for the string
		int max = (strlen(charSet) - 1);
		int num;
		num = rand()% max;
		*rndString = *(ucharSet + num); //Set the fist letter to an Uppercase
		for(int i = 1; i < length; i++){
			num = rand() % max;
			*(rndString + i) = *(charSet + num); //Add a letter
		}
	}
	return rndString;

}

/** Creates a random integer between MIN and MAX
 * @param MIN (Inclusive)
 * @param MAX (Exclusive)
 * @return a random Integer
 */
int rndint(int MIN, int MAX){

	return (rand()%(MAX-MIN)) + MIN;
}

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the employee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee* rtn; //Create a new pointer
	rtn = (struct Employee *)malloc(sizeof(struct Employee)); //Allocate space for the struct
	strcpy(rtn->name, name); //copy the name over
	rtn->birth_year = birth;
	rtn->start_year = start;
	return rtn;
}

/** Prints the given Employee in the following format
 * 	"Requested Employee is [name], born [birth_year], started working [start_year]"
 * @param e, a pointer to the Employee to print
 */
void printEmployee(struct Employee *e) {
	printf("Requested Employee is %s, born %d, started working %d\n", e->name, e->birth_year, e->start_year);
}

/** Creates and array of pointers to random Employee
 * @param n, the size of the array to be made
 * @return a pointer to the created array
 */
struct Employee** makeRandomArray(size_t n){
	struct Employee** rtn; //Make a new array pointer
	struct Employee** start;
	rtn = (struct Employee **)malloc(sizeof(struct Employee*) * n); //Allocate space for the array
	start = rtn;
	for (int i = 0; i < n; i++){
		*(start +  i) = makerndEmployee();
		//Set each pointer to a random new Employee pointer
	}
	return rtn;
}

/**	Prints all Employee in the given array
 * @param arr, the array to print
 * @param n, the size of the array to print
 */
void printAllEmployee(struct Employee** arr, size_t n){
	for(int i = 0; i < n; i++){
		printEmployee(*(arr + i)); //print each pointer in the array
	}
}

/** Creates a new array that is a shallow copy
 * @param arr, the array to create the copy of
 * @param n, length of the array
 * @return a pointer to the new array
 */
struct Employee** makeShallowCopy(struct Employee** arr, size_t n){
	struct Employee** rtn; //Make new array
	struct Employee** start;
	rtn = (struct Employee **)malloc(sizeof(struct Employee*) * n); //Allocate memory
	start = rtn;
	for (int i = 0; i < n; i++){
		*(start + i) = *(arr + i);
		//Set the pointers in our new array to values of the pointers of the ones we want to copy
	}
	return rtn;
}

/** Frees the given array from memory
 * @param arr, the array to free
 * @param n, the size of the array
 */
void destructArray(struct Employee** arr, size_t n){
	for(int i = 0; i < n; i++){
		free(*(arr + i)); //Free the allocated spots for Employee
	}
	free(arr); //Free the allocated spot for the array
}

/** Makes a deep copy of the given array
 * @param arr, the array to copy
 * @param n, the size of the array
 * @return a deep copy with all new pointers and adresses!!
 */
struct Employee** makeDeepCopy(struct Employee** arr, size_t n){
	struct Employee** rtn; //Make a new array
	struct Employee** start;
	rtn = (struct Employee **)malloc(sizeof(struct Employee*) * n); //allocate memory
	start = rtn;
	for (int i = 0; i < n; i++){
		*(start + i) = makeEmployee((*(arr + i))->birth_year, (*(arr + i))->start_year, (*(arr + i))->name);
		//set the consecutive pointers of our new array to new Employee with the values of the ones we what to copy
	}
	return rtn;
}
