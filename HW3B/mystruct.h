/** mystruct.h
 * @author Mike Ciaraldi
 * Sample structs
*/

#include <stddef.h>
#include <stdbool.h>


// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employee started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makerndEmployee();
char* rndstr(size_t length);
int rndint(int MIN, int MAX);
struct Employee *makeEmployee(int birth, int start, const char* name);
struct Employee** makeRandomArray(size_t n);
void printAllEmployee(struct Employee** arr, size_t n);
void printEmployee(struct Employee *e);

struct Employee** makeShallowCopy(struct Employee** arr, size_t n);
void destructArray(struct Employee** arr, size_t n);
struct Employee** makeDeepCopy(struct Employee** arr, size_t n);


