#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BookStruct.h"

void GetBooks() {        //�ӱ��ض�ȡ�ļ������ص������� 
	FILE *fp;                    
	char sName[60] = {0}, sCategory[40] = {0}, sAuthor[40] = {0};
	int nTotal, nCh, nId ;
	float fPrice;
	extern CBook *head, *tail;
	head = (CBook *)malloc(sizeof(CBook));
	tail = (CBook *)malloc(sizeof(CBook));
	head->next = tail;
	tail->pre = head;
	CBook *sBook = NULL;
	CBook *pos = tail->pre;
	extern const char* filename;
	if((fp=fopen(filename,"r"))==NULL) {
		perror("Error! \n");
		
	}
	while((nCh = fscanf(fp, "%d %s %s %s %d %f", &nId, sName, sCategory, sAuthor, &nTotal, &fPrice)) != EOF) {
		sBook = (CBook *)malloc(sizeof(CBook));       //�����ӱ��ض�ȡ��Ϣ�����и�ֵ���� 
		memset(sBook,0,sizeof(sBook));
		sBook->nId = nId;
		sBook->sName = sName;
		sBook->sCategory = sCategory;
		sBook->sAuthor = sAuthor;
		sBook->nTotal = nTotal;
		sBook->fPrice = fPrice;
		InsertBook(sBook, pos);
		pos = pos->next;
	}
	fclose(fp);
}

