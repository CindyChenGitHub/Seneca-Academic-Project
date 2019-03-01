/********************************************************************** 
// ICP144
// File dice.c
// Version 1.0 
// Date 2017/12/07
// Author Cindy Chen 
/**********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define XMAX 5
#define YMAX 5
#define DOTMIN 1
#define DOTMAX 6
#define DICENUM 9

void randInt(int min, int max, int nums, int values[]);

int main(void) {
	struct Dot {
		char line[XMAX][YMAX];

	};

	struct Dot dot[DOTMAX] = {
		{ "-----", "|   |", "| * |", "|   |", "-----" },
		{ "-----", "|*  |", "|   |", "|  *|", "-----" },
		{ "-----", "|*  |", "| * |", "|  *|", "-----" },
		{ "-----", "|* *|", "|   |", "|* *|", "-----" },
		{ "-----", "| * |", "|* *|", "|* *|", "-----" },
		{ "-----", "|* *|", "|* *|", "|* *|", "-----" }
	};

	int dotValue[DICENUM] = { 0 };

	randInt(DOTMIN, DOTMAX, DICENUM, dotValue);

	for (int x = 0; x < XMAX; x++) {
		for (int dotCount = 0; dotCount < DICENUM; dotCount++) {
			for (int y = 0; y < YMAX; y++) {
				char chars = { dot[dotValue[dotCount]].line[x][y] };
				printf("%c", chars);
			}
			printf("\t");
		}
		printf("\n");
	}
	
	return 0;
}

void randInt(int min, int max, int nums, int values[]) {
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < nums; i++) {
		values[i] = rand() % (max - min + 1);
	}
}
