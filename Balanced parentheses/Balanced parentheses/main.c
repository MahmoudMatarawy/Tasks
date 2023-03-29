#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_NONSTDC_NO_WARNINGS

#include<stdio.h>
#include <conio.h>
#include<string.h>
#include "Stack.h"
//ST_stack_t stack;
/*int main(void)
{
	
	int8_t var = 0;
	// 1. Create an empty stack
	createEmptyStack(&stack);

	// 2. Push 5 different characters to the stack
	for (int i = 0; i < 5; i++)
	{
		printf("Enter Character number %d\n", i + 1);
		var = _getch();
		push(&stack, var);
	}
	//3. Print all stack data
	var = printStack(&stack);

	//4. Pop one character from the stack
	if (pop(&stack, &var) == -2)
	{
		printf("Stack is EMPTY\n");
	}
	else
	{
		printf("\nPopped up character is %c\n", var);
	}
	
	//5. Print the stack's top
	var = stack.top;
	printf("\nStack's top = %d\n\n", var);

	//6. Print all stack data
	var = printStack(&stack);

	//7. Push another 7 different characters to the stack
	for (int i = 0; i < 7; i++)
	{
		printf("Enter Character number %d\n", i + 1);
		var = _getch();
		var = push(&stack, var);
		if (var == -1)
			printf("Stack is FULL\n");
	}

	//8. Print the stack's top
	var = stack.top;
	printf("\nStack's top = %d\n\n", var);

	//9. Print all stack data
	var = printStack(&stack);

	//10. Pop 4 characters from the stack
	for (int i = 0; i < 4; i++)
	{
		pop(&stack, &var);
		printf("\nPopped up character is %c\n", var);
	}

	//11. Print the stack's top 
	var = stack.top;
	printf("\nStack's top = %d\n\n", var);


	//12. Print all stack data
	var = printStack(&stack);


	//13. Pop 7 more times from the stack
	for (int i = 0; i < 7; i++)
	{
		if (pop(&stack, &var) == -2)
		{
			printf("\nStack is EMPTY\n");
		}
		else
		{
			printf("\nPopped up character is %c\n", var);
		}
	}


	//14. Print the stack's top 
	var = stack.top;
	printf("\nStack's top = %d\n\n", var);


	//15. Print all stack data
	var = printStack(&stack);
	if (var == -2)
		printf("\nStack is EMPTY\n");

	return 0;
}*/


uint8_t stack[30];

// Check balanced app
int main(void)
{
	uint8_t test_cases[11][30] = { "{(2+3)}", "{((2+3)}", "[(2+3)]" , "{(2+3)/((3+3)*(15-10))}" ,"(2+3)/((3+3)*(15-10))",\
									"{{2+3)/((3+3)*(15-10)))","{(2+3(/((3+3)*(15-10))}","{(2+3)/((3+3(*)15-10))}",\
									"})2+3)/((3+3)*(15-10))}","{(2+3)/(<3+3>*(15-10))}"};
	uint8_t len = 0;
	int8_t var = 0;
	while (1)
	{
		system("cls");
		for (int i = 0; i < 10; i++)
		{
			len = strlen(test_cases[i]);
			printf("Test case %d\n", i + 1);
			puts(test_cases[i]);
			if (len > 10)
				printf("Invalid string : More than 10 charcters\n");
			else
			{
				var = isBalancedParanthethes(test_cases[i]);
				switch (var)
				{
				case 0:
					printf("Parentheses are Balanced\n");
					break;
				case -1:
					printf("Parentheses are not balanced\n");
					break;
				case -2:
					printf("Neither of paranthethes is used\n");
					break;
				default:
					break;
				}
			}
			printf("\n\n\n\n");
		}

		/*
		printf("Enter your string \nHint : Max 10 Characters\n");
		gets(stack);
		len = strlen(stack);
		if (len > 10)
			printf("Invalid string : More than 10 charcters\n");
		else
		{
			var = isBalancedParanthethes(stack);
			switch (var)
			{
			case 0 :
				printf("Parentheses are Balanced\n");
				break;
			case -1 :
				printf("Parentheses are not balanced\n");
				break;
			case -2 :
				printf("Neither of paranthethes is used\n");
				break;
			default:
				break;
			}
		}*/
		//printf("%d\n", var);
		_getch();
	}
	

	return 0;
}