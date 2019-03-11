/*
 * tests.c
 *
 *  Created on: Nov 3, 2018
 *      Author: Nathan Bargman
 *      @author Nathan Bargman
 */
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include <stdio.h>
#include <stdlib.h>

/** Function to perform tests.
 * @return true if all tests succeed, false if even one fails
 *
 */

bool tests(void)
{
	bool results=false;
	puts("During tests");
	bool ok1 = testIsLeapYear();
	if(ok1)puts("IsLeapYear is ok.");
	bool ok2 = testCalcDaysInMonth();
	if(ok2)puts("days in month is ok.");
	bool ok3 = testCalcDayOfWeek();
	if(ok3)puts("day of week is ok.");
	puts("end of tests");
	results = ok1 && ok2 && ok3;
	return results;
}

/** Tests whether the leap year function works.
 * @param year Year we are testing
 * @return true if all test case pass. False otherwise.
 *
 */
bool testIsLeapYear(void)
{
	bool results = false;
	bool ok1 = false;
	//is_leap_year is supposed to return -1 for years less than 1752
	int ans = is_leap_year(1751);
	if (ans == -1)
	{
		//that test passed
		ok1 = true;
	}
	//is_leap_year is true for 1752
	bool ok2 = false;
	ans = is_leap_year(1752);
	if (ans == 1)
	{
		//that test passed
		ok2 = true;
	}
	//is_leap_year is false for 1753
	bool ok3 = false;
	ans = is_leap_year(1753);
	if (ans == 0)
	{
		//that test passed
		ok3 = true;
	}
	//is_leap_year is true for 2000
	bool ok4 = false;
	ans = is_leap_year(2000);
	if (ans == 1)
	{
		//that test passed
		ok4 = true;
	}
	//is_leap_year is false for 1900
	bool ok5 = false;
	ans = is_leap_year(1900);
	if (ans == 0)
	{
		//that test passed
		ok5 = true;
	}
	results = ok1 && ok2 && ok3 && ok4 && ok5;
	return results;
}
bool testCalcDaysInMonth(void)
{
	bool results = false;
	//we can afford to test exhaustively
	bool ok1 = false;
	if (calculate_days_in_month(1751,-1)==-1)
	{
		//test passed
		ok1 = true;

	}
	bool ok2 = false;
	if (calculate_days_in_month(1751,0)==-1)
	{
		//test passed
		ok2 = true;

	}
	bool ok3 = false;
	if (calculate_days_in_month(1752,-1)==-1)
	{
		//test passed
		ok3 = true;

	}
	bool ok4 = false;
	if (calculate_days_in_month(1752,0)==31)
	{
		//test passed
		ok4 = true;

	}
	bool ok5 = false;
	if (calculate_days_in_month(1752,1)==29)
	{
		//test passed
		ok5 = true;

	}
	bool ok6 = false;
	if (calculate_days_in_month(1752,2)==31)
	{
		//test passed
		ok6 = true;

	}
	bool ok7 = false;
	if (calculate_days_in_month(1752,3)==30)//April
	{
		//test passed
		ok7 = true;

	}
	bool ok8 = false;
	if (calculate_days_in_month(1752,4)==31)//May
	{
		//test passed
		ok8 = true;

	}
	bool ok9 = false;
	if (calculate_days_in_month(1752,5)==30)//June
	{
		//test passed
		ok9 = true;

	}
	bool ok10 = false;
	if (calculate_days_in_month(1752,6)==31)//July
	{
		//test passed
		ok10 = true;

	}
	bool ok11 = false;
	if (calculate_days_in_month(1752,7)==31)//August
	{
		//test passed
		ok11 = true;

	}
	bool ok12 = false;
	if (calculate_days_in_month(1752,8)==30)//September
	{
		//test passed
		ok12 = true;

	}
	bool ok13 = false;
	if (calculate_days_in_month(1752,9)==31)//October
	{
		//test passed
		ok13 = true;


	}
	bool ok14 = false;
	if (calculate_days_in_month(1752,10)==30)//November
	{
		//test passed
		ok14 = true;

	}
	bool ok15 = false;
	if (calculate_days_in_month(1752,11)==31)//December
	{
		//test passed
		ok15 = true;

	}
	bool ok16 = false;
	if (calculate_days_in_month(1753,1)==28)//February, not leap year
	{
		//test passed
		ok16 = true;

	}

	results = ok1&&ok2&&ok3&&ok4&&ok5&&ok6&&ok7&&ok8&&ok9&&ok10&&ok11&&ok12&&ok13&&ok14&&ok15&&ok16;
	return results;
}
bool testCalcDayOfWeek(void)
{
	bool results = false;
	bool ok1 = false;

	//Let's test wikipedia's example
	if(calculate_day_of_week(1,0,2000)==6)//, months go in 0=Jan
	{
		//good
		ok1 = true;
		puts("test 1 works");
	}
	bool ok2 = false;
	//Let's test this year
	//1, 1, 2018
	if(calculate_day_of_week(1,1,2018)==4)//, this is Feb, months go in 0=Jan
	{
		//good
		ok2 = true;
		puts("2018 works");
	}
	bool ok3 = false;
	//Let's test this year
	if(calculate_day_of_week(1,1,2019)==5)//, this is Feb, months go in 0=Jan
	{
		//good
		ok3 = true;
		puts("2019 works");
	}
	bool ok4 = false;
	//Let's test this year
	if(calculate_day_of_week(1,1,2020)==6)//, this is Feb, months go in 0=Jan
	{
		//good
		ok4 = true;
		puts("2020 works");
	}
	results = ok1 && ok2 && ok3 && ok4;

	return results;

}
