
#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_NONSTDC_NO_WARNINGS
#include<stdio.h>
#include"XO.h"




extern unsigned char ex_u_ch_graph_board[10];
extern unsigned char ex_u_ch_players_config[2];


int main(void)
{
	unsigned char ex_u_ch_game_state = CONTINUE;
	unsigned char u_ch_player = 0;
	while (1)
	{
		// Initiate the board with positions number
		for (int i = 0; i < 10; i++)
		{
			ex_u_ch_graph_board[i] = i + 48;
		}

		// Clear Terminal
		system("cls");

		// Take the symbols and set player's config
		setPlayerConfig(ex_u_ch_players_config);

		// Draw the board on the Terminal
		drawBoard(ex_u_ch_graph_board);

		// Set the Game state as Continue
		ex_u_ch_game_state = CONTINUE;

		// loop till the game finished
		while (ex_u_ch_game_state == CONTINUE)
		{
			// Take the symbols and update the board
			loadAndUpdate((u_ch_player % 2) + 1);

			// Check the game state if WIN , DRAW or COUNTINUE
			getGameState(ex_u_ch_graph_board, &ex_u_ch_game_state);

			// Switch on game state
			switch (ex_u_ch_game_state)
			{
			case WIN :
				printf("\nPlayer %d WON\n", (u_ch_player % 2) + 1);
				break;
			case DRAW :
				printf("\nDRAW\n");
				break;
			default:
				break;
			}
			u_ch_player++;
		}
		u_ch_player = 0;
		_getch();
	}
	return 0;
}