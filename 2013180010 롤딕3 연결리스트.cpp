#include<stdio.h>
#include<string.h>

typedef struct champ {
	char name[20];
	int hp;
	int mp;
	double speed;
	int range;
	char pos[20];
}champ;
typedef struct Lchamp {
	char name[20];
	int hp;
	int mp;
	double speed;
	int range;
	char pos[20];
	Lchamp *next;
}Lchamp;
void arraylinkedlist();
bool Search_SL(char *, bool state);
void Insert_SL(char *);
void Delete_SL();
void DeleteAll_SL();
void PrintAll_SL();
void PrintAll_SL_Rev(Lchamp *p);
void FindMaxHp_SL();
void SortByHp_SL();
Lchamp *head = new Lchamp;
Lchamp *tail = new Lchamp;
Lchamp *cur = new Lchamp;
Lchamp *prv = new Lchamp;
Lchamp *Dp = new Lchamp, *Dpv;
char In_info[20];
int i = 0, j = 0, count = 32, AC = 0, SC = 0, PC = 0;
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
int main() {
	bool state;
	int select;
	for (i = 0; i < 32; ++i)
		if (info[i].hp == 0)
			strcpy(info[i].name, "0");
	arraylinkedlist();
	while (1) {
		select = 0;
		printf("1. search\n2. Insert\n3. Delete\n4. Delete All[pos]\n5. Print All\n6. Print All(rev)\n7. Find Max Hp\n8. Sort By Hp\n선택하시오 : ");
		scanf("%d", &select);
		rewind(stdin);

		switch (select)
		{
		case 1:
			printf("찾을 챔피언 이름을 입력 : ");
			scanf("%[^\n]s", In_info);
			Search_SL(In_info, true);
			break;
		case 2:
			printf("추가할 챔피언");
			scanf("%[^\n]s", In_info);
			if (!Search_SL(In_info, false))
				printf("중복\n");
			else
				Insert_SL(In_info);
			break;
		case 3:
			printf("제거할 챔피언 입력 : ");
			scanf("%s", In_info);
			if (Search_SL(In_info, false))
				;
			else
				Delete_SL();
			break;
		case 4:
			printf("제거할 포지션 입력 : ");
			scanf("%s", In_info);
			DeleteAll_SL();
			break;
		case 5:
			PrintAll_SL();
			break;
		case 6:
			PrintAll_SL_Rev(head->next);
			PC = 0;
			break;
		case 7:
			FindMaxHp_SL();
			break;
		case 8:
			SortByHp_SL();
			break;
		default:
			break;
		}
	}

}
void arraylinkedlist() {
	Lchamp *node = NULL;
	head->next = head;
	for (i = 0; strcmp(info[i].name, "0") != 0; ++i) {
		node = new Lchamp;

		strcpy(node->name, info[i].name);
		node->hp = info[i].hp;
		node->mp = info[i].mp;
		node->range = info[i].range;
		node->speed = info[i].speed;
		strcpy(node->pos, info[i].pos);
		if (i == 0) {
			head->next = node;
			tail->next = node;
		}
		tail->next->next = node;
		node->next = head->next;
		head->next = node;
		++AC;
	}
}
void PrintAll_SL() {
	Lchamp *cur;
	cur = head->next;
	while (PC != AC) {
		printf("==================\n");
		printf("이름 : %s\nHp: %d\nMp : %d\nspd : %f\nrange : %d\npos : %s\n", cur->name, cur->hp, cur->mp, cur->speed, cur->range, cur->pos);
		printf("==================\n");
		cur = cur->next;
		++PC;
	}
	PC = 0;
}
void PrintAll_SL_Rev(Lchamp *p) {
	Lchamp *cur;
	cur = p;
	while (PC != AC) {
		++PC;
		PrintAll_SL_Rev(cur->next);
		printf("==================\n");
		printf("이름 : %s\nHp: %d\nMp : %d\nspd : %f\nrange : %d\npos : %s\n", cur->name, cur->hp, cur->mp, cur->speed, cur->range, cur->pos);
		printf("==================\n");
	}
}
bool Search_SL(char *In_info, bool state) {
	Lchamp *cur = new Lchamp;
	Dpv = new Lchamp;
	cur->next = head->next;
	Dpv->next = tail->next;
	for (i = 0; i < AC; ++i) {
		if (strcmp(cur->next->name, In_info) == 0) {
			if (state)
				printf("이름 : %s\nHp: %d\nMp : %d\nspd : %f\nrange : %d\npos : %s\n", cur->next->name, cur->next->hp, cur->next->mp, cur->next->speed, cur->next->range, cur->next->pos);
			Dp->next = cur->next;
			return false;
		}

		Dpv->next = cur->next;
		cur->next = cur->next->next;
	}
	return true;
}
void Insert_SL(char *In_info) {

	Lchamp *node = new Lchamp;
	printf("체력 마나 속도 사거리 포지션 순으로 입력 : ");
	scanf("%d %d %lf %d %s", &node->hp, &node->mp, &node->speed, &node->range, node->pos);
	strcpy(node->name, In_info);
	if (node->hp > head->next->hp) {
		node->next = head->next;
		head->next = node;
		tail->next->next = node;
	}
	else if (node->hp < tail->next->hp) {
		node->next = head->next;
		tail->next->next = node;
		tail->next = node;
	}
	else {
		cur->next = head->next;
		while (cur->next != tail->next) {
			if (node->hp <= cur->next->hp && node->hp >= cur->next->next->hp) {
				node->next = cur->next->next;
				cur->next->next = node;
				break;
			}
			cur->next = cur->next->next;
		}
	}
	AC++;
}
void Delete_SL() {
	if (Dp->next == head->next) {
		Dpv->next->next = Dp->next->next;
		head->next = Dpv->next->next;
	}
	else if (Dp->next == tail->next) {
		Dpv->next->next = Dp->next->next;
		tail->next = Dpv->next;
	}
	else
		Dpv->next->next = Dp->next->next;
	--AC;
}
void DeleteAll_SL() {
	int a = AC;
	cur->next = head->next;
	prv->next = tail->next;
	for (i = 0; i < a; ++i) {
		if (strcmp(cur->next->pos, In_info) == 0) {
			if (cur->next == head->next) {
				prv->next->next = cur->next->next;
				--AC;
				cur->next = cur->next->next;
				head->next = cur->next;
			}
			else if (cur->next == tail->next) {
				tail->next = prv->next;
				prv->next->next = head->next;
				--AC;
				cur->next = cur->next->next;
			}
			else {
				prv->next->next = cur->next->next;
				--AC;
				cur->next = cur->next->next;
			}
		}
		else {
			cur->next = cur->next->next;
			prv->next = prv->next->next;
		}
	}
}
void FindMaxHp_SL() {
	int max = 0;
	cur->next = head->next;
	for (i = 0; i<AC; ++i) {
		if (cur->next->hp > max)
			max = cur->next->hp;
		cur->next = cur->next->next;
	}
	for (i = 0; i < AC; ++i) {
		if (cur->next->hp == max)
			printf("%s %d\n", cur->next->name, cur->next->hp);
		cur->next = cur->next->next;
	}
}
void SortByHp_SL() {
	for (i = 0; i < AC; ++i) {
		cur->next = head->next;
		prv->next = tail->next;
		for (j = 1; j < AC; ++j) {
			if (cur->next->hp < cur->next->next->hp) {
				if (cur->next->next == tail->next) {
					prv->next->next = cur->next->next;
					cur->next->next = cur->next->next->next;
					prv->next->next->next = cur->next;
					prv->next = prv->next->next;
					tail->next = cur->next;
				}
				else if (cur->next == head->next) {
					prv->next->next = cur->next->next;
					cur->next->next = cur->next->next->next;
					prv->next->next->next = cur->next;
					prv->next = prv->next->next;
					head->next = prv->next;
				}
				else {
					prv->next->next = cur->next->next;
					cur->next->next = cur->next->next->next;
					prv->next->next->next = cur->next;
					prv->next = prv->next->next;
				}
			}
			else {
				prv->next = cur->next;
				cur->next = cur->next->next;
			}
		}
	}
}