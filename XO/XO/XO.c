#include"XO.h"

unsigned char ex_u_ch_graph_board[10];
unsigned char ex_u_ch_players_config[2];
/*****************************************************************************************/
/*    Function Description    : This function will take a board as an input and prints it on the console */
/*    Parameter in            : uint8_t* board */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : None */
/*    Requirment              : None */
/*****************************************************************************************/
void drawBoard(uint8_t* board)
{
	system("cls");
	printf("\t\t    XO Game\n\n");
	printf("\t  Player 1 (%c)  -  Player 2 (%c)\n\n\n", ex_u_ch_players_config[player_one] , ex_u_ch_players_config[player_two]);
	printf("\t\t     |     |     \n");
	printf("\t\t  %c  |  %c  |  %c \n", board[1], board[2], board[3]);
	printf("\t\t_____|_____|_____\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  %c  |  %c  |  %c \n", board[4], board[5], board[6]);
	printf("\t\t_____|_____|_____\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  %c  |  %c  |  %c \n", board[7], board[8], board[9]);
	printf("\t\t     |     |     \n\n");
}

/*****************************************************************************************/
/*    Function Description    : This function will take the board, position to update and value to set in this position */
/*    Parameter in            : uint8_t* board */
/*							    uint8_t position (Range 1:9) */
/*								uint8_t value (Range X|O) */		
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : None */
/*    Requirment              : None */
/*****************************************************************************************/
void updateBoard(uint8_t* board, uint8_t position, uint8_t value)
{
	board[position] = value;
	drawBoard(board);
}

/*****************************************************************************************/
/*    Function Description    : This function will take the player's number and asks the player to choose between X and O */
/*    Parameter in            : uint8_t playerNumber (Range 1|2) */
/*								uint8_t* symbol (Range X|O) */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : return 0 when the input symbol is not wrong and/or was not chosen before */
/*								return 1 when the input symbol is wrong and/or was chosen before */
/*    Requirment              : None */
/*****************************************************************************************/
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol)
{
	unsigned char u_ch_p_symbol = 0;
	unsigned char u_ch_choosen = 0;
	unsigned char u_ch_ret = 0;
	printf("\nPlayer %d, Please Enter your preferred symbol X or O\n", playerNumber + 1);
	//scanf("%c", &u_ch_p_symbol);
	u_ch_p_symbol = _getch();
	if (playerNumber == player_two)
	{
		u_ch_choosen = ex_u_ch_players_config[player_one];
		if (u_ch_p_symbol == u_ch_choosen || u_ch_p_symbol == (u_ch_choosen + 32))
		{
			printf("\nChoosen symbol, Please try again\n");
			u_ch_ret = 1;
		}
		else {
			switch (u_ch_p_symbol)
			{
			case 'x':
				*symbol = 'X';
				u_ch_ret = 0;
				break;
			case 'X':
				*symbol = 'X';
				u_ch_ret = 0;
				break;
			case 'o':
				*symbol = 'O';
				u_ch_ret = 0;
				break;
			case 'O':
				*symbol = 'O';
				u_ch_ret = 0;
				break;
			default:
				printf("Wrong symbol please try again\n");
				u_ch_ret = 1;
				break;
			}
		}
	}
	else {
		switch (u_ch_p_symbol)
		{
		case 'x':
			*symbol = 'X';
			u_ch_ret = 0;
			break;
		case 'X':
			*symbol = 'X';
			u_ch_ret = 0;
			break;
		case 'o':
			*symbol = 'O';
			u_ch_ret = 0;
			break;
		case 'O':
			*symbol = 'O';
			u_ch_ret = 0;
			break;
		default:
			printf("Wrong symbol please try again\n");
			u_ch_ret = 1;
			break;
		}
	}
	return u_ch_ret;
}

/*****************************************************************************************/
/*    Function Description    : This function will prompt and asks each user about their preferred symbols and saves it in the configArray */
/*    Parameter in            : None */
/*    Parameter inout         : uint8_t* configArray  */
/*    Parameter out           : None */
/*    Return value            : None */
/*    Requirment              : None */
/*****************************************************************************************/
void setPlayerConfig(uint8_t* configArray)
{
	
	unsigned char u_ch_pl_1_st = 1;
	unsigned char u_ch_pl_2_st = 1;
	while (u_ch_pl_1_st)
	{
		u_ch_pl_1_st = getPlayerSymbol(player_one, &configArray[player_one]);
	}
	while (u_ch_pl_2_st)
	{
		u_ch_pl_2_st = getPlayerSymbol(player_two , &configArray[player_two]);
	}
}

/*****************************************************************************************/
/*    Function Description    : This function will take the player's number then load his config, ask him for the position then updates the board */
/*    Parameter in            : uint8_t playerNumber */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : None */
/*    Requirment              : None */
/*****************************************************************************************/
void loadAndUpdate(uint8_t playerNumber)
{
	unsigned char u_ch_p_symbol = 0;
	unsigned int u_i_position = 0;
	unsigned char u_ch_st = 1;
	switch (playerNumber)
	{
	case player_one+1:
		u_ch_p_symbol = ex_u_ch_players_config[player_one];
		break;
	case player_two+1:
		u_ch_p_symbol = ex_u_ch_players_config[player_two];
		break;
	default:
		break;
	}
	while (u_ch_st)
	{
		printf("\nPlayer %d Choose your position from 1 to 9 \n",playerNumber);
		scanf("%d", &u_i_position);
		if (u_i_position >= 1 && u_i_position <= 9)
		{
			u_ch_st = 0;
		}
		else
		{
			printf("Invalid position, Please try again\n");
		}
	}
	//printf("Test : Player_num = %d , Position = %d , Symbol = %c", playerNumber ,u_i_position, u_ch_p_symbol);
	updateBoard(ex_u_ch_graph_board, u_i_position, u_ch_p_symbol);
}

/*****************************************************************************************/
/*    Function Description    : This function will check after each move if there is a win, draw or continue playing */
/*    Parameter in            : uint8_t* board */
/*    Parameter inout         : uint8_t* gameState */
/*								Returns 0 for winning */
/*								Returns 1 for a draw */
/*								Returns 2 to continue */
/*    Parameter out           : None */
/*    Return value            : None */
/*    Requirment              : None */
/*****************************************************************************************/
void getGameState(uint8_t* board, uint8_t* gameState)
{
	if (ex_u_ch_graph_board[1] == ex_u_ch_graph_board[2] && ex_u_ch_graph_board[2] == ex_u_ch_graph_board[3])
		*gameState = WIN;
	else if (ex_u_ch_graph_board[4] == ex_u_ch_graph_board[5] && ex_u_ch_graph_board[5] == ex_u_ch_graph_board[6])
		*gameState = WIN;
	else if (ex_u_ch_graph_board[7] == ex_u_ch_graph_board[8] && ex_u_ch_graph_board[8] == ex_u_ch_graph_board[9])
		*gameState = WIN;
	else if (ex_u_ch_graph_board[1] == ex_u_ch_graph_board[4] && ex_u_ch_graph_board[4] == ex_u_ch_graph_board[7])
		*gameState = WIN;
	else if (ex_u_ch_graph_board[2] == ex_u_ch_graph_board[5] && ex_u_ch_graph_board[5] == ex_u_ch_graph_board[8])
		*gameState = WIN;
	else if (ex_u_ch_graph_board[3] == ex_u_ch_graph_board[6] && ex_u_ch_graph_board[6] == ex_u_ch_graph_board[9])
		*gameState = WIN;
	else if (ex_u_ch_graph_board[1] == ex_u_ch_graph_board[5] && ex_u_ch_graph_board[5] == ex_u_ch_graph_board[9])
		*gameState = WIN;
	else if (ex_u_ch_graph_board[3] == ex_u_ch_graph_board[5] && ex_u_ch_graph_board[5] == ex_u_ch_graph_board[7])
		*gameState = WIN;
	else if (ex_u_ch_graph_board[1] != '1' && ex_u_ch_graph_board[2] != '2' && ex_u_ch_graph_board[3] != '3' && ex_u_ch_graph_board[4] != '4'\
		&& ex_u_ch_graph_board[5] != '5' && ex_u_ch_graph_board[6] != '6' && ex_u_ch_graph_board[7] != '7' && ex_u_ch_graph_board[8] != '8'\
		&& ex_u_ch_graph_board[9] != '9')
		*gameState = DRAW;
	else
	{
		*gameState = CONTINUE;
	}
}

/*****************************************************************************************/
/*    Function Description    : */
/*    Parameter in            : */
/*    Parameter inout         : */
/*    Parameter out           : */
/*    Return value            : */
/*    Requirment              : */
/*****************************************************************************************/