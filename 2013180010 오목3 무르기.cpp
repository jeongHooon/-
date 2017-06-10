#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define SIZE 19

void gotoxy(int x, int y);
void Draw_Base();
void inputKey(char, int *, int *);
void Draw_Stone();
void stack_Pop(bool);
void stack_Push(int, int, int, bool);
void stone_Cancle();
void stone_C_Cancle();
void save_All();
void read_All();
typedef struct cancle {
	int x;
	int y;
	int count;
}cancle;

char base[SIZE][SIZE] = { 0 };
cancle Scancle[361] = { 0 };
cancle Sccancle[361] = { 0 };
int count = 0, i = 0, j = 0, state = 0;
int stackCount = 0, stackCCount = 0;
int main() {
	char base[SIZE][SIZE] = { 0 };
	base[19][19] = 0;
	int x = 0, y = 0;
	char Key = 0;
	Draw_Base();
	gotoxy(x, y);
	while (Key != 27) {
		Key = getch();
		inputKey(Key, &x, &y);
		system("cls");
		gotoxy(0, 0);
		Draw_Base();
		Draw_Stone();
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
	for (i = 0; i < 17; ++i)
		printf("¦¨");
	printf("¦¤");
	printf("\n");
	for (i = 0; i < SIZE - 2; ++i) {
		printf("¦§");
		for (j = 0; j < SIZE - 2; ++j)
			printf("¦«");
		printf("¦©");
		printf("\n");
	}

	printf("¦¦");
	for (i = 0; i < SIZE - 2; ++i)
		printf("¦ª");
	printf("¦¥");
	printf("\n");

}
void inputKey(char Key, int *x, int *y) {
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
		if (base[*y][(*x) / 2] == 0) {
			base[*y][*x / 2] = count + 1;
			stack_Push(*x / 2, *y, count, true);
			for (i = stackCCount; i >0; --i) {
				Sccancle[stackCCount - 1].x = 0;
				Sccancle[stackCCount - 1].y = 0;
				Sccancle[stackCCount - 1].count = 0;
				--stackCCount;
			}
			count = (count + 1) % 2;
		}
		break;
	case 'u':
		if (stackCount != 0)
			stone_Cancle();
		break;
	case 'r':
		if (stackCCount != 0)
			stone_C_Cancle();
		break;
	case 's':
		save_All();
		break;
	case 'q':
		read_All();
	}

}
void Draw_Stone() {
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
void stack_Push(int x, int y, int count, bool a) {
	if (a) {
		Scancle[stackCount].x = x;
		Scancle[stackCount].y = y;
		Scancle[stackCount].count = count;
		++stackCount;
	}
	else {
		Sccancle[stackCCount].x = x;
		Sccancle[stackCCount].y = y;
		Sccancle[stackCCount].count = count;
		++stackCCount;
	}
}
void stack_Pop(bool a) {
	if (a) {
		stack_Push(Scancle[stackCount - 1].x, Scancle[stackCount - 1].y, Scancle[stackCount - 1].count,false);
		Scancle[stackCount-1].x = 0;
		Scancle[stackCount-1].y = 0;
		Scancle[stackCount-1].count = 0;
		--stackCount;
	}
	else {
		stack_Push(Sccancle[stackCCount - 1].x, Sccancle[stackCCount - 1].y, Sccancle[stackCCount - 1].count,true);
		Sccancle[stackCCount].x = 0;
		Sccancle[stackCCount].y = 0;
		Sccancle[stackCCount].count = 0;
		--stackCCount;
	}
}
void stone_Cancle() {
	base[Scancle[stackCount - 1].y][Scancle[stackCount - 1].x] = 0;
	count = (count + 1) % 2;
	stack_Pop(true);
}
void stone_C_Cancle() {
	base[Sccancle[stackCCount - 1].y][Sccancle[stackCCount - 1].x] = Sccancle[stackCCount - 1].count+1;
	count = (count + 1) % 2;
	stack_Pop(false);
}
void save_All() {
	int i, j;
	FILE *fp = fopen("save.txt", "w");
	for (i = 0; i < SIZE; ++i) {
		for (j = 0; j < SIZE; ++j)
			fprintf(fp,"%d ", base[i][j]);
		fprintf(fp,"\n");
	}
	fprintf(fp, "%d",count);
	fprintf(fp, "\n");
	fprintf(fp, "%d", stackCount);
	fprintf(fp, "\n");
	for (i = 0; i < stackCount; ++i) 
		fprintf(fp, "%d %d %d ", Scancle[i].x, Scancle[i].y, Scancle[i].count);
	fprintf(fp, "\n");
	fprintf(fp, "%d", stackCCount);
	fprintf(fp, "\n");
	for (i = 0; i < stackCCount; ++i)
		fprintf(fp, "%d %d %d ", Sccancle[i].x, Sccancle[i].y, Sccancle[i].count);
	fclose(fp);
}
void read_All() {
	int i, j;
	FILE *fp = fopen("save.txt", "r");
	for (i = 0; i < SIZE; ++i) 
		for (j = 0; j < SIZE; ++j)
			fscanf(fp, "%d ", &base[i][j]);
	fscanf(fp, "%d", &count);
	fscanf(fp, "%d", &stackCount);
	for (i = 0; i < stackCount; ++i)
		fscanf(fp, "%d %d %d ", &Scancle[i].x, &Scancle[i].y, &Scancle[i].count);
	fscanf(fp, "%d", &stackCCount);
	for (i = 0; i < stackCCount; ++i)
		fscanf(fp, "%d %d %d ", &Sccancle[i].x, &Sccancle[i].y, &Sccancle[i].count);
	fclose(fp);
}