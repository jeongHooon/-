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
	info *root;
	info *left;
	info *right;
}info;
typedef struct CP {
	info *head;
}CP;
void PrintAll_BT(info* CPa);
void Print_BT(info* CPa);
bool Search_BT(char*, info*, bool);
void Insert_BT(info** node, CP* CPa);
void Delete_BT(CP** CPa);
CP* loadtxt(CP* CPa);
int i, j;
char In_info[20];
info *head = new info;
info *tail = new info;
CP *cur = new CP;
CP *DP = new CP;
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
	while (1) {
		select = 0;
		printf("1. PrintAll_BT\n2. Insert\n3. Search \n4. Delete\n선택하시오 : ");
		scanf("%d", &select);
		rewind(stdin);

		switch (select)
		{
		case 1:
			start = clock();
			PrintAll_BT(CPa->head);
			end = clock();
			printf("%.3lf초\n", (end - start) / (double)1000);
			break;
		case 2:
			printf("추가할 챔피언");
			scanf("%[^\n]s", In_info);
			rewind(stdin);
			if (!Search_BT(In_info, CPa->head, false))
				printf("중복\n");
			else {
				info *node = new info;
				printf("포지션 체력 공격력 방어력 순으로 입력 : ");
				scanf("%s %d %d %d", node->pos, &node->hp, &node->att, &node->def);
				rewind(stdin);
				strcpy(node->name, In_info);
				node->left = NULL;
				node->right = NULL;
				node->root = NULL;
				start = clock();
				Insert_BT(&node, CPa);
				end = clock();
				printf("%.3lf초\n", (end - start) / (double)1000);
			}
			break;
		case 3:
			printf("찾을 챔피언이름을 입력하시오 : ");
			scanf("%s", In_info);
			rewind(stdin);
			start = clock();
			Search_BT(In_info, CPa->head, true);
			end = clock();
			printf("%.3lf초\n", (end - start) / (double)1000);
			break;
		case 4:
			printf("삭제할 챔피언이름을 입력하시오 : ");
			scanf("%s", In_info);
			rewind(stdin);
			Search_BT(In_info, CPa->head, false);
			start = clock();
			Delete_BT(&CPa);
			end = clock();
			printf("%.3lf초\n", (end - start) / (double)1000);
			break;
		case 5:
			Print_BT(CPa->head);
			break;
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
		cur->head = CPa->head;
		fscanf(fp, "%s %s %d %d %d", node->pos, node->name, &node->hp, &node->att, &node->def);
		if (CPa->head == NULL) {
			CPa->head = node;
			node->left = NULL;
			node->right = NULL;
			node->root = NULL;
		}
		else
			while (1)
				if (strcmp(cur->head->name, node->name) < 0) {
					if (cur->head->right == NULL) {
						cur->head->right = node;
						node->root = cur->head;
						node->left = NULL;
						node->right = NULL;
						break;
					}
					else
						cur->head = cur->head->right;
				}
				else if (strcmp(cur->head->name, node->name) > 0) {
					if (cur->head->left == NULL) {
						cur->head->left = node;
						node->root = cur->head;
						node->left = NULL;
						node->right = NULL;
						break;
					}
					else
						cur->head = cur->head->left;
				}
	}
	fclose(fp);
	return CPa;
}
void PrintAll_BT(info* CPa) {

	if (CPa->left != NULL)
		PrintAll_BT(CPa->left);
	if (CPa->right != NULL)
		PrintAll_BT(CPa->right);
	printf("==================\n");
	printf("Pos : %s\nName: %s\nHP : %d\nAtt : %d\nDef : %d\n", CPa->pos, CPa->name, CPa->hp, CPa->att, CPa->def);
	printf("==================\n");


	return;
}
void Print_BT(info* CPa) {
	if (i < 10000) {
		if (CPa->left != NULL)
			Print_BT(CPa->left);
		if (CPa->right != NULL)
			Print_BT(CPa->right);
		i++;
		printf("Pos : %s Name: %s HP : %d Att : %d Def : %d\n", CPa->pos, CPa->name, CPa->hp, CPa->att, CPa->def);
	}
	return;
}
bool Search_BT(char *In_info, info* CPa, bool status) {
	cur->head = CPa;
	while (cur->head != NULL) {
		if (strcmp(In_info, cur->head->name) < 0)
			cur->head = cur->head->left;
		else if (strcmp(In_info, cur->head->name) > 0)
			cur->head = cur->head->right;
		else if (strcmp(In_info, cur->head->name) == 0) {
			if (status) {
				printf("==================\n");
				printf("Pos : %s\nName: %s\nHP : %d\nAtt : %d\nDef : %d\n", cur->head->pos, cur->head->name, cur->head->hp, cur->head->att, cur->head->def);
				printf("==================\n");
			}
			DP->head = cur->head;
			return false;
		}
	}
	return true;
}
void Insert_BT(info** node, CP* CPa) {
	CP* AA = new CP;
	AA->head = CPa->head;
	if (strcmp((*node)->name, AA->head->name) < 0) {
		if (AA->head->left == NULL) {
			AA->head->left = *node;
			(*node)->root = AA->head;
			return;
		}
		AA->head = AA->head->left;
		Insert_BT(&(*node), AA);
	}
	else {
		if (AA->head->right == NULL) {
			AA->head->right = *node;
			(*node)->root = AA->head;
			return;
		}
		AA->head = AA->head->right;
		Insert_BT(&(*node), AA);
	}
}
void Delete_BT(CP** CPa) {
	//P1630424524
	cur->head = DP->head;
	if (cur->head->left == NULL &&cur->head->right != NULL)
		if (cur->head->root->left == cur->head)
			cur->head->root->left = cur->head->right;
		else
			cur->head->root->right = cur->head->right;
	else if (cur->head->right == NULL &&cur->head->left != NULL)
		if (cur->head->root->left == cur->head)
			cur->head->root->left = cur->head->left;
		else
			cur->head->root->right = cur->head->left;
	else if (cur->head->right == NULL &&cur->head->left == NULL)// 리프노드
		if (cur->head->root->left == cur->head)
			cur->head->root->left = NULL;
		else
			cur->head->root->right = NULL;
	else if (cur->head->right != NULL &&cur->head->left != NULL) { //
		cur->head = cur->head->left;

		while (cur->head != NULL) {
			if (cur->head->right == NULL) {
				if (cur->head != DP->head->left)
					cur->head->left = DP->head->left;
				cur->head->right = DP->head->right;
				cur->head->root = DP->head->root;
				if (DP->head->root == NULL)
					(*CPa)->head = cur->head;
				else if (DP->head->root->left == DP->head)
					DP->head->root->left = cur->head;
				else if (DP->head->root->right == DP->head)
					DP->head->root->right = cur->head;
				break;
			}
			cur->head = cur->head->right;
		}
	}
}