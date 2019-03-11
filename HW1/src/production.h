/*
 * production.h
 *
 *  Created on: Nov 3, 2018
 *      Author: Nathan Bargman
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
bool production(int argc, char* argv[]);
int calculate_days_in_month(int year, int month);
int is_leap_year(int year);
int calculate_day_of_week(int day, //first day of month is 1
		int month, //uses 0 for January
		int year);
int check_if_valid_year(int year);
int shift_month(int month);
const char* parse_month(int month);
#endif /* PRODUCTION_H_ */
