
#include<stdio.h>
#include<Windows.h>
#include<conio.h>

void gotoxy(int x, int y);
void Draw_Base();
void inputKey(char base[][19], char, int *, int *);
void Draw_Stone(char base[][19]);

void check34(char base[][19]);
void AI_BLACK(char base[][19]);
void AI_WHITE(char base[][19]);


typedef struct aaa {
	int x;
	int y;
	double c;
}aaa;
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define SIZE 19
#define WHITE 2
#define BLACK 1
#define EMPTY 0
aaa AI_value = { 0 };
aaa qwe1[SIZE][SIZE] = { 0 };
aaa qwe2[SIZE][SIZE] = { 0 };
int count = 0, i = 0, j = 0, k = 0;
int nowB[2][SIZE] = { 0 }, nowW[2][SIZE] = { 0 };
int max_H[4][SIZE], max_V[2][SIZE], max_D1[2][SIZE], max_D2[2][SIZE], max_D3[2][SIZE], max_D4[2][SIZE];
double value[SIZE][SIZE] = { 0 };
bool state = true;
int main() {

	char base[SIZE][SIZE] = { 0 };
	int x = 0, y = 0;
	char Key = 0;

	base[19][19] = 0;
	Draw_Base();
	gotoxy(x, y);

	while (Key != 27) {
		
		Key = getch();
		inputKey(base, Key, &x, &y);
		check34(base);

		system("cls");

		gotoxy(0, 0);
		Draw_Base();
		
		AI_WHITE(base);
		
		check34(base);
		Draw_Stone(base);

		gotoxy(x, y);


	}

}
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void AI_WHITE(char base[][19]) {
	for (i = 0; i < SIZE; ++i)//search max vlaue
		for (j = 0; j < SIZE; ++j)
			if (value[i][j]>AI_value.c) {
				AI_value.c = value[i][j];
				AI_value.x = j;
				AI_value.y = i;
			}
	if (count == 0) {
		AI_value.x = 9;
		AI_value.y = 9;
		AI_value.c = 1;
	}

	else if (base[AI_value.y][AI_value.x] != WHITE && base[AI_value.y][AI_value.x] != BLACK)
		if (count % 2 == 1) {
			base[AI_value.y][AI_value.x] = WHITE;
			++count;
		}

	/*gotoxy(AI_value.x * 2, AI_value.y);
	printf("『");*/
	AI_value.y = 0;
	AI_value.x = 0;
	AI_value.c = 0;
}
void AI_BLACK(char base[][19]) {
	for (i = 0; i < SIZE; ++i)//search max vlaue
		for (j = 0; j < SIZE; ++j)
			if (value[i][j]>AI_value.c) {
				AI_value.c = value[i][j];
				AI_value.x = j;
				AI_value.y = i;
			}
	if (count == 0) {
		base[9][9] = BLACK;
		++count;
	}

	else if (base[AI_value.y][AI_value.x] != WHITE && base[AI_value.y][AI_value.x] != BLACK)
		if (count % 2 == 0) {
			base[AI_value.y][AI_value.x] = BLACK;
			++count;
		}

	/*gotoxy(AI_value.x * 2, AI_value.y);
	printf("『");*/
	AI_value.y = 0;
	AI_value.x = 0;
	AI_value.c = 0;
}
void Draw_Base() {
	int i;
	int j;
	printf("Γ");
	for (i = 0; i< 17; ++i)
		printf("Θ");
	printf("Δ");
	printf("\n");


	for (i = 0; i < SIZE - 2; ++i) {
		printf("Η");
		for (j = 0; j < SIZE - 2; ++j)
			printf("Λ");
		printf("Ι");

		printf("\n");

	}

	printf("Ζ");
	for (i = 0; i < SIZE - 2; ++i)
		printf("Κ");
	printf("Ε\n");

	for (i = 0; i < SIZE; ++i) {
		for (j = 0; j < SIZE; ++j)
			printf("%.1f ", value[i][j]);
		printf("\n");
	}


}

void inputKey(char base[][19], char Key, int *x, int *y) {
	switch (Key) {
	case UP:
		if (*y != 0)
			--(*y);
		break;
	case DOWN:
		if (*y != 18)
			++(*y);
		break;
	case RIGHT:
		if (*x != 36)
			*x += 2;
		break;
	case LEFT:
		if (*x != 0)
			*x -= 2;
		break;
	case SPACE:
		if (base[*y][(*x) / 2] != WHITE && base[*y][(*x) / 2] != BLACK) {
			if (count % 2 == 0) {
				base[*y][*x / 2] = BLACK;
				++count;
			}
			else {
				base[*y][*x / 2] = WHITE;
				++count;
			}
		}
		break;
	}
}
void Draw_Stone(char base[][19]) {
	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j) {
			if (base[i][j] == 1) {
				gotoxy(j * 2, i);
				printf("】");
			}
			else if (base[i][j] == 2) {
				gotoxy(j * 2, i);
				printf("＋");
			}
		}
}
void check34(char base[][19]) {
	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j)
			value[i][j] = 0;
	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j) {
			if (base[i][j] == BLACK) {// o
				if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
					value[i][j - 1] += 0.3;
				if ((j + 1) < SIZE &&base[i][j + 1] == EMPTY)
					value[i][j + 1] += 0.3;
				if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
					value[i - 1][j] += 0.3;
				if ((i + 1) < SIZE &&base[i + 1][j] == EMPTY)
					value[i + 1][j] += 0.3;
				if ((j - 1) > -1 && (i - 1) > -1 && base[i - 1][j - 1] == EMPTY)
					value[i - 1][j - 1] += 0.3;
				if ((j - 1) > -1 && (i + 1) < SIZE && base[i + 1][j - 1] == EMPTY)
					value[i + 1][j - 1] += 0.3;
				if ((j + 1) < SIZE && (i - 1) > -1 && base[i - 1][j + 1] == EMPTY)
					value[i - 1][j + 1] += 0.3;
				if ((j + 1) < SIZE && (i + 1) < SIZE && base[i + 1][j + 1] == EMPTY)
					value[i + 1][j + 1] += 0.3;
			}
			//////亜稽
			if (base[i][j] == BLACK&&base[i][j + 1] == BLACK&&base[i][j + 2] == BLACK) { //ししし
				if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
					value[i][j - 1] += 1.5;
				if ((j + 3) < SIZE &&base[i][j + 3] == EMPTY)
					value[i][j + 3] += 1.5;
			}
			if (base[i][j] == BLACK&&base[i][j + 1] == BLACK&&base[i][j + 2] == EMPTY && base[i][j + 3] == BLACK) {//ししxし
				if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
					value[i][j - 1] += 1.5;
				if ((j + 4) < SIZE &&base[i][j + 4] == EMPTY)
					value[i][j + 4] += 1.5;
				++value[i][j + 2];
			}
			if (base[i][j] == BLACK&&base[i][j + 1] == EMPTY&&base[i][j + 2] == BLACK&&base[i][j + 3] == BLACK) {//しxしし
				if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
					value[i][j - 1] += 1.5;
				if ((j + 4) < SIZE &&base[i][j + 4] == EMPTY)
					value[i][j + 4] += 1.5;
				value[i][j + 1] += 1.5;
			}
			if (base[i][j] == BLACK&&base[i][j + 1] == BLACK&&base[i][j + 2] == BLACK&&base[i][j + 3] == BLACK) {//しししし
				if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
					value[i][j - 1] += 20;
				if ((j + 4) < SIZE &&base[i][j + 4] == EMPTY)
					value[i][j + 4] += 20;
			}
			if (base[i][j] == BLACK&&base[i][j + 1] == BLACK&&base[i][j + 2] == BLACK&&base[i][j + 3] == EMPTY&&base[i][j + 4] == BLACK) {//しししxし
				if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
					--value[i][j - 1];
				if ((j + 5) < SIZE &&base[i][j + 5] == EMPTY)
					--value[i][j + 5];
				value[i][j + 3] += 20;
			}
			if (base[i][j] == BLACK&&base[i][j + 1] == BLACK&&base[i][j + 2] == EMPTY&&base[i][j + 3] == BLACK&&base[i][j + 4] == BLACK) {//ししxしし
				if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
					--value[i][j - 1];
				if ((j + 5) < SIZE &&base[i][j + 5] == EMPTY)
					--value[i][j + 5];
				value[i][j + 2] += 20;
			}
			if (base[i][j] == BLACK&&base[i][j + 1] == EMPTY&&base[i][j + 2] == BLACK&&base[i][j + 3] == BLACK&&base[i][j + 4] == BLACK) {//しxししし
				if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
					--value[i][j - 1];
				if ((j + 5) < SIZE &&base[i][j + 5] == EMPTY)
					--value[i][j + 5];
				value[i][j + 1] += 20;
			}
			////// 室稽
			if (base[i][j] == BLACK&&base[i + 1][j] == BLACK&&base[i + 2][j] == BLACK) { //ししし
				if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
					value[i - 1][j] += 1.5;
				if ((i + 3) < SIZE &&base[i + 3][j] == EMPTY)
					value[i + 3][j] += 1.5;
			}
			if (base[i][j] == BLACK&&base[i + 1][j] == BLACK&&base[i + 2][j] == EMPTY && base[i + 3][j] == BLACK) {//ししxし
				if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
					value[i - 1][j] += 1.5;
				if ((i + 4) < SIZE &&base[i + 4][j] == EMPTY)
					value[i + 4][j] += 1.5;
				value[i + 2][j] += 1.5;
			}
			if (base[i][j] == BLACK&&base[i + 1][j] == EMPTY&&base[i + 2][j] == BLACK&&base[i + 3][j] == BLACK) {//しxしし
				if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
					value[i][j - 1] += 1.5;
				if ((i + 4) < SIZE &&base[i + 4][j] == EMPTY)
					value[i + 4][j] += 1.5;
				value[i + 1][j] += 1.5;
			}
			if (base[i][j] == BLACK&&base[i + 1][j] == BLACK&&base[i + 2][j] == BLACK&&base[i + 3][j] == BLACK) {//しししし
				if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
					value[i - 1][j] += 20;
				if ((i + 4) < SIZE &&base[i + 4][j] == EMPTY)
					value[i + 4][j] += 20;
			}
			if (base[i][j] == BLACK&&base[i + 1][j] == BLACK&&base[i + 2][j] == BLACK&&base[i + 3][j] == EMPTY&&base[i + 4][j] == BLACK) {//しししxし
				if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
					--value[i - 1][j];
				if ((i + 5) < SIZE &&base[i + 5][j] == EMPTY)
					--value[i + 5][j];
				value[i + 3][j] += 20;
			}
			if (base[i][j] == BLACK&&base[i + 1][j] == BLACK&&base[i + 2][j] == EMPTY&&base[i + 3][j] == BLACK&&base[i + 4][j] == BLACK) {//ししxしし
				if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
					--value[i - 1][j];
				if ((i + 5) < SIZE &&base[i + 5][j] == EMPTY)
					--value[i + 5][j];
				value[i + 2][j] += 20;
			}
			if (base[i][j] == BLACK&&base[i + 1][j] == EMPTY&&base[i + 2][j] == BLACK&&base[i + 3][j] == BLACK&&base[i + 4][j] == BLACK) {//しxししし
				if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
					--value[i - 1][j];
				if ((i + 5) < SIZE &&base[i + 5][j] == EMPTY)
					--value[i + 5][j];
				value[i + 1][j] += 20;
			}
			//////企唖識 1
			if (base[i][j] == BLACK&&base[i + 1][j + 1] == BLACK&&base[i + 2][j + 2] == BLACK) { //ししし
				if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
					value[i - 1][j - 1] += 1.5;
				if ((i + 3) < SIZE && (j + 3) < SIZE &&base[i + 3][j + 3] == EMPTY)
					value[i + 3][j + 3] += 1.5;
			}
			if (base[i][j] == BLACK&&base[i + 1][j + 1] == BLACK&&base[i + 2][j + 2] == EMPTY && base[i + 3][j + 3] == BLACK) {//ししxし
				if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
					value[i - 1][j - 1] += 1.5;
				if ((i + 4) < SIZE && (j + 4) < SIZE &&base[i + 4][j + 4] == EMPTY)
					value[i + 4][j + 4] += 1.5;
				value[i + 2][j + 2] += 1.5;
			}
			if (base[i][j] == BLACK&&base[i + 1][j + 1] == EMPTY&&base[i + 2][j + 2] == BLACK&&base[i + 3][j + 3] == BLACK) {//しxしし
				if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
					value[i - 1][j - 1] += 1.5;
				if ((i + 4) < SIZE && (j + 4) < SIZE &&base[i + 4][j + 4] == EMPTY)
					value[i + 4][j + 4] += 1.5;
				value[i + 1][j + 1] += 1.5;
			}
			if (base[i][j] == BLACK&&base[i + 1][j + 1] == BLACK&&base[i + 2][j + 2] == BLACK&&base[i + 3][j + 3] == BLACK) {//しししし
				if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
					value[i - 1][j - 1] += 20;
				if ((i + 4) < SIZE && (j + 4) < SIZE &&base[i + 4][j + 4] == EMPTY)
					value[i + 4][j + 4] += 20;
			}
			if (base[i][j] == BLACK&&base[i + 1][j + 1] == BLACK&&base[i + 2][j + 2] == BLACK&&base[i + 3][j + 3] == EMPTY&&base[i + 4][j + 4] == BLACK) {//しししxし
				if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
					--value[i - 1][j - 1];
				if ((i + 5) < SIZE && (j + 5) < SIZE &&base[i + 5][j + 5] == EMPTY)
					--value[i + 5][j + 5];
				value[i + 3][j + 3] += 20;
			}
			if (base[i][j] == BLACK&&base[i + 1][j + 1] == BLACK&&base[i + 2][j + 2] == EMPTY&&base[i + 3][j + 3] == BLACK&&base[i + 4][j + 4] == BLACK) {//ししxしし
				if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
					--value[i - 1][j - 1];
				if ((i + 5) < SIZE && (j + 5) < SIZE &&base[i + 5][j + 5] == EMPTY)
					--value[i + 5][j + 5];
				value[i + 2][j + 2] += 20;
			}
			if (base[i][j] == BLACK&&base[i + 1][j + 1] == EMPTY&&base[i + 2][j + 2] == BLACK&&base[i + 3][j + 3] == BLACK&&base[i + 4][j + 4] == BLACK) {//しxししし
				if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
					--value[i - 1][j - 1];
				if ((i + 5) < SIZE && (j + 5) < SIZE &&base[i + 5][j + 5] == EMPTY)
					--value[i + 5][j + 5];
				value[i + 1][j + 1] += 20;
			}
			//////企唖識 2
			if (base[i][j] == BLACK&&base[i + 1][j - 1] == BLACK&&base[i + 2][j - 2] == BLACK) { //ししし
				if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
					value[i - 1][j + 1]+=1.5;
				if ((i + 3) < SIZE && (j - 3) > -1 && base[i + 3][j - 3] == EMPTY)
					value[i + 3][j - 3]+=1.5;
			}
			if (base[i][j] == BLACK&&base[i + 1][j - 1] == BLACK&&base[i + 2][j - 2] == EMPTY && base[i + 3][j - 3] == BLACK) {//ししxし
				if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
					value[i - 1][j + 1] += 1.5;
				if ((i + 4) < SIZE && (j - 4) > -1 && base[i + 4][j - 4] == EMPTY)
					++value[i + 4][j - 4];
				value[i + 2][j - 2] += 1.5;
			}
			if (base[i][j] == BLACK&&base[i + 1][j - 1] == EMPTY&&base[i + 2][j - 2] == BLACK&&base[i + 3][j - 3] == BLACK) {//しxしし
				if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
					value[i - 1][j + 1] += 1.5;
				if ((i + 4) < SIZE && (j - 4) > -1 && base[i + 4][j - 4] == EMPTY)
					++value[i + 4][j - 4];
				value[i + 1][j - 1] += 1.5;
			}
			if (base[i][j] == BLACK&&base[i + 1][j - 1] == BLACK&&base[i + 2][j - 2] == BLACK&&base[i + 3][j - 3] == BLACK) {//しししし
				if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
					value[i - 1][j + 1] += 20;
				if ((i + 4) < SIZE && (j - 4) > -1 && base[i + 4][j - 4] == EMPTY)
					value[i + 4][j - 4] += 20;
			}
			if (base[i][j] == BLACK&&base[i + 1][j - 1] == BLACK&&base[i + 2][j - 2] == BLACK&&base[i + 3][j - 3] == EMPTY&&base[i + 4][j - 4] == BLACK) {//しししxし
				if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
					--value[i - 1][j + 1];
				if ((i + 5) < SIZE && (j - 5) > -1 && base[i + 5][j - 5] == EMPTY)
					--value[i + 5][j - 5];
				value[i + 3][j - 3] += 20;
			}
			if (base[i][j] == BLACK&&base[i + 1][j - 1] == BLACK&&base[i + 2][j - 2] == EMPTY&&base[i + 3][j - 3] == BLACK&&base[i + 4][j - 4] == BLACK) {//ししxしし
				if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
					--value[i - 1][j + 1];
				if ((i + 5) < SIZE && (j - 5) > -1 && base[i + 5][j - 5] == EMPTY)
					--value[i + 5][j - 5];
				value[i + 2][j - 2] += 20;
			}
			if (base[i][j] == BLACK&&base[i + 1][j - 1] == EMPTY&&base[i + 2][j - 2] == BLACK&&base[i + 3][j - 3] == BLACK&&base[i + 4][j - 4] == BLACK) {//しxししし
				if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
					--value[i - 1][j + 1];
				if ((i + 5) < SIZE && (j - 5) > -1 && base[i + 5][j - 5] == EMPTY)
					--value[i + 5][j - 5];
				value[i + 1][j - 1] += 20;
			}
		}
	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j) {
			if (base[i][j] == WHITE) {/////o
				if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
					value[i][j - 1] += 0.3;
				if ((j + 1) < SIZE &&base[i][j + 1] == EMPTY)
					value[i][j + 1] += 0.3;
				if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
					value[i - 1][j] += 0.3;
				if ((i + 1) < SIZE &&base[i + 1][j] == EMPTY)
					value[i + 1][j] += 0.3;
				if ((j - 1) > -1 && (i - 1) > -1 && base[i - 1][j - 1] == EMPTY)
					value[i - 1][j - 1] += 0.3;
				if ((j - 1) > -1 && (i + 1) < SIZE && base[i + 1][j - 1] == EMPTY)
					value[i + 1][j - 1] += 0.3;
				if ((j + 1) < SIZE && (i - 1) > -1 && base[i - 1][j + 1] == EMPTY)
					value[i - 1][j + 1] += 0.3;
				if ((j + 1) < SIZE && (i + 1) < SIZE && base[i + 1][j + 1] == EMPTY)
					value[i + 1][j + 1] += 0.3;
			}
			//////亜稽
			if (base[i][j] == WHITE &&base[i][j + 1] == WHITE) {////oo
				if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
					value[i][j - 1] += 0.5;
				if ((j + 2) < SIZE &&base[i][j + 2] == EMPTY)
					value[i][j + 2] += 0.5;


				if (base[i][j] == WHITE&&base[i][j + 1] == WHITE&&base[i][j + 2] == WHITE) { //ししし
					if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
						value[i][j - 1] += 1.5;
					if ((j + 3) < SIZE &&base[i][j + 3] == EMPTY)
						value[i][j + 3] += 1.5;
				}
				if (base[i][j] == WHITE&&base[i][j + 1] == WHITE&&base[i][j + 2] == EMPTY && base[i][j + 3] == WHITE) {//ししxし
					if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
						value[i][j - 1] += 1.5;
					if ((j + 4) < SIZE &&base[i][j + 4] == EMPTY)
						value[i][j + 4] += 1.5;
					value[i][j + 2] += 1.5;
				}
				if (base[i][j] == WHITE&&base[i][j + 1] == EMPTY&&base[i][j + 2] == WHITE&&base[i][j + 3] == WHITE) {//しxしし
					if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
						value[i][j - 1] += 1.5;
					if ((j + 4) < SIZE &&base[i][j + 4] == EMPTY)
						value[i][j + 4] += 1.5;
					value[i][j + 1] += 1.5;
				}
				if (base[i][j] == WHITE&&base[i][j + 1] == WHITE&&base[i][j + 2] == WHITE&&base[i][j + 3] == WHITE) {//しししし
					if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
						value[i][j - 1] += 20;
					if ((j + 4) < SIZE &&base[i][j + 4] == EMPTY)
						value[i][j + 4] += 20;
				}
				if (base[i][j] == WHITE&&base[i][j + 1] == WHITE&&base[i][j + 2] == WHITE&&base[i][j + 3] == EMPTY&&base[i][j + 4] == WHITE) {//しししxし
					if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
						--value[i][j - 1];
					if ((j + 5) < SIZE &&base[i][j + 5] == EMPTY)
						--value[i][j + 5];
					value[i][j + 3] += 20;
				}
				if (base[i][j] == WHITE&&base[i][j + 1] == WHITE&&base[i][j + 2] == EMPTY&&base[i][j + 3] == WHITE&&base[i][j + 4] == WHITE) {//ししxしし
					if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
						--value[i][j - 1];
					if ((j + 5) < SIZE &&base[i][j + 5] == EMPTY)
						--value[i][j + 5];
					value[i][j + 2] += 20;
				}
				if (base[i][j] == WHITE&&base[i][j + 1] == EMPTY&&base[i][j + 2] == WHITE&&base[i][j + 3] == WHITE&&base[i][j + 4] == WHITE) {//しxししし
					if ((j - 1) > -1 && base[i][j - 1] == EMPTY)
						--value[i][j - 1];
					if ((j + 5) < SIZE &&base[i][j + 5] == EMPTY)
						--value[i][j + 5];
					value[i][j + 1] += 20;
				}
				/////室稽
				if (base[i][j] == WHITE &&base[i + 1][j] == WHITE) {////oo
					if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
						value[i - 1][j] += 0.5;
					if ((i + 2) < SIZE &&base[i + 2][j] == EMPTY)
						value[i + 2][j] += 0.5;
				}
				if (base[i][j] == WHITE&&base[i + 1][j] == WHITE&&base[i + 2][j] == WHITE) { //ししし
					if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
						value[i - 1][j] += 1.5;
					if ((i + 3) < SIZE &&base[i + 3][j] == EMPTY)
						value[i + 3][j] += 1.5;
				}
				if (base[i][j] == WHITE&&base[i + 1][j] == WHITE&&base[i + 2][j] == EMPTY && base[i + 3][j] == WHITE) {//ししxし
					if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
						value[i - 1][j] += 1.5;
					if ((i + 4) < SIZE &&base[i + 4][j] == EMPTY)
						value[i + 4][j] += 1.5;
					value[i + 2][j] += 1.5;
				}
				if (base[i][j] == WHITE&&base[i + 1][j] == EMPTY&&base[i + 2][j] == WHITE&&base[i + 3][j] == WHITE) {//しxしし
					if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
						value[i][j - 1] += 1.5;
					if ((i + 4) < SIZE &&base[i + 4][j] == EMPTY)
						value[i + 4][j] += 1.5;
					value[i + 1][j] += 1.5;
				}
				if (base[i][j] == WHITE&&base[i + 1][j] == WHITE&&base[i + 2][j] == WHITE&&base[i + 3][j] == WHITE) {//しししし
					if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
						value[i - 1][j] += 20;
					if ((i + 4) < SIZE &&base[i + 4][j] == EMPTY)
						value[i + 4][j] += 20;
				}
				if (base[i][j] == WHITE&&base[i + 1][j] == WHITE&&base[i + 2][j] == WHITE&&base[i + 3][j] == EMPTY&&base[i + 4][j] == WHITE) {//しししxし
					if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
						--value[i - 1][j];
					if ((i + 5) < SIZE &&base[i + 5][j] == EMPTY)
						--value[i + 5][j];
					value[i + 3][j] += 20;
				}
				if (base[i][j] == WHITE&&base[i + 1][j] == WHITE&&base[i + 2][j] == EMPTY&&base[i + 3][j] == WHITE&&base[i + 4][j] == WHITE) {//ししxしし
					if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
						--value[i - 1][j];
					if ((i + 5) < SIZE &&base[i + 5][j] == EMPTY)
						--value[i + 5][j];
					value[i + 2][j] += 20;
				}
				if (base[i][j] == WHITE&&base[i + 1][j] == EMPTY&&base[i + 2][j] == WHITE&&base[i + 3][j] == WHITE&&base[i + 4][j] == WHITE) {//しxししし
					if ((i - 1) > -1 && base[i - 1][j] == EMPTY)
						--value[i - 1][j];
					if ((i + 5) < SIZE &&base[i + 5][j] == EMPTY)
						--value[i + 5][j];
					value[i + 1][j] += 20;
				}
				//////企唖識 1
				if (base[i][j] == WHITE &&base[i + 1][j + 1] == WHITE) {////oo
					if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
						value[i - 1][j - 1] += 0.5;
					if ((i + 2) < SIZE && (j + 2) < SIZE && base[i + 2][j] == EMPTY)
						value[i + 2][j + 2] += 0.5;
				}
				if (base[i][j] == WHITE&&base[i + 1][j + 1] == WHITE&&base[i + 2][j + 2] == WHITE) { //ししし
					if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
						value[i - 1][j - 1] += 1.5;
					if ((i + 3) < SIZE && (j + 3) < SIZE &&base[i + 3][j + 3] == EMPTY)
						value[i + 3][j + 3] += 1.5;
				}
				if (base[i][j] == WHITE&&base[i + 1][j + 1] == WHITE&&base[i + 2][j + 2] == EMPTY && base[i + 3][j + 3] == WHITE) {//ししxし
					if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
						value[i - 1][j - 1] += 1.5;
					if ((i + 4) < SIZE && (j + 4) < SIZE &&base[i + 4][j + 4] == EMPTY)
						value[i + 4][j + 4] += 1.5;
					value[i + 2][j + 2] += 1.5;
				}
				if (base[i][j] == WHITE&&base[i + 1][j + 1] == EMPTY&&base[i + 2][j + 2] == WHITE&&base[i + 3][j + 3] == WHITE) {//しxしし
					if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
						value[i - 1][j - 1] += 1.5;
					if ((i + 4) < SIZE && (j + 4) < SIZE &&base[i + 4][j + 4] == EMPTY)
						value[i + 4][j + 4] += 1.5;
					value[i + 1][j + 1] += 1.5;
				}
				if (base[i][j] == WHITE&&base[i + 1][j + 1] == WHITE&&base[i + 2][j + 2] == WHITE&&base[i + 3][j + 3] == WHITE) {//しししし
					if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
						value[i - 1][j - 1] += 20;
					if ((i + 4) < SIZE && (j + 4) < SIZE &&base[i + 4][j + 4] == EMPTY)
						value[i + 4][j + 4] += 20;
				}
				if (base[i][j] == WHITE&&base[i + 1][j + 1] == WHITE&&base[i + 2][j + 2] == WHITE&&base[i + 3][j + 3] == EMPTY&&base[i + 4][j + 4] == WHITE) {//しししxし
					if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
						--value[i - 1][j - 1];
					if ((i + 5) < SIZE && (j + 5) < SIZE &&base[i + 5][j + 5] == EMPTY)
						--value[i + 5][j + 5];
					value[i + 3][j + 3] += 20;
				}
				if (base[i][j] == WHITE&&base[i + 1][j + 1] == WHITE&&base[i + 2][j + 2] == EMPTY&&base[i + 3][j + 3] == WHITE&&base[i + 4][j + 4] == WHITE) {//ししxしし
					if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
						--value[i - 1][j - 1];
					if ((i + 5) < SIZE && (j + 5) < SIZE &&base[i + 5][j + 5] == EMPTY)
						--value[i + 5][j + 5];
					value[i + 2][j + 2] += 20;
				}
				if (base[i][j] == WHITE&&base[i + 1][j + 1] == EMPTY&&base[i + 2][j + 2] == WHITE&&base[i + 3][j + 3] == WHITE&&base[i + 4][j + 4] == WHITE) {//しxししし
					if ((i - 1) > -1 && (j - 1) > -1 && base[i - 1][j - 1] == EMPTY)
						--value[i - 1][j - 1];
					if ((i + 5) < SIZE && (j + 5) < SIZE &&base[i + 5][j + 5] == EMPTY)
						--value[i + 5][j + 5];
					value[i + 1][j + 1] += 20;
				}
				//////企唖識 2
				if (base[i][j] == WHITE &&base[i + 1][j - 1] == WHITE) {////oo
					if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
						value[i - 1][j + 1] += 0.5;
					if ((i + 2) < SIZE && (j - 2) > -1 && base[i + 2][j] == EMPTY)
						value[i + 2][j - 2] += 0.5;
				}
				if (base[i][j] == WHITE&&base[i + 1][j - 1] == WHITE&&base[i + 2][j - 2] == WHITE) { //ししし
					if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
						value[i - 1][j + 1] += 1.5;
					if ((i + 3) < SIZE && (j - 3) > -1 && base[i + 3][j - 3] == EMPTY)
						value[i + 3][j - 3] += 1.5;
				}
				if (base[i][j] == WHITE&&base[i + 1][j - 1] == WHITE&&base[i + 2][j - 2] == EMPTY && base[i + 3][j - 3] == WHITE) {//ししxし
					if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
						value[i - 1][j + 1] += 1.5;
					if ((i + 4) < SIZE && (j - 4) > -1 && base[i + 4][j - 4] == EMPTY)
						value[i + 4][j - 4] += 1.5;
					value[i + 2][j - 2] += 1.5;
				}
				if (base[i][j] == WHITE&&base[i + 1][j - 1] == EMPTY&&base[i + 2][j - 2] == WHITE&&base[i + 3][j - 3] == WHITE) {//しxしし
					if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
						value[i - 1][j + 1] += 1.5;
					if ((i + 4) < SIZE && (j - 4) > -1 && base[i + 4][j - 4] == EMPTY)
						value[i + 4][j - 4] += 1.5;
					value[i + 1][j - 1] += 1.5;
				}
				if (base[i][j] == WHITE&&base[i + 1][j - 1] == WHITE&&base[i + 2][j - 2] == WHITE&&base[i + 3][j - 3] == WHITE) {//しししし
					if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
						value[i - 1][j + 1] += 20;
					if ((i + 4) < SIZE && (j - 4) > -1 && base[i + 4][j - 4] == EMPTY)
						value[i + 4][j - 4] += 20;
				}
				if (base[i][j] == WHITE&&base[i + 1][j - 1] == WHITE&&base[i + 2][j - 2] == WHITE&&base[i + 3][j - 3] == EMPTY&&base[i + 4][j - 4] == WHITE) {//しししxし
					if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
						--value[i - 1][j + 1];
					if ((i + 5) < SIZE && (j - 5) > -1 && base[i + 5][j - 5] == EMPTY)
						--value[i + 5][j - 5];
					value[i + 3][j - 3] += 20;
				}
				if (base[i][j] == WHITE&&base[i + 1][j - 1] == WHITE&&base[i + 2][j - 2] == EMPTY&&base[i + 3][j - 3] == WHITE&&base[i + 4][j - 4] == WHITE) {//ししxしし
					if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
						--value[i - 1][j + 1];
					if ((i + 5) < SIZE && (j - 5) > -1 && base[i + 5][j - 5] == EMPTY)
						--value[i + 5][j - 5];
					value[i + 2][j - 2] += 20;
				}
				if (base[i][j] == WHITE&&base[i + 1][j - 1] == EMPTY&&base[i + 2][j - 2] == WHITE&&base[i + 3][j - 3] == WHITE&&base[i + 4][j - 4] == WHITE) {//しxししし
					if ((i - 1) > -1 && (j + 1) < SIZE && base[i - 1][j + 1] == EMPTY)
						--value[i - 1][j + 1];
					if ((i + 5) < SIZE && (j - 5) > -1 && base[i + 5][j - 5] == EMPTY)
						--value[i + 5][j - 5];
					value[i + 1][j - 1] += 20;
				}
			}

		}
}