
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
		for (int i = 0; i < 10; i++)
		{
			ex_u_ch_graph_board[i] = i + 48;
		}
		system("cls");
		setPlayerConfig(ex_u_ch_players_config);
		drawBoard(ex_u_ch_graph_board);
		ex_u_ch_game_state = CONTINUE;
		while (ex_u_ch_game_state == CONTINUE)
		{
			loadAndUpdate((u_ch_player % 2) + 1);
			getGameState(ex_u_ch_graph_board, &ex_u_ch_game_state);
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