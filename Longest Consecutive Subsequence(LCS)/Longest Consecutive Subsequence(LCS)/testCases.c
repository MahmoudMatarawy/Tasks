#include"testCases.h"


void createTestCases(int32_t* test_cases, uint8_t* arraySize)
{
	*(test_cases + 0) = 9;
	*(test_cases + 1) = 0;
	*(test_cases + 2) = 7;
	*(test_cases + 3) = 5;
	*(test_cases + 4) = 3;
	*(test_cases + 5) = 8;
	*(test_cases + 6) = -10;
	*(test_cases + 7) = 4;
	*(test_cases + 8) = 2;
	*(test_cases + 9) = 1;
	arraySize[0] = 10;

	*(test_cases + 60) = 9;
	*(test_cases + 61) = 0;
	*(test_cases + 62) = 7;
	*(test_cases + 63) = 5;
	*(test_cases + 64) = 3;
	*(test_cases + 65) = 8;
	*(test_cases + 66) = -10;
	*(test_cases + 67) = 4;
	*(test_cases + 68) = 2;
	*(test_cases + 69) = 1;
	*(test_cases + 70) = 6;
	*(test_cases + 71) = 12;
	arraySize[2] = 12;

	*(test_cases + 90) = 0;
	*(test_cases + 91) = 1;
	*(test_cases + 92) = 2;
	*(test_cases + 93) = 3;
	*(test_cases + 94) = 4;
	*(test_cases + 95) = 5;
	*(test_cases + 96) = 6;
	*(test_cases + 97) = 7;
	*(test_cases + 98) = 8;
	*(test_cases + 99) = 9;
	arraySize[3] = 10;

	*(test_cases + 120) = 2;
	*(test_cases + 121) = 8;
	*(test_cases + 122) = 4;
	*(test_cases + 123) = 10;
	*(test_cases + 124) = 6;
	*(test_cases + 125) = 20;
	*(test_cases + 126) = 16;
	*(test_cases + 127) = 12;
	*(test_cases + 128) = 14;
	*(test_cases + 129) = 16;
	arraySize[4] = 10;
}