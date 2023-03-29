#ifndef  STACK_H_
#define STACK_H_
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#define STACK_SIZE  10

typedef struct stack {
	uint8_t elements[STACK_SIZE];
	int8_t top;
}ST_stack_t;

// Stack Functions
void createEmptyStack(ST_stack_t* stack);
int8_t push(ST_stack_t* stack, uint8_t data);
int8_t pop(ST_stack_t* stack, uint8_t* data);
int8_t printStack(ST_stack_t* stack);
int8_t getStackTop(ST_stack_t* stack, uint8_t* topData);
int8_t isFull(ST_stack_t* stack);
int8_t isEmpty(ST_stack_t* stack);


// Balanced Paranthethes Function
#define open_curly_ind 0
#define closed_curly_ind 1
#define open_curved_ind 2
#define closed_curved_ind 3

#define open_curly '{'
#define closed_curly '}'
#define open_curved '('
#define closed_curved ')'
int8_t isBalancedParanthethes(uint8_t* expression);



// Test Cases
/*
* Follow the below algorithm to test your stack
1. Create an empty stack
2. Push 5 different characters to the stack
3. Print all stack data
4. Pop one character from the stack
5. Print the stack's top
6. Print all stack data
7. Push another 7 different characters to the stack
8. Print the stack's top
9. Print all stack data
10. Pop 4 characters from the stack
11. Print the stack's top 
12. Print all stack data
13. Pop 7 more times from the stack
14. Print the stack's top 
15. Print all stack data
*/

#endif // ! STACK_H_

