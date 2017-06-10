#include<stdio.h>
int main() {
	int i, j, x=111, y=111, count = 0;
	char base[19][19];
	int chga = 97;
	for (i = 0; i < 361; ++i)
		base[0][i] = '+';
	while (1) {
		system("cls");
		for (i = 0; i < 19; ++i) {
			for (j = 0; j < 19; ++j)
				printf("%c ", base[i][j]);
			printf("\n");
		}
		printf("%c", chga);
		printf("흑돌(o)의 수 : %d 백돌(x)의 수 : %d\n", count / 2 + count % 2, count / 2);
		printf("놓을 수의 좌표를 입력하시오(x y) : ");
		scanf("%d %d", &x ,&y);
		rewind(stdin);
		if (x > 18 || y > 18)
			;		
		else if (base[y][x] == '+') {
			if (count % 2 == 0) {
				base[y][x] = 'o';
				++count;
			}
			else {
				base[y][x] = 'x';
				++count;
			}
		}
		

	}

}