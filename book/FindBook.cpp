#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BookStruct.h"

//查找书籍 
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
			printf("Id\t书名\t类别\t作者\t\t状态\t价格\n");
			printf("%-8d%-8s%-8s%-10s%8d\t%.2f\n", sBook->nId, sBook->sName, sBook->sCategory, sBook->sAuthor, sBook->nTotal, sBook->fPrice);
		}
		printf("0 退出，其它键继续\n");
		scanf("%d", &c);
		if (c == 0) {
			finding = 0;
		}
		printf("\n");
	}
	return sBook->nId;
}

//选择书籍 
CBook *Choose() {
	char key[60] =  {0};
	int nWay,nId;
	extern CBook *head, *tail;
	CBook *pos = head->next;
	CBook *find = NULL;
	printf("Choose 1.Id 2.书名 3.分类 4.作者\n");
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

//根据传入的方式判断是否是这本书 
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
		return -1;  //如果没有寻找方式，返回值-1，方便上级程序判断 
	}
}

