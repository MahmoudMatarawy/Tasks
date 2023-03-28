#ifndef XO_h_
#define XO_h_
#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_NONSTDC_NO_WARNINGS
#include<stdint.h>
#include<stdio.h>
#include <conio.h>

#define board_max 9
#define board_min 1
#define player_one 0
#define player_two 1
#define WIN 0
#define DRAW 1
#define CONTINUE 2


void drawBoard(uint8_t* board);
void updateBoard(uint8_t* board, uint8_t position, uint8_t value);
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol); 
void setPlayerConfig(uint8_t* configArray);
void loadAndUpdate(uint8_t playerNumber);
void getGameState(uint8_t* board, uint8_t* gameState);



#endif // !'XO_h'

