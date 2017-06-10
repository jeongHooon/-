#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct champ {
	char name[20];
	int hp;
	int mp;
	double speed;
	int range;
	char pos[20];
}champ;
char In_info[20];
int i = 0, j = 0, count = 32;
champ info[32] = {
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
void search();
void insult();
void delete_C();
void delete_All();
void print_All();
void max_Hp();
void sort_Hp();
int check(char *In_info);
int main() {
	int select;

	while (1) {
		select = 0;
		for (i = 0; i < 32; ++i)
			if (info[i].hp == 0)
				strcpy(info[i].name, "0");
		printf("1. search\n2. Insert\n3. Delete\n4. Delete All[pos]\n5. Print All\n6. Find Max Hp\n7. Sort By Hp\n선택하시오 : ");
		scanf("%d", &select);
		rewind(stdin);

		switch (select) {
		case 1:
			search();
			break;
		case 2:
			insult();
			break;
		case 3:
			delete_C();
			break;
		case 4:
			delete_All();
			break;
		case 5:
			print_All();
			break;
		case 6:
			max_Hp();
			break;
		case 7:
			sort_Hp();
			break;
		}
	}
}
void search() {
	printf("검색할 챔피언 : ");
	scanf("%[^\n]s", In_info);
	rewind(stdin);

	for (i = 0; i < 32; ++i)
		if (strcmp(info[i].name, In_info) == 0) {
			printf("===============\n");
			printf("이름 : %s\n체력 : %d\n 마나 : %d\n 이동속도 : %f\n사거리 : %d\n포지션 : %s\n", info[i].name, info[i].hp, info[i].mp, info[i].speed, info[i].range, info[i].pos);
			printf("===============\n");
		}
}
void insult(){
	printf("추가할 챔피언 : ");
	scanf("%[^\n]s", In_info);
	rewind(stdin);

	switch (check(In_info)) {
	case 0:
		break;
	case 1:
		for (i = 0; i < 32; ++i)
			if (strcmp(info[i].name, "0") == 0) {
				strcpy(info[i].name, In_info);
				printf("체력 마나 속도 거리 포지션 순으로 입력 : ");
				scanf("%d %d %lf %d %s", &info[i].hp, &info[i].mp, &info[i].speed, &info[i].range, info[i].pos);
				rewind(stdin);
				break;
			}
	}
}
void delete_C(){
	printf("삭제할 챔피언 입력 : ");
	scanf("%[^\n]s", In_info);

	for (i = 0; i < 32; ++i)
		if (strcmp(info[i].name, In_info) == 0) {
			strcpy(info[i].name, "0");
			break;
		}

}
void delete_All(){
	printf("삭제할 포지션 입력 : ");
	scanf("%[^\n]s", In_info);

	for (i = 0; i < 32; ++i)
		if (strcmp(info[i].pos, In_info) == 0)
			strcpy(info[i].name, "0");
}
void print_All(){
	for (i = 0; i < 32; ++i)
		if (strcmp(info[i].name, "0") != 0) {
			printf("===============\n");
			printf("이름 : %s\n체력 : %d\n 마나 : %d\n 이동속도 : %f\n사거리 : %d\n포지션 : %s\n", info[i].name, info[i].hp, info[i].mp, info[i].speed, info[i].range, info[i].pos);
			printf("===============\n");
		}

}
void max_Hp(){
	int max = 0;
	for (i = 0; i < 32; ++i) 
		if (info[i].hp>max)
			max = info[i].hp;
	for (i = 0; i < 32; ++i)
		if (info[i].hp == max)
			printf("%s %d\n", info[i].name,info[i].hp);	
}
void sort_Hp() {
	int check(char *In_info);
	champ tmp;

		for (i = 0; i < count - 1; ++i)
			for (j = 0; j < count - i - 1; ++j)
				if (info[j].hp < info[j + 1].hp) {
					tmp = info[j + 1];
					info[j + 1] = info[j];
					info[j] = tmp;
				}
	}
int check(char *In_info) {
	for (i = 0; i < 32; ++i)
		if (strcmp(info[i].name, In_info) == 0) {
			printf("중복된 챔피언입니다.\n");
			return 0;
		}
	return 1;
}
