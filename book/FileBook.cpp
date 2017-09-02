#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BookStruct.h"
const char* filename = "bk.txt";

//ɾ���鼮 
void DeleteBooks() {
	CBook *del = NULL;
	printf("Delete Book\n");
	printf("Choose which one to delete\n");
	del = Choose();
	printf("Deleted Book:");
	printf("%-10d%-30s%-20s%-20s%8d\t%.2f\n", del->nId, del->sName, del->sCategory, del->sAuthor, del->nTotal, del->fPrice);
	del->pre->next = del->next;
	del->next->pre = del->pre;
	free(del);
	del = NULL;
	printf("\n Delete Done!\n\n");
}

// ��ӡ����鼮 
void PrintBooks() {
	extern CBook *head, *tail;
	CBook *pos = head->next;
	printf("Id\t����\t\t���\t����\t\t״̬\t�۸�\n");
	while(pos != tail) {
		printf("%-8d%-16s%-8s%-9s%8d\t%.2f\n", pos->nId, pos->sName, pos->sCategory, pos->sAuthor, pos->nTotal, pos->fPrice);
		pos = pos->next;
	}
	printf("\n");
}

//�ӱ���ɨ�貢�����鼮 
void InsertBook(CBook *sBook, CBook *pos) {
	CBook *tmp = NULL, *pt = NULL;
	tmp = (CBook *)malloc(sizeof(CBook));
	memset(tmp,0,sizeof(sBook));
	tmp->nId = sBook->nId;
	tmp->sName = (char *)malloc(strlen(sBook->sName)+1);
	memset(tmp->sName,0,strlen(sBook->sName)+1);
	strcpy(tmp->sName, sBook->sName);
	tmp->sCategory = (char *)malloc(strlen(sBook->sCategory)+1);
	memset(tmp->sCategory,0,strlen(sBook->sCategory)+1);
	strcpy(tmp->sCategory, sBook->sCategory);
	tmp->sAuthor = (char *)malloc(strlen(sBook->sAuthor)+1);
	memset(tmp->sAuthor,0,strlen(sBook->sAuthor)+1);
	strcpy(tmp->sAuthor, sBook->sAuthor);
	tmp->nTotal = sBook->nTotal;
	tmp->fPrice = sBook->fPrice;
	pt = pos->next;
	pos->next = tmp;
	tmp->pre = pos;
	tmp->next = pt;
	pt->pre = tmp;
}

//�����鼮 
void SaveBooks() {
	FILE *fp;
	extern CBook *head, *tail;
	CBook *pos = head->next;
	if((fp=fopen(filename,"w"))==NULL) {
		perror("Error! \n");
	}
	while(pos != tail) {
		fprintf(fp, "%d\t%s\t%s\t%s\t%8d\t%.2f\n", pos->nId, pos->sName, pos->sCategory, pos->sAuthor, pos->nTotal, pos->fPrice);
		pos = pos->next;
	}
	fclose(fp);

}

