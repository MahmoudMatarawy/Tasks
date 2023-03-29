
#include"main.h"

//uint8_t stack[30];
ST_stack_t stack;

int main(void)
{

	int8_t var = 0;
	printf("\n\n\t\t Stack app\n");
	// 1. Create an empty stack
	createEmptyStack(&stack);

	// 2. Push 5 different characters to the stack
	for (int counter = 0; counter < 5; counter++)
	{
		printf("Enter Character number %d\n", counter + 1);
		var = _getch();
		push(&stack, var);
	}
	//3. Print all stack data
	var = printStack(&stack);

	//4. Pop one character from the stack
	if (pop(&stack, &var) == ERR_EMPTY)
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
	for (int counter = 0; counter < 7; counter++)
	{
		printf("Enter Character number %d\n", counter + 1);
		var = _getch();
		var = push(&stack, var);
		if (var == ERR_FULL)
			printf("Stack is FULL\n");
	}

	//8. Print the stack's top
	var = stack.top;
	printf("\nStack's top = %d\n\n", var);

	//9. Print all stack data
	var = printStack(&stack);

	//10. Pop 4 characters from the stack
	for (int counter = 0; counter < 4; counter++)
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
	for (int counter = 0; counter < 7; counter++)
	{
		if (pop(&stack, &var) == ERR_EMPTY)
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
	if (var == ERR_EMPTY)
		printf("\nStack is EMPTY\n");

	printf("\n\n\t\t Blanced Parentheses app\n");


	// Check balanced app
	uint8_t test_cases[11][30] = { "{(2+3)}", "{((2+3)}", "[(2+3)]" , "{(2+3)/((3+3)*(15-10))}" ,"(2+3)/((3+3)*(15-10))",\
									"{{2+3)/((3+3)*(15-10)))","{(2+3(/((3+3)*(15-10))}","{(2+3)/((3+3(*)15-10))}",\
									"})2+3)/((3+3)*(15-10))}","{(2+3)/(<3+3>*(15-10))}"};
	uint8_t len = 0;
	var = 0;

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
	//while (1)
	//{
		//system("cls");
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
		//_getch();
	//}
	

	return 0;
}