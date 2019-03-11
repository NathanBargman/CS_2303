/*
 * production.c
 *
 *  Created on: Jan 21, 2019
 *      Author: Nathan Bargman
 *      @author Nathan Bargman
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "production.h"
#include <math.h>

/** Your production code goes in this function.
 *
 * @param argc Number of words on the command line
 * @param argv Array of pointers to character strings representing the words on the command line.
 * @return true if Program was able to print a calendar.
 *         false if User entered bad input.
 */

bool production(int argc, char* argv[])
{
	bool results = false;
	bool done = false;
	//get the year, Usage as needed.
	int year = -1;
	puts("CALENDAR");
	if(argc<2)
	{
		puts("Enter a year");
		scanf("%d",&year);
		if(year<1752)
		{
			printf("Usage: Year should be greater than 1751, received %d.\n",year);
			done = true;
		}
	}
	else
	{
		char* ptr=0;
		long year_l = strtol(argv[1],&ptr,10);
		year = (int)year_l;
		if(year<1752)
		{
			printf("Usage: Year should be greater than 1751, received %d.\n",year);
			done = true;
		}
	}
	if(!done)
	{
		char space[] = "  "; //The consistent space between days
		for(int i = 0; i < 12; i++){ //Loop through each month
			if(i != 0){printf("\n%s\n", parse_month(i));} else{ printf("%s\n", parse_month(i));} //Change the month from a number to a char array
			printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"); //Display the days of the week
			for(int w = 0; w < calculate_day_of_week(1, i, year); w++){ //Calculate distance until the first day of the month
				printf("   %s", space); //Create first indent
			}
			for(int d = 1; d < calculate_days_in_month(year, i) + 1; d++){ //Print the numbers for each day in the month
				if(calculate_day_of_week(d, i, year) == 0 && d != 1){ //Go to the next line if we reach the end of the week
					printf("\n");
				}
				if(d < 10){ //If the number is single digits
					printf("  %d", d); //print the number
				}else{ //If the number is double digits
					printf(" %d", d);
				}

				if(calculate_day_of_week(d, i, year) != 6 && d != calculate_days_in_month(year, i)){
					printf("%s", space);
				}
			}
		}
		printf("\n");
	}
	if(!done)
	{
		results=true;
	}
	return results;
}

/** Calculates how many days are in a given month for a given year.
 * @param year The year we are checking.
 * @param month The month we are checking. Range 0 through 11, where January = 0.
 * @return the number of days the months contains.
 */
int calculate_days_in_month(int year, int month)
{
	int ans = -1;
	if(check_if_valid_year(year) && month > -1 && month < 12){ //Make sure the year and move have proper indexes
		if(month == 0 || month == 2 || month == 4 || month == 6 || month == 7|| month == 9 || month == 11){ //See if the month has 31 days
			ans = 31;
		}else if (month == 1){
			if(is_leap_year(year)){ //Is it a February leap year?
				ans = 29;
			}else{
				ans = 28;
			}
		}else{
			ans = 30; //The rest of the months are 30 days
		}
	}
	return(ans);
}

/** Test if a given year is a leap year or not.
 * @param year The year we are testing
 * @return 1 if it is a valid leap year.
 *         0 if a valid year, but not a leap year.
 *        -1 if not a valid year (i.e. before the calendar rule changed in 1752).
 */

int is_leap_year(int year)
{
	int ans = -1; //Start with an invalid answer
	if(check_if_valid_year(year)){ //Check to see if the year is after 1751
		ans = 0;
		if(year % 4 == 0){ //Check to see if the number is divisible by 4
			if(year % 100 != 0 || year % 400 == 0){ //Check to see if the year is divisible by 400 but not 100
				ans = 1;
			}
		}
	}
	return ans;
}
/** Determines what day of the week a particular date falls on.
 * @param day Day of the month, counting from 1.
 * @param month Range 0 through 11, where January = 0.
 * @param year The year.
 * @return -1 for invalid input (e.g., year < 1752, month out of range,
 *            day < 1 or > appropriate for that month & year
 *         0 through 6, where Sunday = 0.
 *
 */
int calculate_day_of_week(int day, //first day of month is 1
						  int month, //uses 0 for January
						  int year){
//invalid input gets a -1 answer
	int ans = -1;
	int shiftedYear = year;
	if(month == 0 || month == 1){ //Subtract 1 from the year if the month is January or February.
		shiftedYear -= 1;
	}
	if(check_if_valid_year(year)){
		//Equation for finding the day of the week.
		ans = ((int)(day + floor(2.6 * shift_month(month) - 0.2) + (shiftedYear % 100) + floor((shiftedYear % 100)/4) + floor(floor(shiftedYear/100.00)/4) - (2 * floor(shiftedYear/100.00)))) % 7;
		if(ans < 0){
			ans += 7;
		}
	}
	return ans;
}
/** If the year is within the constants of this program.
 *  @param year
 *  @returns 0 if the year is before 1752, otherwise 1
 */
int check_if_valid_year(int year){
	if(year < 1752){
		return 0;
	}
	return 1;
}
/** Determines the number of the shifted month (March = 1.... February = 12)
 *  @param month Month of the Year (January = 0)
 *  @returns integer of range of 1 - 12
 */
int shift_month(int month){
	int ans = month;
	ans -= 1;
	if(ans <= 0){
		ans += 12;
	}
	return ans;
}
const char* parse_month(int month){
	static char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	return months[month];
}
