

#include "main.h"


int32_t test_cases[5][30];
uint8_t arraySize[5];
int main(void)
{
	int state = 0;
	uint8_t lcs = 0;
	createTestCases(test_cases, arraySize);
	printf("\t\t Insertion Sort\n");
	for (int counter = 0; counter < 4; counter++)
	{
		printf("\n\nTest case %d\n", counter+1);
		printf("\nInitial array is ");
		printArray(test_cases[counter], arraySize[counter]);
		state = insertionSort(test_cases[counter], arraySize[counter]);
		if (state == ERR_OK)
		{
			printf("\nSorted array is");
			printArray(test_cases[counter], arraySize[counter]);
		}
		else if (state == ERR_EMPTY)
			printf("\nEmpty array\n\n\n");
		else
			printf("\nArray size is more than 10\n\n\n");
	}


	createTestCases(test_cases, arraySize);
	state = 0;
	printf("\n\n\n\n\n\t The Longest Consecutive Subsequence(LCS)\n\n");
	for (int counter = 0; counter < 5; counter++)
	{
		printf("\n\nTest case %d\n", counter + 1);
		printf("\nInitial array is ");
		printArray(test_cases[counter], arraySize[counter]);
		state = lcsGetSize(test_cases[counter], arraySize[counter], &lcs);
		printf("\nSorted array is");
		printArray(test_cases[counter], arraySize[counter]);
		if (state == ERR_OK)
		{
			printf("\nThe Longest Consecutive Subsequence(LCS) is %d\n\n\n", lcs);
		}
		else if (state == ERR_EMPTY)
			printf("\nEmpty array\n\n\n");
		else if (state == ERR_MORE_THAN_10)
			printf("\nArray size is more than 10\n\n\n");
		else
			printf("\nthere is no LCS\n\n\n");
	}
	return 0;
}