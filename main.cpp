#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ConvertY(int s) {
	if (s < 4) return 0;
	if (s < 7) return 1;
	return 2;
}

int ConvertX(int s) {
	if (s == 1 || s == 4 || s == 7) return 0;
	if (s == 2 || s == 5 || s == 8) return 1;
	return 2;
}

void display(char pole[3][3]) {
	printf("-------\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c ", pole[i][j]);
		}
		printf("\n\n");
	}
	printf("-------\n");
}

char checkWinner(char pole[3][3])
{
	// HORIZONT
	for (int i = 0; i < 3; i++)
		if (pole[i][0] != '-' && pole[i][0] == pole[i][1] && pole[i][0] == pole[i][2]) return pole[i][0];
	// VERTICAL
	for (int i = 0; i < 3; i++)
		if (pole[0][i] != '-' && pole[0][i] == pole[1][i] && pole[0][i] == pole[2][i]) return pole[0][i];
	// DIAGONAL 1
	if (pole[0][0] != '-' && pole[0][0] == pole[1][1] && pole[0][0] == pole[2][2]) return pole[1][1];
	// DIAGONAL 2
	if (pole[0][2] != '-' && pole[0][2] == pole[1][1] && pole[0][2] == pole[2][0]) return pole[1][1];
	return '-';
}

int main() {
	// - пусто, X - крестик, O - нолик
	char pole[3][3] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };
	int number = 0;
	int drawCounter = 1;
	int shot = 0;
	int y = 0, x = 0;
	char winChar = 0;
	char currentChar = 0;
	srand(time(NULL));
	number = rand();

	while (true){
		if (number % 2 == 0)
		{
			// shot X
			currentChar = 'X';
		}
		else
		{
			// shot O
			currentChar = 'O';
		}
		do {
			printf("enter 1-9 for %c: ", currentChar);
			scanf_s("%d", &shot);
			y = ConvertY(shot);
			x = ConvertX(shot);
		} while (pole[y][x] != '-');
		pole[y][x] = currentChar;
		// show pole
		display(pole);
		// next turn
		number++;
		// check for win
		winChar = checkWinner(pole);
		if (winChar != '-')
		{
			printf("WINNER %c\n", winChar);
			break;
		}
		// check for draw
		if (drawCounter == 9)
		{
			printf("DRAW!\n");
			break;
		}
		drawCounter++;
	}



}