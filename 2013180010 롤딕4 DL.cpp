#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

typedef struct info {
	char pos[10];
	char name[15];
	int hp;
	int att;
	int def;
	info *next;
	info *prv;
}info;
typedef struct CP {
	info *head;
}CP;
void PrintAll_SL(CP* CPa);
void PrintAll_SL1(CP* CPa);
bool Search_SL(char *, CP* CPa);
void Insert_SL(char *, CP* CPa);
void FindMaxHp_SL(CP* CPa);
CP* loadtxt(CP* CPa);
void MergeSort(info** headRef);
info *SortedMerge(info* a, info* b);
void FrontBackSplit(info* source, info** frontRef, info** backRef);
int i, j;
char In_info[20];
info *head = new info;
info *tail = new info;
info *cur = new info;
info *prv = new info;
info info_champ[10] = { 0 };
int main() {
	int select;
	CP* CPa = new CP;
	CPa->head = NULL;
	clock_t start, end;
	start = clock();
	loadtxt(CPa);
	end = clock();
	printf("%.3lf초\n", (end - start) / (double)1000);
	printf("%d개\n",j-1);
	while (1) {
		select = 0;
		printf("1. PrintAll_SL\n2. Insert\n3. Find Max Hp\n4. Sort By Hp\n선택하시오 : ");
		scanf("%d", &select);
		rewind(stdin);

		switch (select)
		{
		case 1:
			start = clock();
			PrintAll_SL(CPa);
			end = clock();
			printf("%.3lf초\n", (end - start) / (double)1000);
			break;
		case 2:
			printf("추가할 챔피언");
			scanf("%[^\n]s", In_info);
			if (!Search_SL(In_info, CPa))
				printf("중복\n");
			else {
				start = clock();
				Insert_SL(In_info, CPa);
				end = clock();
				printf("%.3lf초\n", (end - start) / (double)1000);
			}
			break;
		case 3:
			start = clock();
			FindMaxHp_SL(CPa);
			end = clock();
			printf("%.3lf초\n", (end - start) / (double)1000);
			break;
		case 4:
			start = clock();
			MergeSort(&CPa->head);
			end = clock();
			printf("%.3lf초\n", (end - start) / (double)1000);
			printf("%s %s %s", CPa->head->name, CPa->head->next->name, CPa->head->next->prv->name);
			break;
		case 5:
			PrintAll_SL1(CPa);
		default:
			break;
		}
	}
}
CP* loadtxt(CP* CPa) {

	FILE *fp = fopen("LOLDic.txt", "r");
	info *node = NULL;

	while (!feof(fp)) {
		node = new info;
		fscanf(fp, "%s %s %d %d %d", node->pos, node->name, &node->hp, &node->att, &node->def);
		if (CPa->head == NULL) {
			CPa->head = node;
			node->prv = NULL;
			node->next = NULL;
		}
		else {
			CPa->head->prv = node;
			node->next = CPa->head;
			node->prv = NULL;
			CPa->head = node;
		}
		++j;
	}
	fclose(fp);
	return CPa;
}
void PrintAll_SL(CP* CPa) {
	cur->next = CPa->head;
	while (cur->next != NULL) {
		printf("==================\n");
		printf("Pos : %s\nName: %s\nHP : %d\nAtt : %d\nDef : %d\n", cur->next->pos, cur->next->name, cur->next->hp, cur->next->att, cur->next->def);
		printf("==================\n");
		cur->next = cur->next->next;;
	}
}
void PrintAll_SL1(CP* CPa) {
	cur->next = CPa->head;
	while (i < 10000) {
		printf("==================\n");
		printf("Pos : %s\nName: %s\nHP : %d\nAtt : %d\nDef : %d\n", cur->next->pos, cur->next->name, cur->next->hp, cur->next->att, cur->next->def);
		printf("==================\n");
		cur->next = cur->next->next;;
		++i;
	}
}
bool Search_SL(char *In_info, CP* CPa) {
	cur->next = CPa->head;
	while (cur->next != NULL) {
		if (strcmp(cur->next->name, In_info) == 0) {
			return false;
		}
		cur->next = cur->next->next;
	}
	return true;
}
void Insert_SL(char *In_info, CP* CPa) {

	info *node = new info;
	printf("포지션 체력 공격력 방어력 순으로 입력 : ");
	scanf("%s %d %d %d", node->pos, &node->hp, &node->att, &node->def);
	strcpy(node->name, In_info);
	CPa->head->prv = node;
	node->next = CPa->head;
	node->prv = NULL;
	CPa->head = node;
}
void FindMaxHp_SL(CP* CPa) {
	int max = 0;
	cur->next = CPa->head;;
	while (cur->next != NULL) {
		if (cur->next->hp > max)
			max = cur->next->hp;
		cur->next = cur->next->next;
	}
	cur->next = CPa->head;
	while (cur->next != NULL) {
		if (cur->next->hp == max) {
			printf("==================\n");
			printf("Pos : %s\nName: %s\nHP : %d\nAtt : %d\nDef : %d\n", cur->next->pos, cur->next->name, cur->next->hp, cur->next->att, cur->next->def);
			printf("==================\n");			
		}
		cur->next = cur->next->next;
	}
}
void MergeSort(info** headRef)
{
	info* head = *headRef;
	info* a;
	info* b;

	if ((head == NULL) || (head->next == NULL))
		return;

	FrontBackSplit(head, &a, &b);

	MergeSort(&a);
	MergeSort(&b);

	*headRef = SortedMerge(a, b);
}

info* SortedMerge(info* a, info* b)
{
	info* result = NULL;
	info* p;
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);
	if (strcmp(a->name, b->name) <= 0) {
		result = a;
		a = a->next;
	}
	else {
		result = b;
		b = b->next;
	}
	p = result;
	while (a != NULL && b != NULL)
		if (strcmp(a->name, b->name) <= 0)
		{
			p->next = a;
			a->prv = p;
			a = a->next;
			p = p->next;
		}
		else
		{
			p->next = b;
			b->prv = p;
			b = b->next;
			p = p->next;
		}

	if (a == NULL) {
		p->next = b;
		b->prv = p;
	}

	else {
		p->next = a;
		a->prv = p;
	}

	return(result);
}


void FrontBackSplit(info* source, info** frontRef, info** backRef)
{
	info* fast;
	info* slow;
	if (source == NULL || source->next == NULL)
	{
		*frontRef = source;
		*backRef = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;

		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}

		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
	}
}