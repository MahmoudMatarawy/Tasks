#include"LCS.h"
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
	uint8_t lcs_ind = 0;
	uint8_t var1 = 0, var = 0;
	int8_t state = insertionSort(array, arraySize);
	
	if (state == -1 || state == -2)
		return state;
	else {
		//printf("\nArray size = %d\n", arraySize);
		//printArray(array, arraySize);
		for (int i = 0; i < arraySize-1; i++)
		{
			if (array[i + 1] - array[i] == 1)
			{
				var++;
			}
			else {
				lcs[lcs_ind] = var;
				var = 0;
				lcs_ind++;
			}
		}
		if (lcs_ind == 0)
		{
			var1 = var;
		}
		for (int i = 0; i < lcs_ind; i++)
		{
			if (lcs[i] > var1)
			{
				var1 = lcs[i];
			}
		}
		if (var1 == 0)
		{
			return -3;
		}
		else
		{
			*sizeofLCS = var1 +1;
		}
	}
	return 0;
}