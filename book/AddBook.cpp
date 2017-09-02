#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BookStruct.h"

//Ìí¼ÓÊé¼®º¯Êý 
void AddBooks() {
	char sName[60] = {0}, sCategory[40] =  {0}, sAuthor[40] =  {0};
	int  nCh, nNum, nId = 0;
	int nTotal = 1;
	float fPrice;
	CBook *sBook = NULL;
	extern CBook *head, *tail;
	CBook *pos = tail->pre;
	printf("\nAdd Book ctrl+d to quit\n");
	printf("Enter Book's Id, Name, Category, Author, Price in order: \n=> ");
	while((nCh = scanf("%d %s %s %s  %f", &nId, sName, sCategory, sAuthor, &fPrice)) != EOF) {
		if (nCh != 5) {
			printf("Erroe Input,please try again! \n");
			printf("Enter sBook's nId, Name, Category, sAuthor, Total, Price in order: \n ");
			continue;
		}
		sBook = (CBook *)malloc(sizeof(CBook));
		sBook->nId = nId;
		sBook->sName = sName;
		sBook->sCategory = sCategory;
		sBook->sAuthor = sAuthor;
		sBook->nTotal = nTotal;
		sBook->fPrice = fPrice;
		InsertBook(sBook, pos);
		pos = pos->next;
		nNum++;
		printf("Added %d sBook\n", nNum);
		printf("Enter sBook's Id, Name, Category, Author,  Total, Price: \n=> ");
	}
	printf("Add complete. Bye!\n\n");
}
