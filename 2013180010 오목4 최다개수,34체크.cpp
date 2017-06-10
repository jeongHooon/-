
#include<stdio.h>
#include<Windows.h>
#include<conio.h>

void gotoxy(int x, int y);
void Draw_Base();
void inputKey(char base[][19], char, int *, int *);
void Draw_Stone(char base[][19]);

void check34(char base[][19]);
void reset();
void reset1();

void check_H(char base[][19]);
void check_V(char base[][19]);

typedef struct aaa {
	int x;
	int y;
	int c;
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
aaa qwe1[SIZE][SIZE] = { 0 };
aaa qwe2[SIZE][SIZE] = { 0 };
int count = 0, i = 0, j = 0, k = 0;
int nowB[2][SIZE] = { 0 }, nowW[2][SIZE] = { 0 };
int max_H[4][SIZE], max_V[2][SIZE], max_D1[2][SIZE], max_D2[2][SIZE], max_D3[2][SIZE], max_D4[2][SIZE];
int value[SIZE][SIZE] = { 0 };
bool state = true;
int main() {

	char base[SIZE][SIZE] = { 0 };
	int x = 0, y = 0;
	char Key = 0;

	base[19][19] = 0;
	check_H(base);
	check_V(base);
	Draw_Base();
	gotoxy(x, y);

	while (Key != 27) {
		check_H(base);
		check_V(base);
		check34(base);


		Key = getch();
		inputKey(base, Key, &x, &y);


		system("cls");
		gotoxy(0, 0);
		Draw_Base();
		//gotoxy(x, y);
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
	printf("Ε");


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
		if (base[*y][(*x) / 2] != WHITE && base[*y][(*x) / 2] != BLACK)
			if (count == 0) {
				base[*y][*x / 2] = 1;
				nowB[1][*x / 2]++;
				nowB[0][*y]++;
				count = 1;
			}
			else if (base[*y][(*x) / 2] != WHITE && base[*y][(*x) / 2] != BLACK) {
				base[*y][*x / 2] = 2;
				nowW[1][*x / 2]++;
				nowW[0][*y]++;
				count = 0;
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
	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j)
			if (value[i][j] > 0) {
				gotoxy(j * 2, i);
				printf("『");
			}
	for (k = 0; k < SIZE; ++k)
		for (i = 0; i<SIZE; ++i)
			if (qwe1[k][i].c == 1)
				for (j = 0; j < max_H[1][k]; ++j) {
					if (base[qwe1[k][i].y][qwe1[k][i].x + j] == EMPTY)
						++qwe1[k][i].x;
					gotoxy((qwe1[k][i].x + j) * 2, qwe1[k][i].y);
					printf("』");
					}
	for (k = 0; k < SIZE; ++k)
		for (i = 0; i<SIZE; ++i)
			if (qwe2[k][i].c == 1)
				for (j = 0; j < max_V[1][k]; ++j) {
					if (base[qwe2[k][i].y][qwe2[k][i].x + j] == EMPTY)
						++qwe2[k][i].x;
					gotoxy((qwe2[k][i].x + j) * 2, qwe2[k][i].y);
					printf("【");
				}
}
void check34(char base[][19]) {
	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j)
			value[i][j] = 0;
	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j) {
			if (base[i][j] == BLACK&&base[i][j + 1] == BLACK&&base[i][j + 2] == BLACK) { //ししし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					++value[i][j - 1];
				if ((j + 3) < SIZE &&base[i][j + 3] == EMPTY)
					++value[i][j + 3];
			}
			if (base[i][j] == BLACK&&base[i][j + 1] == BLACK&&base[i][j + 2] == EMPTY && base[i][j + 3] == BLACK) {//ししxし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					++value[i][j - 1];
				if ((j + 4) < SIZE &&base[i][j + 4] == EMPTY)
					++value[i][j + 4];
				++value[i][j + 2];
			}
			if (base[i][j] == BLACK&&base[i][j + 1] == EMPTY&&base[i][j + 2] == BLACK&&base[i][j + 3] == BLACK) {//しxしし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					++value[i][j - 1];
				if ((j + 4) < SIZE &&base[i][j + 4] == EMPTY)
					++value[i][j + 4];
				++value[i][j + 1];
			}
			if (base[i][j] == BLACK&&base[i][j + 1] == BLACK&&base[i][j + 2] == BLACK&&base[i][j + 3] == BLACK) {//しししし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					++value[i][j - 1];
				if ((j + 4) < SIZE &&base[i][j + 4] == EMPTY)
					++value[i][j + 4];
			}
			if (base[i][j] == BLACK&&base[i][j + 1] == BLACK&&base[i][j + 2] == BLACK&&base[i][j + 3] == EMPTY&&base[i][j + 4] == BLACK) {//しししxし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					--value[i][j - 1];
				if ((j + 5) < SIZE &&base[i][j + 5] == EMPTY)
					--value[i][j + 5];
				++value[i][j + 3];
			}
			if (base[i][j] == BLACK&&base[i][j + 1] == BLACK&&base[i][j + 2] == EMPTY&&base[i][j + 3] == BLACK&&base[i][j + 4] == BLACK) {//ししxしし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					--value[i][j - 1];
				if ((j + 5) < SIZE &&base[i][j + 5] == EMPTY)
					--value[i][j + 5];
				++value[i][j + 2];
			}
			if (base[i][j] == BLACK&&base[i][j + 1] == EMPTY&&base[i][j + 2] == BLACK&&base[i][j + 3] == BLACK&&base[i][j + 4] == BLACK) {//しxししし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					--value[i][j - 1];
				if ((j + 5) < SIZE &&base[i][j + 5] == EMPTY)
					--value[i][j + 5];
				++value[i][j + 1];
			}
		}
	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j) {
			if (base[i][j] == WHITE&&base[i][j + 1] == WHITE&&base[i][j + 2] == WHITE) { //ししし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					++value[i][j - 1];
				if ((j + 3) < SIZE &&base[i][j + 3] == EMPTY)
					++value[i][j + 3];
			}
			if (base[i][j] == WHITE&&base[i][j + 1] == WHITE&&base[i][j + 2] == EMPTY && base[i][j + 3] == WHITE) {//ししxし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					++value[i][j - 1];
				if ((j + 4) < SIZE &&base[i][j + 4] == EMPTY)
					++value[i][j + 4];
				++value[i][j + 2];
			}
			if (base[i][j] == WHITE&&base[i][j + 1] == EMPTY&&base[i][j + 2] == WHITE&&base[i][j + 3] == WHITE) {//しxしし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					++value[i][j - 1];
				if ((j + 4) < SIZE &&base[i][j + 4] == EMPTY)
					++value[i][j + 4];
				++value[i][j + 1];
			}
			if (base[i][j] == WHITE&&base[i][j + 1] == WHITE&&base[i][j + 2] == WHITE&&base[i][j + 3] == WHITE) {//しししし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					++value[i][j - 1];
				if ((j + 4) < SIZE &&base[i][j + 4] == EMPTY)
					++value[i][j + 4];
			}
			if (base[i][j] == WHITE&&base[i][j + 1] == WHITE&&base[i][j + 2] == WHITE&&base[i][j + 3] == EMPTY&&base[i][j + 4] == WHITE) {//しししxし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					--value[i][j - 1];
				if ((j + 5) < SIZE &&base[i][j + 5] == EMPTY)
					--value[i][j + 5];
				++value[i][j + 3];
			}
			if (base[i][j] == WHITE&&base[i][j + 1] == WHITE&&base[i][j + 2] == EMPTY&&base[i][j + 3] == WHITE&&base[i][j + 4] == WHITE) {//ししxしし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					--value[i][j - 1];
				if ((j + 5) < SIZE &&base[i][j + 5] == EMPTY)
					--value[i][j + 5];
				++value[i][j + 2];
			}
			if (base[i][j] == WHITE&&base[i][j + 1] == EMPTY&&base[i][j + 2] == WHITE&&base[i][j + 3] == WHITE&&base[i][j + 4] == WHITE) {//しxししし
				if ((j - 1)>-1 && base[i][j - 1] == EMPTY)
					--value[i][j - 1];
				if ((j + 5) < SIZE &&base[i][j + 5] == EMPTY)
					--value[i][j + 5];
				++value[i][j + 1];
			}
		}
}
void reset() {
	for (j = 0; j < SIZE;++j)
	for (i = 0; i < SIZE; ++i) {
		qwe1[j][i].x = 0;
		qwe1[j][i].y = 0;
		qwe1[j][i].c = 0;
	
	}
}
void reset1() {
	for (j = 0; j < SIZE; ++j)
		for (i = 0; i < SIZE; ++i) {
			
			qwe2[j][i].x = 0;
			qwe2[j][i].y = 0;
			qwe2[j][i].c = 0;
		}
}
void check_H(char base[][19]) {

	for (int i = 0; i < SIZE; ++i) {
		max_H[0][i] = 3;
		max_H[1][i] = 0;
	}
	reset();
	for (int j = 0; j < SIZE; ++j) {
		for (int i = 0; i < SIZE; ++i) {
			if (base[j][i] == BLACK && base[j][i + 1] == BLACK && base[j][i + 2] == BLACK && base[j][i + 3] == BLACK) {
				if (max_H[1][j] == 3)
					reset();
				max_H[1][j] = 4;
				max_H[0][j] = BLACK;
				qwe1[j][i].x = i;
				qwe1[j][i].y = j;
				qwe1[j][i].c = 1;
			}
			else if (base[j][i] == BLACK && base[j][i + 1] == BLACK && base[j][i + 2] == BLACK && base[j][i + 3] == EMPTY && base[j][i + 4] == BLACK) {
				if (max_H[1][j] == 3)
					reset();
				max_H[1][j] = 4;
				max_H[0][j] = BLACK;
				qwe1[j][i].x = i;
				qwe1[j][i].y = j;
				qwe1[j][i].c = 1;
			}
			else if (base[j][i] == BLACK && base[j][i + 1] == BLACK && base[j][i + 2] == EMPTY && base[j][i + 3] == BLACK && base[j][i + 4] == BLACK) {
				if (max_H[1][j] == 3)
					reset();
				max_H[1][j] = 4;
				max_H[0][j] = BLACK;
				qwe1[j][i].x = i;
				qwe1[j][i].y = j;
				qwe1[j][i].c = 1;
			}
			else if (base[j][i] == BLACK && base[j][i + 1] == EMPTY && base[j][i + 2] == BLACK && base[j][i + 3] == BLACK && base[j][i + 4] == BLACK) {
				if (max_H[1][j] == 3)
					reset();

				max_H[1][j] = 4;
				max_H[0][j] = BLACK;
				qwe1[j][i].x = i;
				qwe1[j][i].y = j;
				qwe1[j][i].c = 1;
			}

			else if (base[j][i] == BLACK && base[j][i + 1] == BLACK && base[j][i + 2] == EMPTY && base[j][i + 3] == BLACK) {
				if (max_H[1][j] == 2)
					reset();
				if (max_H[1][j] < 4) {
					max_H[1][j] = 3;
					max_H[0][j] = BLACK;
					qwe1[j][i].x = i;
					qwe1[j][i].y = j;
					qwe1[j][i].c = 1;
				}
			}
			else if (base[j][i] == BLACK && base[j][i + 1] == EMPTY && base[j][i + 2] == BLACK && base[j][i + 3] == BLACK) {
				if (max_H[1][j] == 2)
					reset();
				if (max_H[1][j] < 4) {
					max_H[1][j] = 3;
					max_H[0][j] = BLACK;
					qwe1[j][i].x = i;
					qwe1[j][i].y = j;
					qwe1[j][i].c = 1;
				}
			}
			else if (base[j][i] == BLACK && base[j][i + 1] == BLACK && base[j][i + 2] == BLACK) {
				if (max_H[1][j] == 2)
					reset();
				if (max_H[1][j] < 4) {
					max_H[1][j] = 3;
					max_H[0][j] = BLACK;
					qwe1[j][i].x = i;
					qwe1[j][i].y = j;
					qwe1[j][i].c = 1;
				}
			}
			else if (base[j][i] == BLACK && base[j][i + 1] == BLACK) {
				if (max_H[1][j] < 3) {
					max_H[1][j] = 2;
					max_H[0][j] = BLACK;
					qwe1[j][i].x = i;
					qwe1[j][i].y = j;
					qwe1[j][i].c = 1;
				}
			}
			else if (base[j][i] == BLACK && base[j][i + 1] == EMPTY && base[j][i + 2] == BLACK) {
				if (max_H[1][j] < 3) {
					max_H[1][j] = 2;
					max_H[0][j] = BLACK;
					qwe1[j][i].x = i;
					qwe1[j][i].y = j;
					qwe1[j][i].c = 1;
				}
			}
		}
	}
}
void check_V(char base[][19]) {
	for (int i = 0; i < SIZE; ++i) {
		max_V[0][i] = 3;
		max_V[1][i] = 0;
	}
	reset1();


	for (int j = 0; j < SIZE; ++j) {
		for (int i = 0; i < SIZE; ++i) {
			if (base[j][i] == WHITE && base[j][i + 1] == WHITE && base[j][i + 2] == WHITE && base[j][i + 3] == WHITE) {
				if (max_V[1][j] == 3)
					reset1();
				max_V[1][j] = 4;
				max_V[0][j] = WHITE;
				qwe2[j][i].x = i;
				qwe2[j][i].y = j;
				qwe2[j][i].c = 1;
			}
			else if (base[j][i] == WHITE && base[j][i + 1] == WHITE && base[j][i + 2] == WHITE && base[j][i + 3] == EMPTY && base[j][i + 4] == WHITE) {
				if (max_V[1][j] == 3)
					reset1();
				max_V[1][j] = 4;
				max_V[0][j] = WHITE;
				qwe2[j][i].x = i;
				qwe2[j][i].y = j;
				qwe2[j][i].c = 1;
			}
			else if (base[j][i] == WHITE && base[j][i + 1] == WHITE && base[j][i + 2] == EMPTY && base[j][i + 3] == WHITE && base[j][i + 4] == WHITE) {
				if (max_V[1][j] == 3)
					reset1();
				max_V[1][j] = 4;
				max_V[0][j] = WHITE;
				qwe2[j][i].x = i;
				qwe2[j][i].y = j;
				qwe2[j][i].c = 1;
			}
			else if (base[j][i] == WHITE && base[j][i + 1] == EMPTY && base[j][i + 2] == WHITE && base[j][i + 3] == WHITE && base[j][i + 4] == WHITE) {
				if (max_V[1][j] == 3)
					reset1();
				max_V[1][j] = 4;
				max_V[0][j] = WHITE;
				qwe2[j][i].x = i;
				qwe2[j][i].y = j;
				qwe2[j][i].c = 1;
			}

			else if (base[j][i] == WHITE && base[j][i + 1] == WHITE && base[j][i + 2] == EMPTY && base[j][i + 3] == WHITE) {
				if (max_V[1][j] == 2)
					reset1();
				if (max_V[1][j] < 4) {
					max_V[1][j] = 3;
					max_V[0][j] = WHITE;
					qwe2[j][i].x = i;
					qwe2[j][i].y = j;
					qwe2[j][i].c = 1;
				}
			}
			else if (base[j][i] == WHITE && base[j][i + 1] == EMPTY && base[j][i + 2] == WHITE && base[j][i + 3] == WHITE) {
				if (max_V[1][j] == 2)
					reset1();
				if (max_V[1][j] < 4) {
					max_V[1][j] = 3;
					max_V[0][j] = WHITE;
					qwe2[j][i].x = i;
					qwe2[j][i].y = j;
					qwe2[j][i].c = 1;
				}
			}
			else if (base[j][i] == WHITE && base[j][i + 1] == WHITE && base[j][i + 2] == WHITE) {
				if (max_V[1][j] == 2)
					reset1();
				if (max_V[1][j] < 4) {
					max_V[1][j] = 3;
					max_V[0][j] = WHITE;
					qwe2[j][i].x = i;
					qwe2[j][i].y = j;
					qwe2[j][i].c = 1;
				}
			}
			else if (base[j][i] == WHITE && base[j][i + 1] == WHITE) {
				if (max_V[1][j] < 3) {
					max_V[1][j] = 2;
					max_V[0][j] = WHITE;
					qwe2[j][i].x = i;
					qwe2[j][i].y = j;
					qwe2[j][i].c = 1;
				}
			}
			else if (base[j][i] == WHITE && base[j][i + 1] == EMPTY && base[j][i + 2] == WHITE) {
				if (max_V[1][j] < 3) {
					max_V[1][j] = 2;
					max_V[0][j] = WHITE;
					qwe2[j][i].x = i;
					qwe2[j][i].y = j;
					qwe2[j][i].c = 1;
				}
			}
		}
	}
}

