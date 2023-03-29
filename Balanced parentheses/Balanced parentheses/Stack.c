#include"Stack.h"


/*****************************************************************************************/
/*    Function Description    : This function takes a reference to a stacks type */
/*								Initialize this stack with Zeros */
/*								Initialize the top with -1*/
/*    Parameter in            : None */
/*    Parameter inout         : ST_stack_t* stack */
/*    Parameter out           : None */
/*    Return value            : None */
/*    Requirment              : None */
/*****************************************************************************************/
void createEmptyStack(ST_stack_t* stack)
{
	stack->top = -1;
	for (int i = 0; i < STACK_SIZE; i++)
	{
		stack->elements[i] = 0;
	}
}



/*****************************************************************************************/
/*    Function Description    : This function takes a reference to the stack and data to store */
/*								Stores the data passed into the stack */
/*    Parameter in            : None */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : returns -1 if the stack is full */
/*								returns 0 otherwise */
/*    Requirment              : None */
/*****************************************************************************************/
int8_t push(ST_stack_t* stack, uint8_t data)
{
	int8_t state = isFull(stack);
	if (state == -1)
		return state;
	else
	{
		stack->top++;
		int8_t i_top = stack->top;
		stack->elements[i_top] = data;
		return state;
	}
	
}



/*****************************************************************************************/
/*    Function Description    : This function takes a reference to the stack */
/*								Stores the data popped from the stack in a data variable */
/*    Parameter in            : None */
/*    Parameter inout         : ST_stack_t* stack */
/*    Parameter out           : uint8_t* data */
/*    Return value            : returns -2 if the stack is empty */
/*								returns 0 otherwise */
/*    Requirment              : None */
/*****************************************************************************************/
int8_t pop(ST_stack_t* stack, uint8_t* data)
{
	int8_t state = isEmpty(stack);
	if (state == -2)
		return state;
	else
	{
		//stack->top--;
		int8_t i_top = stack->top;
		*data = stack->elements[i_top];
		stack->top--;
		return state;
	}
}


/*****************************************************************************************/
/*    Function Description    : This function takes a reference to the stack */
/*								Prints all stack's data starting from the top */
/*    Parameter in            : ST_stack_t* stack */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : returns -1 if the stack is full */
/*								returns -2 if the stack is empty */
/*								returns 0 otherwise */
/*    Requirment              : */
/*****************************************************************************************/
int8_t printStack(ST_stack_t* stack)
{
	int8_t state = 0;
	state = isFull(stack) | isEmpty(stack);
	for (int8_t i = stack->top; i >= 0; i--)
	{
		printf("%c\n", stack->elements[i]);
	}
	return state;
	
}


/*****************************************************************************************/
/*    Function Description    : This function takes a reference to the stack */
/*								Stores its top data into a variable */
/*    Parameter in            : ST_stack_t* stack */
/*    Parameter inout         : None */
/*    Parameter out           : uint8_t* topData */
/*    Return value            : returns -2 if the stack is empty */
/*								returns 0 otherwise */
/*    Requirment              : None */
/*****************************************************************************************/
int8_t getStackTop(ST_stack_t* stack, uint8_t* topData)
{
	int8_t state = isEmpty(stack);
	if (state == -2)
		return state;
	*topData = stack->elements[stack->top];
	return state;
}


/*****************************************************************************************/
/*    Function Description    : This function takes a reference to the stack */
/*								Checks if the stack is full or not */
/*    Parameter in            : ST_stack_t* stack */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : returns -1 if the stack is full */
/*								returns 0 otherwise */
/*    Requirment              : None */
/*****************************************************************************************/
int8_t isFull(ST_stack_t* stack)
{
	int8_t ind = stack->top;
	if (ind + 1 == STACK_SIZE)
		return -1;
	return 0;
}



/*****************************************************************************************/
/*    Function Description    : This function takes a reference to the stack */
/*								Checks if the stack is empty or not */
/*    Parameter in            : ST_stack_t* stack */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : returns -2 if the stack is empty */
/*								returns 0 otherwise */
/*    Requirment              : None */
/*****************************************************************************************/
int8_t isEmpty(ST_stack_t* stack)
{
	int8_t ind = stack->top;
	if (ind == -1)
		return -2;
	return 0 ;
}



/*****************************************************************************************/
/*    Function Description    : This function takes an expression array max 10 characters */
/*								Checks if the parentheses are balanced or not */
/*								Checks the following parentheses types {, }, (, ) only */
/*    Parameter in            : uint8_t* expression */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : returns -2 if the neither of paranthethes is used */
/*								returns -1 if the parentheses are not balanced */
/*								returns 0 if the parentheses are balanced */
/*    Requirment              : None */
/*****************************************************************************************/
int8_t isBalancedParanthethes(uint8_t* expression)
{
	uint8_t arr[4] = {0,0,0,0};
	uint8_t var = 0;
	for (int i = 0; i < 9; i++)
	{
		switch (expression[i])
		{
		case open_curly :
			arr[open_curly_ind]++;
			var++;
			break;
		case closed_curly :
			arr[closed_curly_ind]++;
			var++;
			break;
		case open_curved :
			arr[open_curved_ind]++;
			var++;
			break;
		case closed_curved :
			arr[closed_curved_ind]++;
			var++;
			break;
		default:
			break;
		}
	}
	if (var == 0)
		return -2;
	if ((arr[open_curly_ind] == arr[closed_curly_ind]) && (arr[open_curved_ind] == arr[closed_curved_ind]))
		return 0;
	else
		return -1;
}