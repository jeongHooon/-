#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
#define SIZE 32

void search(char *, int);
void insult(char *, int);
void delete_C(char *, int);
void delete_All(char *, int);
void print_All(int);
void Find_max_Hp(int, int);
void Print_max_Hp(int, int);
void sort_Hp(int, int);
int check(char *, int);
char In_info[20];
int r = 0, i = 0, j = 0, max = 0;

typedef struct champ {
	char name[20];
	int hp;
	int mp;
	double speed;
	int range;
	char pos[20];
}champ;

champ info[40] = {
	{ "가렌", 551, 0, 55.5, 150, "탑" },
	{ "갱플랭크", 576, 255, 57, 150, "탑" },
	{ "그라가스", 523, 268, 59.2, 150, "탑" },
	{ "그레이브즈", 494, 295, 54.1, 450, "원딜" },
	{ "나미", 439, 348, 51.1, 500, "서포터" },
	{ "나서스", 501, 245, 56.8, 100, "탑" },
	{ "노틸러스",518, 250, 55.3, 200, "정글" },
	{ "녹턴", 525, 250, 57.1, 210, "정글" },
	{ "누누", 533, 255, 54.5, 120, "정글" },
	{ "니달리", 461, 265, 52.5, 430, "정글" },
	{ "다리우스", 519, 237, 53.5, 130, "탑" },
	{ "다이애나", 528, 270, 51, 170, "미드" },
	{ "드레이븐", 502, 282, 50, 420, "원딜" },
	{ "라이즈", 498, 305, 55, 400, "탑" },
	{ "람머스", 506, 288, 53.5, 110, "탑" },
	{ "럭스", 424, 300, 53.3, 500, "미드" },
	{ "럼블", 530, 100, 58.9, 120, "탑" },
	{ "레넥톤", 513, 100, 56.2, 100, "탑" },
	{ "레오나", 517, 275, 58, 100, "서포터" },
	{ "렝가", 520, 5, 58 ,130, "정글" },
	{ "루시안", 470, 271, 49, 550, "원딜" },
	{ "룰루", 497, 255, 46.6, 450, "탑" },
	{ "르블랑", 465, 300, 54.5, 550, "미드" },
	{ "리신", 515, 200, 59, 120, "정글" },
	{ "리븐", 500, 0, 54, 170, "탑" },
	{ "리산드라", 449, 270, 50.7, 450, "탑" },
	{ "마스터이", 536, 222, 58, 130, "정글" },
	{ "마오카이", 511, 296, 61.3, 120, "탑" },
	{ "말자하", 460, 295, 54.7, 520, "미드" },
	{ "말파이트", 514, 255, 59.7, 110, "탑" }

};

int main() {
	int select;

	while (1) {
		select = 0;
		for (i = 0; i < SIZE; ++i)
			if (info[i].hp == 0)
				strcpy(info[i].name, "0");
		printf("1. search\n2. Insert\n3. Delete\n4. Delete All[pos]\n5. Print All\n6. Find Max Hp\n7. Sort By Hp\n선택하시오 : ");
		scanf("%d", &select);
		rewind(stdin);

		switch (select)
		{
		case 1:
			printf("찾을 챔피언의 이름을 입력 : ");
			scanf("%[^\n]s", In_info);
			rewind(stdin);
			search(In_info, 0);
			break;
		case 2:
			printf("추가할 챔피언의 이름을 입력 : ");
			scanf("%[^\n]s", In_info);
			rewind(stdin);
			switch (check(In_info, 0)) {
			case 0:
				break;
			case 1:
				insult(In_info, 0);

			}
			break;
		case 3:
			printf("제거할 챔피언의 이름을 입력 : ");
			scanf("%[^\n]s", In_info);
			rewind(stdin);
			delete_C(In_info, 0);
			break;
		case 4:
			printf("제거할 포지션의 이름을 입력 : ");
			scanf("%[^\n]s", In_info);
			rewind(stdin);
			delete_All(In_info, 0);
			break;
		case 5:
			print_All(0);
			break;
		case 6:
			Find_max_Hp(0, 0);
			break;
		case 7:
			sort_Hp(0, 0);
			break;
		default:
			break;
		}
	}
}
void search(char *In_info, int r) {
	if (strcmp(In_info, info[r].name) == 0)
		printf("챔피언 : %s\nHp : %d\nMp : %d\nSpeed : %f\nRange : %d\nPos : %s\n", info[r].name, info[r].hp, info[r].mp, info[r].speed, info[r].range, info[r].pos);
	else if (r < SIZE)
		search(In_info, r + 1);
}
void insult(char *In_info, int r) {
	if (strcmp(info[r].name, "0") == 0) {
		strcpy(info[r].name, In_info);
		printf("체력 마나 속도 거리 포지션 순으로 입력 : ");
		scanf("%d %d %lf %d %s", &info[r].hp, &info[r].mp, &info[r].speed, &info[r].range, info[r].pos);
	}
	else if (r < SIZE)
		insult(In_info, r + 1);
}
void delete_C(char *In_info, int r) {
	if (strcmp(In_info, info[r].name) == 0)
		strcpy(info[r].name, "0");
	else if (r < SIZE)
		delete_C(In_info, r + 1);
}
void delete_All(char *In_info, int r) {
	if (r < SIZE)
		delete_All(In_info, r + 1);
	if (strcmp(In_info, info[r].pos) == 0)
		strcpy(info[r].name, "0");
}
void print_All(int r) {
	if (strcmp(info[r].name, "0") != 0 && r < SIZE) {
		printf("=================\n");
		printf("챔피언 : %s\nHp : %d\nMp : %d\nSpeed : %f\nRange : %d\nPos : %s\n", info[r].name, info[r].hp, info[r].mp, info[r].speed, info[r].range, info[r].pos);
		printf("=================\n");
	}
	if (r < SIZE)
		print_All(r + 1);
}
void Find_max_Hp(int max, int r) {
	if (info[r].hp>max && strcmp(info[r].name, "0") != 0 && r < SIZE) {
		max = info[r].hp;
		Find_max_Hp(max, r + 1);
	}
	else if (r < SIZE)
		Find_max_Hp(max, r + 1);
	else
		Print_max_Hp(max, 0);
}
void Print_max_Hp(int max, int r) {
	if (info[r].hp == max && strcmp(info[r].name, "0") != 0 && r < SIZE)
		printf("챔피언 : %s\nHp : %d\n", info[r].name, info[r].hp);
	if (r < SIZE)
		Print_max_Hp(max, r + 1);
}

void sort_Hp(int i, int j) {
	champ tmp;
	if (j < SIZE - i&& i < SIZE) {
		if (info[j].hp < info[j + 1].hp) {
			tmp = info[j + 1]; info[j + 1] = info[j]; info[j] = tmp;
		}
		sort_Hp(i, j + 1);
	}
	else if (i < SIZE)
		sort_Hp(i + 1, 0);
}


int check(char *In_info, int r) {
	if (strcmp(In_info, info[r].name) == 0) {
		printf("중복\n");
		return 0;
	}
	else if (r < SIZE) {
		check(In_info, r + 1);

	}
	else
		return 1;
}