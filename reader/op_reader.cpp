#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "op_reader.h"
#include "../Book/BookStruct.h"
CReader *ReaderHead, *ReaderTail;
CBook *head, *tail;
const char* ReaderFile = "rd.txt";

//ʵ�ֶԶ��ߵĲ������� 
int op_reader(int op,int nReaderId, int nBookId) {
	int nOperation, nProcessing = 1;
	ScanReaders();
	if (op == 1) {
		int nFindId ;
		printf("nFindId=");
		scanf("%d[^/n]\n", &nFindId);
		FindReaders(nFindId);
	} else if (op == 2) {
		AddReaders();//��ӽ�������Ϣ
	} else if (op == 3) {
		RsetReader();//�޸Ľ�������Ϣ
	} else if (op == 4) {
		DeleteReaders();//ɾ����������Ϣ 
	} else if (op == 5) {
		PrintReaders();//��ӡ��������Ϣ
	} else if(op ==6) {
		printf("BorrowBooks ing...%d -> %d\n",nReaderId,nBookId);//��ʾ����ѧ��id��Ӧ���鼮id 
		ReaderBorrow(nReaderId,nBookId);
		printf("Acess nBookId=%d",nBookId);
		SaveReader(); 
	} else {
		ReaderReturnBook(nReaderId);
		SaveReader();
	}
	SaveReader();
	return 1;
}

//�ӱ����ļ�ɨ�������Ϣ 
void ScanReaders() {
	FILE *ReaderFp;// FILE:���������ļ��Ľṹ��
	char sName[60] = {0}, sCategory[40] = {0}, sBook[40] = {0};//�����ߵ�������ѧԺ���鼮��Ϣ������ַ��������� 
	int nDate, nCh ,nReaderId, nKeepBook;
	float fPrice;
	ReaderHead = (CReader *)malloc(sizeof(CReader));
	memset(ReaderHead,0,sizeof(CReader));
	ReaderTail = (CReader *)malloc(sizeof(CReader));
	memset(ReaderTail,0,sizeof(CReader));
	ReaderHead->next = ReaderTail;
	ReaderTail->pre = ReaderHead;
	CReader *reader = NULL;
	CReader *pos = ReaderTail->pre;
	if((ReaderFp=fopen(ReaderFile,"r"))==NULL) {
		printf("Cannot Read\n");// �ļ��в�����
	}
	while ((nCh = fscanf(ReaderFp, "%d %s %s %s %d ", &nReaderId, sName, sCategory, sBook, &nKeepBook)) > 3 ) {
		reader = (CReader *)malloc(sizeof(CReader));
		memset(reader,0,sizeof(CReader));
		reader->nReaderId = nReaderId;
		reader->sName = sName;
		reader->sCategory = sCategory;
		reader->sBook = sBook;
		reader->nKeepBook = nKeepBook;
		InsertReader(reader, pos);
		pos = pos->next;
	}
	fclose(ReaderFp);
}

//��Ӷ�����Ϣ���� 
void AddReaders() {
	char sName[50] = {0}, sCategory[50] = {0}, sBook[40] = {0};
	int nReaderId, nDate, nCh, nNum, nKeepBook = 0;
	float fPrice;
	CReader *reader = NULL;
	CReader *pos = ReaderTail->pre;
	printf("\nAdd Readers ctrl+d to quit \n");
	printf("Enter reader's nReaderId ,sName, sCategory, sBook: ");
	while((nCh = scanf("%d %s %s %s[^/n]",&nReaderId, sName, sCategory, sBook)) != EOF) {
		if (nCh != 4) {
			printf("Enter reader's nReaderId ,sName, sCategory, sBook:");
			continue;
		}
		reader = (CReader *)malloc(sizeof(CReader));
		memset(reader,0,sizeof(CReader));
		reader->nReaderId = nReaderId;
		printf("nReaderId=%d",nReaderId);
		reader->sName = sName;
		reader->sCategory = sCategory;
		reader->sBook = sBook;
		reader->nKeepBook = nKeepBook;
		InsertReader(reader, pos);
		pos = pos->next;
		nNum++;
		//printf("Added %d Readers \n", nNum);
		printf("Enter reader's nReaderId, sName, sCategory, sBook, keepbook:\n ");
	}
	printf("Add Done.\n\n");
}

//���Ҷ�����Ϣ���� 
void FindReaders(int nReaderId) {
	int finding = 1, c;//���ñ�־finding�ж��Ƿ��ҵ� 
	CReader *reader = NULL;
	while(finding) {
		reader = ReaderChoose(nReaderId);
		if (reader == NULL) {//û����ض�����Ϣ 
			printf("\n404 NOT FOUND\n");
			finding = 0;
		} else {
			printf("\nFind\n");
			printf("nId\t����\tѧԺ\tƫ��\t\t����ID\n");
			printf("%-8d%-8s%-8s%-13s%5d\n", reader->nReaderId, reader->sName, reader->sCategory, reader->sBook, reader->nKeepBook);
			finding = 0;
		}
		printf("\n");
	}
}

//�޸Ķ�����Ϣ���� 
void RsetReader() {
	char sInfo[60];
	int nTotal, nWay, nReaderId,nKeepBook;
	float fPrice;
	int nTempid = 0;//��ʱidֵ 
	CReader *change = NULL;
	printf("For change nReaderId:");//������Ҫ�޸ĵĶ���id 
	scanf("%d[^/n]\n", &nTempid);
	change = ReaderChoose(nTempid);
	printf("Before:");
	printf("%-10d%-10s%-20s%-20s%8d\n", change->nReaderId, change->sName, change->sCategory, change->sBook, change->nKeepBook);
	printf("Choose which(1:ReaderId,2:Name,3:Category,4:PreBook,5:Keepbook): ");
	getchar();
	scanf("%d", &nWay);
	printf("After:");
	if (nWay == 2 || nWay == 3 || nWay == 4) {//ѡ�����������ѧԺ���鼮�޸�ʱ����ѭ�� 
		scanf("%s", sInfo);
		if (nWay == 2) {
			free(change->sName);
			change->sName = (char *)malloc(strlen(sInfo)+1);
			strcpy(change->sName, sInfo);
		} else if (nWay == 3) {
			free(change->sCategory);
			change->sCategory = (char *)malloc(strlen(sInfo)+1);
			strcpy(change->sCategory, sInfo);
		} else {
			free(change->sBook);
			change->sBook = (char *)malloc(strlen(sInfo)+1);
			strcpy(change->sBook, sInfo);
		}
	} else if (nWay == 1) {
		scanf("%d", &nReaderId);
		change->nReaderId = nReaderId;
	} else {
		scanf("%d", &nKeepBook);
		change->nKeepBook = nKeepBook;
	}
	printf("%-10d%-10s%-20s%-20s%8d\n", change->nReaderId, change->sName, change->sCategory, change->sBook, change->nKeepBook);
	change = NULL;
}

//ɾ��������Ϣ���� 
void DeleteReaders() {
	CReader *del = NULL;
	int iWaitDel;//��ʱ������Ŷ���id 
	printf("Choose the nReaderId to delete \n");
	scanf("%d[^/n]\n", &iWaitDel);
	del = ReaderChoose(iWaitDel);
	printf("The sBook wait delete:");
	printf("%-10d%-30s%-20s%-20s%8d\n", del->nReaderId,del->sName, del->sCategory, del->sBook, del->nKeepBook);
	del->pre->next = del->next;
	del->next->pre = del->pre;
	free(del);
	if(del!=NULL){
		del = NULL;
	}
	printf("\nDelete Done \n\n");
}

//���麯�� 
void ReaderBorrow(int nReaderId,int nBookId)
{
	CReader *bor = NULL;
	bor = ReaderChoose(nReaderId);
	printf("Before: %d",bor->nKeepBook);
	(ReaderChoose(nReaderId))->nKeepBook = nBookId;
	//printf("Book=%d",nBookId);
	bor = NULL;
}

//���麯�� 
int ReaderReturnBook(int nReaderId) {
	CReader *re = NULL;
	re =ReaderChoose(nReaderId);
	printf("Before Return:%d",re->nKeepBook);
	(ReaderChoose(nReaderId))->nKeepBook = 0;
	re = NULL;
	return 1;
}

//��ӡ������Ϣ���� 
void PrintReaders() {
	CReader *pos = ReaderHead->next;
	printf("ѧ��\t����\tѧԺ\t\tƫ��\t����\n");
	while(pos != ReaderTail) {
		printf("%-8d%-8s%-16s%-5s%5d\n",pos->nReaderId, pos->sName, pos->sCategory, pos->sBook, pos->nKeepBook);
		pos = pos->next;
	}
	printf("\n");
}

CReader *ReaderChoose(int key) {
	CReader *pos = ReaderHead->next;
	CReader *find = NULL;
	while(pos != ReaderTail) {
		if(IsReader(key,pos)) {
			find = pos;
			break;
		}
		pos = pos->next;
	}
	return find;

}

int IsReader(int key,CReader *pos) {
	return (key == pos->nReaderId);
}

//���������Ϣ���� 
void InsertReader(CReader *reader, CReader *pos) {
	CReader *tmp = NULL, *pt = NULL;
	tmp = (CReader *)malloc(sizeof(CReader));
	tmp->nReaderId = reader->nReaderId;
	tmp->sName = (char *)malloc(strlen(reader->sName)+1);
	strcpy(tmp->sName, reader->sName);
	tmp->sCategory = (char *)malloc(strlen(reader->sCategory)+1);
	strcpy(tmp->sCategory, reader->sCategory);
	tmp->sBook = (char *)malloc(strlen(reader->sBook)+1);
	strcpy(tmp->sBook, reader->sBook);
	tmp->nKeepBook = reader->nKeepBook;
	pt = pos->next;
	pos->next = tmp;
	tmp->pre = pos;
	tmp->next = pt;
	pt->pre = tmp;
	tmp = NULL;
	pt = NULL;
}

//���������Ϣ���� 
void SaveReader() {
	FILE *ReaderFp;
	CReader *pos = ReaderHead->next;

	if((ReaderFp=fopen(ReaderFile,"w"))==NULL) {
		printf("Reader File open error!");
	}

	while(pos != ReaderTail) {
		fprintf(ReaderFp, "%d\t%s\t%s\t%s\t%8d\n",pos->nReaderId, pos->sName, pos->sCategory, pos->sBook, pos->nKeepBook);
		pos = pos->next;
	}

	fclose(ReaderFp);
}
