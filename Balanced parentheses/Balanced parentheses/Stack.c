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
	stack->top = STACK_TOP_INIT;
	for (int counter = 0; counter < STACK_SIZE; counter++)
	{
		stack->elements[counter] = STACK_INIT_VALUE;
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
	if (state == ERR_FULL)
		return ERR_FULL;
	else
	{
		stack->top++;
		int8_t stack_top = stack->top;
		stack->elements[stack_top] = data;
		return ERR_OK;
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
	if (state == ERR_EMPTY)
		return ERR_EMPTY;
	else
	{
		//stack->top--;
		int8_t stack_top = stack->top;
		*data = stack->elements[stack_top];
		stack->top--;
		return ERR_OK;
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
	for (int8_t counter = stack->top; counter >= 0; counter--)
	{
		printf("%c\n", stack->elements[counter]);
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
	if (state == ERR_EMPTY)
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
	int8_t stack_top = (stack->top) + 1 ;
	if (stack_top == STACK_SIZE)
		return ERR_FULL;
	return ERR_OK;
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
	int8_t stack_top = stack->top;
	if (stack_top == STACK_TOP_INIT)
		return ERR_EMPTY;
	return ERR_OK ;
}
