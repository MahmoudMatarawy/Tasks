#include "sorting.h"



uint8_t getSmallestIndex(int32_t* array, uint8_t arraySize)
{
	uint8_t index = 0;
	int32_t min = array[0];
 	for (uint8_t counter = 1; counter < arraySize; counter++)
	{
		if (array[counter] < min)
		{
			min = array[counter];
			index = counter;
		}
			
	}
	return index;
}
/*****************************************************************************************/
/*    Function Description    : This function takes a reference to an array of integers 
*								Sorts the array in ascending order
*								Using the insertion sort algorithm*/
/*    Parameter in            : uint8_t arraySize */
/*    Parameter inout         : int32_t* array */
/*    Parameter out           : None */
/*    Return value            : returns -1 if the array is empty
*								returns -2 if the array size is 0 or >10
*								returns 0 if sorting is done without errors */
/*    Requirment              : None */
/*****************************************************************************************/
int8_t insertionSort(int32_t* array, uint8_t arraySize)
{
	int32_t swap = 0;
	uint8_t index = 0;
	if (arraySize == 0)
		return ERR_EMPTY;
	else if (arraySize > 10)
		return ERR_MORE_THAN_10;
	for (uint8_t counter = 0; counter < arraySize-1; counter++)
	{
		index = counter+getSmallestIndex(array+counter , arraySize-counter);
		swap = array[counter];
		array[counter] = array[index];
		array[index] = swap;
	}
	return ERR_OK;

}


/*****************************************************************************************/
/*    Function Description    : This function takes a reference to an array of integers 
*								Prints all array elements */
/*    Parameter in            : int32_t* array 
*								uint8_t arraySize */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : None */
/*    Requirment              : None */
/*****************************************************************************************/
void printArray(int32_t* array, uint8_t arraySize)
{
	printf("\n{");
	for (int counter = 0; counter < arraySize; counter++)
	{
		printf("%d", array[counter]);
		if (counter < arraySize - 1)
			printf(",");
	}
	printf("}\n");
}