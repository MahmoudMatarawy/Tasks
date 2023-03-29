#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include "sorting.h"
#include "testCases.h"
#include "LCS.h"
int32_t test_cases[5][30];
uint8_t arraySize[5];
int32_t string[] = {5,1,2,6,4,3};
int main(void)
{
	int state = 0;
	uint8_t lcs = 0;
	createTestCases(test_cases, arraySize);
	printf("\t\t Insertion Sort\n");
	for (int i = 0; i < 4; i++)
	{
		printf("\n\nTest case %d\n", i+1);
		printf("\nInitial array is ");
		printArray(test_cases[i], arraySize[i]);
		state = insertionSort(test_cases[i], arraySize[i]);
		if (state == 0)
		{
			printf("\nSorted array is");
			printArray(test_cases[i], arraySize[i]);
		}
		else if (state == -1)
			printf("\nEmpty array\n\n\n");
		else
			printf("\nArray size is more than 10\n\n\n");
	}


	createTestCases(test_cases, arraySize);
	state = 0;
	printf("\n\n\n\n\n\t The Longest Consecutive Subsequence(LCS)\n\n");
	for (int i = 0; i < 5; i++)
	{
		printf("\n\nTest case %d\n", i + 1);
		printf("\nInitial array is ");
		printArray(test_cases[i], arraySize[i]);
		state = lcsGetSize(test_cases[i], arraySize[i], &lcs);
		printf("\nSorted array is");
		printArray(test_cases[i], arraySize[i]);
		if (state == 0)
		{
			printf("\nThe Longest Consecutive Subsequence(LCS) is %d\n\n\n", lcs);
		}
		else if (state == -1)
			printf("\nEmpty array\n\n\n");
		else if (state == -2)
			printf("\nArray size is more than 10\n\n\n");
		else
			printf("\nthere is no LCS\n\n\n");
	}
	return 0;
}