#include"lcs.h"
#include"sorting.h"


/*****************************************************************************************/
/*    Function Description    : This function takes a reference to an array,
*								array size,
*								and reference to store the size of the LCS,
*								Using the insertion sort algorithm
*								The function will search for the LCS in the array and
*								stores its size. */
/*    Parameter in            : uint8_t arraySize*/
/*    Parameter inout         : int32_t* array*/
/*    Parameter out           : uint8_t* sizeofLCS */
/*    Return value            : returns -1 if the array is empty
*								returns -2 if the array size is 0 or >10
*								returns -3 if there is no LCS
*								returns 0 otherwise */
/*    Requirment              : None */
/*****************************************************************************************/
int8_t lcsGetSize(int32_t* array, uint8_t arraySize, uint8_t* sizeofLCS)
{
	uint8_t lcs[10];
	uint8_t lcs_index = 0;
	uint8_t max = 0, lcs_counter = 0;
	int8_t state = insertionSort(array, arraySize);
	
	if (state == ERR_EMPTY || state == ERR_MORE_THAN_10)
		return state;
	else {
		for (int counter = 0; counter < arraySize-1; counter++)
		{
			if (array[counter + 1] - array[counter] == 1)
			{
				lcs_counter++;
			}
			else {
				lcs[lcs_index] = lcs_counter;
				lcs_counter = 0;
				lcs_index++;
			}
		}
		if (lcs_index == 0)
		{
			max = lcs_counter;
		}
		for (int counter = 0; counter < lcs_index; counter++)
		{
			if (lcs[counter] > max)
			{
				max = lcs[counter];
			}
		}
		if (max == 0)
		{
			return ERR_no_LCS;
		}
		else
		{
			*sizeofLCS = max +1;
		}
	}
	return ERR_OK;
}