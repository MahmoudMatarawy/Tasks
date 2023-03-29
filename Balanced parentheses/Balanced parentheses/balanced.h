#ifndef _BALANCED_H_
#define _BLANCED_H_
#include<stdio.h>
#include<stdint.h>



// Balanced Paranthethes Function
#define open_curly_ind 0
#define closed_curly_ind 1
#define open_curved_ind 2
#define closed_curved_ind 3

#define open_curly '{'
#define closed_curly '}'
#define open_curved '('
#define closed_curved ')'

#define min_Chars   0
#define max_chars	10

#define neither_of_paranthethes_is_used -2
#define parentheses_are_not_balanced -1
#define parentheses_are_balanced 0

int8_t isBalancedParanthethes(uint8_t* expression);


#endif // !_BALANCED_H_



