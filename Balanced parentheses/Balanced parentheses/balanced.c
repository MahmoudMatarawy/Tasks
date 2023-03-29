#include "balanced.h"


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
	uint8_t arr[4] = { 0 };
	uint8_t arr_counter = 0;
	for (int counter = min_Chars; counter < max_chars-1; counter++)
	{
		switch (expression[counter])
		{
		case open_curly:
			arr[open_curly_ind]++;
			arr_counter++;
			break;
		case closed_curly:
			arr[closed_curly_ind]++;
			arr_counter++;
			break;
		case open_curved:
			arr[open_curved_ind]++;
			arr_counter++;
			break;
		case closed_curved:
			arr[closed_curved_ind]++;
			arr_counter++;
			break;
		default:
			break;
		}
	}
	if (arr_counter == 0)
		return neither_of_paranthethes_is_used;
	if ((arr[open_curly_ind] == arr[closed_curly_ind]) && (arr[open_curved_ind] == arr[closed_curved_ind]))
		return parentheses_are_balanced;
	else
		return parentheses_are_not_balanced;
}