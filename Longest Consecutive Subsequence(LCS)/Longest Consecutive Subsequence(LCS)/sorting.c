#include "sorting.h"



uint8_t getSmallestIndex(int32_t* array, uint8_t arraySize)
{
	uint8_t ind = 0;
	int32_t min = array[0];
	//printf("%d\n", min);
 	for (uint8_t i = 1; i < arraySize; i++)
	{
		//printf("%d\n", min);
		if (array[i] < min)
		{
			min = array[i];
			ind = i;
		}
			
	}
	return ind;
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
	uint8_t ind = 0;
	if (arraySize == 0)
		return -1;
	else if (arraySize > 10)
		return -2;
	for (uint8_t i = 0; i < arraySize-1; i++)
	{
		ind = i+getSmallestIndex(array+i , arraySize-i);
		swap = array[i];
		array[i] = array[ind];
		array[ind] = swap;
	}
	return 0;

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
	for (int i = 0; i < arraySize; i++)
	{
		printf("%d", array[i]);
		if (i < arraySize - 1)
			printf(",");
	}
	printf("}\n");
}