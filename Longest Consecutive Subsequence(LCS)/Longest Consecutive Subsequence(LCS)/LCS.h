#ifndef _LCS_H_
#define _LCS_H_
#include<stdint.h>
#include<stdio.h>



#define ERR_no_LCS -3

int8_t lcsGetSize(int32_t* array, uint8_t arraySize, uint8_t* sizeofLCS);

/*
Follow the below algorithm to test your algorithm
1. Test Case 1
- Ask the user to enter array elements
- Enter the following elements
- [9, 0, 7, 5, 3, 8, -10, 4, 2, 1]
- Print the LCS size
2. Test Case 2
- Ask the user to enter array elements
- Press Enter without entering any element
3. Test Case 3
- Ask the user to enter array elements
- Enter the following elements
- [9, 0, 7, 5, 3, 8, -10, 4, 2, 1, 6, 12]
4. Test Case 4
- Ask the user to enter array elements
- Enter the following elements
- [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
- Print the LCS size
5. Test Case 5
- Ask the user to enter array elements
- Enter the following elements
- [2, 8, 4, 10, 6, 20, 16, 12, 14, 16]

*/

#endif // !_LCS_H_

