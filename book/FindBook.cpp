#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BookStruct.h"

//�����鼮 
int FindBooks() {
	int finding = 1, c;
	CBook *sBook = NULL;
	printf("Find Book\n");
	while(finding) {
		sBook = Choose();
		if (sBook == NULL) {
			printf("\n Can not Find\n");
		} else {
			printf("\nFind it! \n");
			printf("Id\t����\t���\t����\t\t״̬\t�۸�\n");
			printf("%-8d%-8s%-8s%-10s%8d\t%.2f\n", sBook->nId, sBook->sName, sBook->sCategory, sBook->sAuthor, sBook->nTotal, sBook->fPrice);
		}
		printf("0 �˳�������������\n");
		scanf("%d", &c);
		if (c == 0) {
			finding = 0;
		}
		printf("\n");
	}
	return sBook->nId;
}

//ѡ���鼮 
CBook *Choose() {
	char key[60] =  {0};
	int nWay,nId;
	extern CBook *head, *tail;
	CBook *pos = head->next;
	CBook *find = NULL;
	printf("Choose 1.Id 2.���� 3.���� 4.����\n");
	printf("The nWay:");
	scanf("%d", &nWay);
	printf("Value:");
	scanf("%s", key);
	while(pos != tail) {
		if (IsBook(nWay, key, pos) == 0) {
			find = pos;
			//break;
		}
		pos = pos->next;
	}
	//printf("Find=%s",find->sName);
	return find;
}

//���ݴ���ķ�ʽ�ж��Ƿ����Ȿ�� 
int IsBook(int nWay, char *key, CBook *pos) {
	if (nWay == 1) {
		int nId = atoi(key);
		return (nId != pos->nId);  
	}
	if (nWay == 2) {
		return strcmp(key, pos->sName);
	} else if (nWay == 3) {
		return strcmp(key, pos->sCategory);
	} else if (nWay == 4) {
		return strcmp(key, pos->sAuthor);
	} else {
		return -1;  //���û��Ѱ�ҷ�ʽ������ֵ-1�������ϼ������ж� 
	}
}

