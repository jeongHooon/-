#include<stdio.h>
#include<Windows.h>


void gotoxy(int x, int y);
void Draw_Base();
void inputKey(char base[][19], char, int *, int *);
void Draw_Stone(char base[][19]);

void check_H(char base[][19]);
void check_V(char base[][19]);
void check_D1(char base[][19]);
void check_D2(char base[][19]);
void check_D3(char base[][19]);
void check_D4(char base[][19]);

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define SIZE 19
int count = 0, i = 0, j = 0;
int nowB[2][SIZE] = { 0 }, nowW[2][SIZE] = { 0 };
int max_H[4][SIZE], max_V[2][SIZE], max_D1[2][SIZE], max_D2[2][SIZE], max_D3[2][SIZE], max_D4[2][SIZE];
int main() {
	char base[SIZE][SIZE] = { 0 };
	base[19][19] = 0;
	int x = 0, y = 0;
	char Key = 0;
	
	check_H(base);
	check_V(base);
	check_D1(base);
	check_D2(base);
	check_D3(base);
	check_D4(base);
	Draw_Base();
	gotoxy(x, y);

	while (Key != 27) {
		check_H(base);
		check_V(base);
		check_D1(base);
		check_D2(base);
		check_D3(base);
		check_D4(base);

		Key = getch();
		inputKey(base, Key, &x, &y);


		system("cls");
		gotoxy(0, 0);
		Draw_Base();
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
	printf("¦£");
	for (i = 0; i< 17; ++i)
		printf("¦¨");
	printf("¦¤");
	printf("B : %d ", nowB[0][0]);
	printf("W : %d ", nowW[0][0]);
	switch (max_H[0][0]) {
	case 1:
		printf("B : %d", max_H[1][0]);
		break;
	case 2:
		printf("W : %d", max_H[1][0]);
		break;
	case 3:
		printf("WB : %d", max_H[1][0]);
		break;
	}
	printf("\n");


	for (i = 0; i < SIZE - 2; ++i) {
		printf("¦§");
		for (j = 0; j < SIZE - 2; ++j)
			printf("¦«");
		printf("¦©");
		printf("B : %d ", nowB[0][i + 1]);
		printf("W : %d ", nowW[0][i + 1]);
		switch (max_H[0][i + 1]) {
		case 1:
			printf("B : %d\n", max_H[1][i + 1]);
			break;
		case 2:
			printf("W : %d\n", max_H[1][i + 1]);
			break;
		case 3:
			printf("WB : %d\n", max_H[1][i + 1]);
			break;
		default:
			printf("\n");
		}
	}

	printf("¦¦");
	for (i = 0; i < SIZE - 2; ++i)
		printf("¦ª");
	printf("¦¥");
	printf("B : %d ", nowB[0][18]);
	printf("W : %d ", nowW[0][18]);
	switch (max_H[0][18]) {
	case 1:
		printf("B : %d\n", max_H[1][18]);
		break;
	case 2:
		printf("W : %d\n", max_H[1][18]);
		break;
	case 3:
		printf("WB : %d\n", max_H[1][18]);
		break;
	default:
		printf("\n");
	}
	for (i = 0; i < SIZE; ++i)
		printf("B ");
	printf("\n");
	for (i = 0; i < SIZE; ++i)
		printf("%d ", nowB[1][i]);
	printf("\n");
	for (i = 0; i < SIZE; ++i)
		printf("W ");
	printf("\n");
	for (i = 0; i < SIZE; ++i)
		printf("%d ", nowW[1][i]);
	printf("\n");

	for (i = 0; i < SIZE; ++i)
		switch (max_V[0][i]) {
		case 1:
			printf("B ");
			break;
		case 2:
			printf("W ");
			break;
		case 3:
			printf("WB");
			break;
		}
	printf("\n");
	for (i = 0; i < SIZE; ++i)
		printf("%d ", max_V[1][i]);
	printf("\n");

	for (i = 0; i < SIZE; ++i)
		switch (max_D1[0][i]) {
		case 1:
			printf("B ");
			break;
		case 2:
			printf("W ");
			break;
		case 3:
			printf("WB");
			break;
		}
	printf(" D1\n");
	for (i = 0; i < SIZE; ++i)
		printf("%d ", max_D1[1][i]);
	printf("\n");

	for (i = 0; i < SIZE; ++i)
		switch (max_D2[0][i]) {
		case 1:
			printf("B ");
			break;
		case 2:
			printf("W ");
			break;
		case 3:
			printf("WB");
			break;
		}
	printf(" D2\n");
	for (i = 0; i < SIZE; ++i)
		printf("%d ", max_D2[1][i]);
	printf("\n");

	for (i = 0; i < SIZE; ++i)
		switch (max_D3[0][i]) {
		case 1:
			printf("B ");
			break;
		case 2:
			printf("W ");
			break;
		case 3:
			printf("WB");
			break;
		}
	printf(" D3\n");
	for (i = 0; i < SIZE; ++i)
		printf("%d ", max_D3[1][i]);
	printf("\n");
	for (i = 0; i < SIZE; ++i)
		switch (max_D4[0][i]) {
		case 1:
			printf("B ");
			break;
		case 2:
			printf("W ");
			break;
		case 3:
			printf("WB");
			break;
		}
	printf(" D4\n");
	for (i = 0; i < SIZE; ++i)
		printf("%d ", max_D4[1][i]);
	printf("\n");

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
		if (base[*y][(*x) / 2] == 0)
			if (count == 0) {
				base[*y][*x / 2] = 1;
				nowB[1][*x / 2]++;
				nowB[0][*y]++;
				count = 1;
			}
			else {
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
				printf("¡Û");
			}
			else if (base[i][j] == 2) {
				gotoxy(j * 2, i);
				printf("¡Ü");
			}
		}
}
void check_H(char base[][19]) {

	int maxB = 0, maxW = 0;
	int countB = 0, countW = 0;

	for (int i = 0; i < SIZE; ++i) {
		max_H[0][i] = 3;
		max_H[1][i] = 0;
	}
	for (int j = 0; j < SIZE; ++j) {
		for (int i = 0; i < SIZE; ++i) {
			if (base[j][i] == 1 && base[j][i + 1] != 1) {
				if (base[j][i + 1] == 0 && base[j][i + 2] == 1)
					++countB;
				else {
					if (countB >= maxB)
						maxB = countB + 1;
					countB = 0;
				}
			}
			else if (base[j][i] == 2 && base[j][i + 1] != 2) {
				if (base[j][i + 1] != 1 && base[j][i + 2] == 2)
					++countW;
				else {
					if (countW >= maxW)
						maxW = countW + 1;
					countW = 0;
				}
			}
			if (base[j][i] == 1 && base[j][i + 1] == 1) {
				countB++;
			}
			else if (base[j][i] == 2 && base[j][i + 1] == 2)
				countW++;
		}
		if (maxB > maxW) {
			max_H[0][j] = 1;
			max_H[1][j] = maxB;
		}
		else if (maxW > maxB) {
			max_H[0][j] = 2;
			max_H[1][j] = maxW;
		}
		else if (maxW == maxB) {
			max_H[0][j] = 3;
			max_H[1][j] = maxW;
		}
		maxB = 0; maxW = 0;
		countB = 0; countW = 0;
	}
}
void check_V(char base[][19]) {

	int maxB = 0, maxW = 0;
	int countB = 0, countW = 0;

	for (i = 0; i < SIZE; ++i) {
		max_V[0][i] = 3;
		max_V[1][i] = 0;
	}
	for (j = 0; j < SIZE; ++j) {
		for (i = 0; i < SIZE; ++i) {
			if (base[i][j] == 1 && base[i + 1][j] != 1) {
				if (base[i + 1][j] == 0 && base[i + 2][j] == 1)
					countB++;
				else {
					if (countB >= maxB)
						maxB = countB + 1;
					countB = 0;
				}
			}
			else if (base[i][j] == 2 && base[i + 1][j] != 2) {
				if (base[i + 1][j] == 0 && base[i + 2][j] == 2)
					countW++;
				else {
					if (countW >= maxW)
						maxW = countW + 1;
					countW = 0;
				}
			}
			if (base[i][j] == 1 && base[i + 1][j] == 1)
				countB++;

			else if (base[i][j] == 2 && base[i + 1][j] == 2)
				countW++;

		}
		if (maxB > maxW) {
			max_V[0][j] = 1;
			max_V[1][j] = maxB;
		}
		else if (maxW > maxB) {
			max_V[0][j] = 2;
			max_V[1][j] = maxW;
		}
		else if (maxW == maxB) {
			max_V[0][j] = 3;
			max_V[1][j] = maxW;
		}
		maxB = 0; maxW = 0;
		countB = 0; countW = 0;
	}
}

void check_D1(char base[][19]) {
	int maxB = 0, maxW = 0;
	int countB = 0, countW = 0;

	for (i = 0; i < SIZE; ++i) {
		max_D1[0][i] = 3;
		max_D1[1][i] = 0;
	}
	for (int k = 0; k < SIZE; ++k) {
		for (j = 0, i = k; j < SIZE - k; ++j, ++i) {

			if (base[i][j] == 1 && base[i + 1][j + 1] != 1) {
				if (base[i + 1][j + 1] == 0 && base[i + 2][j + 2] == 1)
					countB++;
				else {
					if (countB >= maxB)
						maxB = countB + 1;
					countB = 0;
				}
			}
			else if (base[i][j] == 2 && base[i + 1][j + 1] != 2) {
				if (base[i + 1][j + 1] == 0 && base[i + 2][j + 2] == 2)
					countW++;
				else {
					if (countW >= maxW)
						maxW = countW + 1;
					countW = 0;
				}
			}
			if (base[i][j] == 1 && base[i + 1][j + 1] == 1)
				countB++;
			else if (base[i][j] == 2 && base[i + 1][j + 1] == 2)
				countW++;
		}
		if (maxB > maxW) {
			max_D1[0][k] = 1;
			max_D1[1][k] = maxB;
		}
		else if (maxW > maxB) {
			max_D1[0][k] = 2;
			max_D1[1][k] = maxW;
		}
		else if (maxW == maxB) {
			max_D1[0][k] = 3;
			max_D1[1][k] = maxW;
		}
		maxB = 0; maxW = 0;
		countB = 0; countW = 0;
	}
}
void check_D2(char base[][19]) {
	int maxB = 0, maxW = 0;
	int countB = 0, countW = 0;

	for (i = 0; i < SIZE; ++i) {
		max_D2[0][i] = 3;
		max_D2[1][i] = 0;
	}
	for (int k = 0; k < SIZE; ++k) {
		for (j = k, i = 0; j < SIZE; ++j, ++i) {

			if (base[i][j] == 1 && base[i + 1][j + 1] != 1) {
				if (base[i + 1][j + 1] == 0 && base[i + 2][j + 2] == 1)
					++countB;
				else {
					if (countB >= maxB)
						maxB = countB + 1;
					countB = 0;
				}
			}
			else if (base[i][j] == 2 && base[i + 1][j + 1] != 2) {
				if (base[i + 1][j + 1] == 0 && base[i + 2][j + 2] == 2)
					++countW;
				else {
					if (countW >= maxW)
						maxW = countW + 1;
					countW = 0;
				}
			}
			if (base[i][j] == 1 && base[i + 1][j + 1] == 1)
				countB++;
			else if (base[i][j] == 2 && base[i + 1][j + 1] == 2)
				countW++;
		}
		if (maxB > maxW) {
			max_D2[0][k] = 1;
			max_D2[1][k] = maxB;
		}
		else if (maxW > maxB) {
			max_D2[0][k] = 2;
			max_D2[1][k] = maxW;
		}
		else if (maxW == maxB) {
			max_D2[0][k] = 3;
			max_D2[1][k] = maxW;
		}
		maxB = 0; maxW = 0;
		countB = 0; countW = 0;
	}
}
void check_D3(char base[][19]) {
	int maxB = 0, maxW = 0;
	int countB = 0, countW = 0;

	for (i = 0; i < SIZE; ++i) {
		max_D3[0][i] = 3;
		max_D3[1][i] = 0;
	}
	for (int k = 0; k < SIZE; ++k) {
		for (j = 18 - k, i = 0; i < SIZE - k; --j, ++i) {
			if (base[i][j] == 1 && base[i + 1][j - 1] != 1) {
				if (base[i + 1][j - 1] == 0 && base[i + 2][j - 2] == 1)
					++countB;
				else {
					if (countB >= maxB)
						maxB = countB + 1;
					countB = 0;
				}
			}
			else if (base[i][j] == 2 && base[i + 1][j - 1] != 2) {
				if (base[i + 1][j - 1] == 0 && base[i + 2][j - 2] == 2)
					++countW;
				else {
					if (countW >= maxW)
						maxW = countW + 1;
					countW = 0;
				}
			}
			if (base[i][j] == 1 && base[i + 1][j - 1] == 1)
				countB++;
			else if (base[i][j] == 2 && base[i + 1][j - 1] == 2)
				countW++;
		}
		if (maxB > maxW) {
			max_D3[0][k] = 1;
			max_D3[1][k] = maxB;
		}
		else if (maxW > maxB) {
			max_D3[0][k] = 2;
			max_D3[1][k] = maxW;
		}
		else if (maxW == maxB) {
			max_D3[0][k] = 3;
			max_D3[1][k] = maxW;
		}
		maxB = 0; maxW = 0;
		countB = 0; countW = 0;
	}
}
void check_D4(char base[][19]) {
	int maxB = 0, maxW = 0;
	int countB = 0, countW = 0;

	for (i = 0; i < SIZE; ++i) {
		max_D4[0][i] = 3;
		max_D4[1][i] = 0;
	}
	for (int k = 0; k < SIZE; ++k) {
		for (j = 18, i = k; i < SIZE; --j, ++i) {
			if (base[i][j] == 1 && base[i + 1][j - 1] != 1) {
				if (base[i + 1][j - 1] == 0 && base[i + 2][j - 2] == 1)
					++countB;
				else {
					if (countB >= maxB)
						maxB = countB + 1;
					countB = 0;
				}
			}
			else if (base[i][j] == 2 && base[i + 1][j - 1] != 2) {
				if (base[i + 1][j - 1] == 0 && base[i + 2][j - 2] == 2)
					++countW;
				else {
					if (countW >= maxW)
						maxW = countW + 1;
					countW = 0;
				}
			}
			if (base[i][j] == 1 && base[i + 1][j - 1] == 1)
				countB++;
			else if (base[i][j] == 2 && base[i + 1][j - 1] == 2)
				countW++;
		}
		if (maxB > maxW) {
			max_D4[0][k] = 1;
			max_D4[1][k] = maxB;
		}
		else if (maxW > maxB) {
			max_D4[0][k] = 2;
			max_D4[1][k] = maxW;
		}
		else if (maxW == maxB) {
			max_D4[0][k] = 3;
			max_D4[1][k] = maxW;
		}
		maxB = 0; maxW = 0;
		countB = 0; countW = 0;
	}
}
