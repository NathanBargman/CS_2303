/*
 * mystring.c
 *
 *  Created on: Feb 14, 2019
 *      Author: Nathan Bargman
 */
#include <stdlib.h>
#include "mystring.h"
#include <stdio.h>

/**
 * Calculate the length of the string,
 * excluding the terminating null byte ('\0')
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen1(const char* s)
{
	size_t n = 0;

	// Step through the array, counting up until we find the null terminator
	while (s[n] != '\0') {
		n++;
	}

	return n;
}
/**
 * Calculate the length of the string
 * excluding the terminating null byte ('\0')
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen2(const char* s)
{
	size_t n = 0;

	// Keep incrementing the pointer until we find it is pointing to the null terminator
	while (*s != '\0') {
		n++;
		s++;
	}

	/* Note: This could have been written as:
	 while (*(s++)) n++;
	 */

	return n;
}

/** Duplicates a character string into a freshly-allocated block of memory.
 * @param s The string to duplicate.
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 */
char* mystrdup(char* s) {
	size_t length = strlen(s); // Length of the original string

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(length + 1);
	if (newstr) { // If allocation succeeded, copy into it
		strcpy(newstr, s);
	}
	return newstr;
}

/** Copies the second string into the provided address
 *  @param char* dest, the pointer to the destination for the string
 *  @param char* src, the string to copy
 *  @return char*, a copy of the dest pointer
 */
char* mystrcpy(char* dest, char* src) {
	char *save = dest;
	while(*src != '\0'){ //Copy until we find the terminator
		*dest = *src;
		dest++, src++;
	}
	*dest = '\0';

	return save;
}

/** Copies the second string into the provided address for each index of n
 * 		Ex: If n is 6 then 6 character will be copied. If the string to copy is too short
 * 		the rest of the indexes will be 0. If the string is too long it will be cut off.
 *  @param char* dest, the pointer to the destination for the string
 *  @param char* src, the string to copy
 *  @param size_t n, the amount of character to copy
 *  @return char*, a copy of the dest pointer
 */
char* mystrncpy(char* dest, char* src, size_t n) {
	char *save = dest;
	unsigned i = 0;
	while(*src != '\0' && i < n){ //copy the string until a terminator is reached or until the length is
		*dest = *src;
		src++, dest++, i++;
	}
	while(i < n){ //If there is room left over fill it with 0
		*dest = 0;
		dest++, i++;
	}

	return save;
}

/** Appends the second string into the provided address's string
 *  @param char* dest, the pointer to the first string
 *  @param char* src, the string to append
 *  @return char*, a copy of the dest pointer
 */
char* mystrcat(char* dest, char* src) {
	mystrcpy(dest + mystrlen1(dest), src); //Copy to the end of the dest string
	return dest;
}

/** Appends the second string into the provided address's string, but no more than n character my be appended
 * 		A NULL terminator is added to the end, so the proper size of dest should be the length of the two strings + 1
 *  @param char* dest, the pointer to the first string
 *  @param char* src, the string to append
 *  @param size_t n, the number of character to be appended
 *  @return char*, a copy of the dest pointer
 */
char* mystrncat(char* dest, char* src, size_t n) {
	*(dest + mystrlen1 (dest) + n) = '\0'; //add a null terminator
	mystrncpy (dest + mystrlen1 (dest), src, n); //Copy to the end of the dest string

	return dest;
}
