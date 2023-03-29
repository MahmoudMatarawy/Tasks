#ifndef _SORTING_H_
#define _SORTING_H_
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int8_t insertionSort(int32_t* array, uint8_t arraySize);
void printArray(int32_t* array, uint8_t arraySize);
/*
Follow the below algorithm to test your algorithm
1. Test Case 1
- Ask the user to enter array elements
- Enter the following elements
- [9, 0, 7, 5, 3, 8, -10, 4, 2, 1]
- Print the array after sorting
2. Test Case 2
- Ask the user to enter array elements
- Press Enter without entering any element
- Print the array after sorting
3. Test Case 3
- Ask the user to enter array elements
- Enter the following elements
- [9, 0, 7, 5, 3, 8, -10, 4, 2, 1, 6, 12]
4. Test Case 4
- Ask the user to enter array elements
- Enter the following elements
- [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
- Print the array after sorting
*/ 


#endif // !_SORTING_H_

