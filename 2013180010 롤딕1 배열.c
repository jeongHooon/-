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
	{ "����", 551, 0, 55.5, 150, "ž" },
	{ "���÷�ũ", 576, 255, 57, 150, "ž" },
	{ "�׶󰡽�", 523, 268, 59.2, 150, "ž" },
	{ "�׷��̺���", 494, 295, 54.1, 450, "����" },
	{ "����", 439, 348, 51.1, 500, "������" },
	{ "������", 501, 245, 56.8, 100, "ž" },
	{ "��ƿ����",518, 250, 55.3, 200, "����" },
	{ "����", 525, 250, 57.1, 210, "����" },
	{ "����", 533, 255, 54.5, 120, "����" },
	{ "�ϴ޸�", 461, 265, 52.5, 430, "����" },
	{ "�ٸ��콺", 519, 237, 53.5, 130, "ž" },
	{ "���ֳ̾�", 528, 270, 51, 170, "�̵�" },
	{ "�巹�̺�", 502, 282, 50, 420, "����" },
	{ "������", 498, 305, 55, 400, "ž" },
	{ "���ӽ�", 506, 288, 53.5, 110, "ž" },
	{ "����", 424, 300, 53.3, 500, "�̵�" },
	{ "����", 530, 100, 58.9, 120, "ž" },
	{ "������", 513, 100, 56.2, 100, "ž" },
	{ "������", 517, 275, 58, 100, "������" },
	{ "����", 520, 5, 58 ,130, "����" },
	{ "��þ�", 470, 271, 49, 550, "����" },
	{ "���", 497, 255, 46.6, 450, "ž" },
	{ "�����", 465, 300, 54.5, 550, "�̵�" },
	{ "����", 515, 200, 59, 120, "����" },
	{ "����", 500, 0, 54, 170, "ž" },
	{ "������", 449, 270, 50.7, 450, "ž" },
	{ "��������", 536, 222, 58, 130, "����" },
	{ "����ī��", 511, 296, 61.3, 120, "ž" },
	{ "������", 460, 295, 54.7, 520, "�̵�" },
	{ "������Ʈ", 514, 255, 59.7, 110, "ž" }

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
		printf("1. search\n2. Insert\n3. Delete\n4. Delete All[pos]\n5. Print All\n6. Find Max Hp\n7. Sort By Hp\n�����Ͻÿ� : ");
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
	printf("�˻��� è�Ǿ� : ");
	scanf("%[^\n]s", In_info);
	rewind(stdin);

	for (i = 0; i < 32; ++i)
		if (strcmp(info[i].name, In_info) == 0) {
			printf("===============\n");
			printf("�̸� : %s\nü�� : %d\n ���� : %d\n �̵��ӵ� : %f\n��Ÿ� : %d\n������ : %s\n", info[i].name, info[i].hp, info[i].mp, info[i].speed, info[i].range, info[i].pos);
			printf("===============\n");
		}
}
void insult(){
	printf("�߰��� è�Ǿ� : ");
	scanf("%[^\n]s", In_info);
	rewind(stdin);

	switch (check(In_info)) {
	case 0:
		break;
	case 1:
		for (i = 0; i < 32; ++i)
			if (strcmp(info[i].name, "0") == 0) {
				strcpy(info[i].name, In_info);
				printf("ü�� ���� �ӵ� �Ÿ� ������ ������ �Է� : ");
				scanf("%d %d %lf %d %s", &info[i].hp, &info[i].mp, &info[i].speed, &info[i].range, info[i].pos);
				rewind(stdin);
				break;
			}
	}
}
void delete_C(){
	printf("������ è�Ǿ� �Է� : ");
	scanf("%[^\n]s", In_info);

	for (i = 0; i < 32; ++i)
		if (strcmp(info[i].name, In_info) == 0) {
			strcpy(info[i].name, "0");
			break;
		}

}
void delete_All(){
	printf("������ ������ �Է� : ");
	scanf("%[^\n]s", In_info);

	for (i = 0; i < 32; ++i)
		if (strcmp(info[i].pos, In_info) == 0)
			strcpy(info[i].name, "0");
}
void print_All(){
	for (i = 0; i < 32; ++i)
		if (strcmp(info[i].name, "0") != 0) {
			printf("===============\n");
			printf("�̸� : %s\nü�� : %d\n ���� : %d\n �̵��ӵ� : %f\n��Ÿ� : %d\n������ : %s\n", info[i].name, info[i].hp, info[i].mp, info[i].speed, info[i].range, info[i].pos);
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
			printf("�ߺ��� è�Ǿ��Դϴ�.\n");
			return 0;
		}
	return 1;
}
