#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BookStruct.h"
#include "FileBook.h"

//改变书籍信息 
void ChangeInfo()
{
    char sInfo[60];
    int nTotal, nWay;
    float fPrice;
    CBook *change = NULL;
    printf("修改图书信息\n");
    change = Choose();
    printf("Before：");
    printf("%-10s%-15s%-15s%8d\t%.2f\n", change->sName, change->sCategory, change->sAuthor, change->nTotal, change->fPrice);

    printf("选择修改的类型(Name,Category,Author,Total,Price)|(1,2,3,4,5): ");
    scanf("%d", &nWay);
    printf("After：");

    if (nWay == 1 || nWay == 2 || nWay == 3)
    {
        scanf("%s", sInfo);

        if (nWay == 1)
        {
            change->sName = (char *)malloc(strlen(sInfo)+1);
            memset(change->sName,0,strlen(sInfo)+1);
            strcpy(change->sName, sInfo);
        }
        else if (nWay == 2)
        {
            change->sCategory = (char *)malloc(strlen(sInfo)+1);
            memset(change->sCategory,0,strlen(sInfo)+1);
            strcpy(change->sCategory, sInfo);
        }
        else
        {
            change->sAuthor = (char *)malloc(strlen(sInfo)+1);
            memset(change->sAuthor,0,strlen(sInfo)+1);
            strcpy(change->sAuthor, sInfo);
        }
    }
    else if (nWay == 4)
    {
        scanf("%d", &nTotal);
        change->nTotal = nTotal;
    }
    else
    {
        scanf("%f", &fPrice);
        change->fPrice = fPrice;
    }
    printf("After Change:");
    printf("%-30s%-20s%-20s%8d\t%.2f\n\n", change->sName, change->sCategory, change->sAuthor, change->nTotal, change->fPrice);
}

//借出书籍 
int BorrowBooks()
{
  int nBookId = -1;
  CBook *bor = NULL;
  bor = Choose();
  //bor = FindBooks();
  printf("BookName:");
  printf("%d\n",bor->nId);
  if (bor->nTotal == 0)
  {
  	  return -1;  //返回上级程序，无法借出 
  }
  else
  {
	  bor->nTotal = 0;
	  printf("After bor =%d\n",bor->nTotal);
	  SaveBooks();
	  nBookId = bor->nId;
	  free(bor);
	  if(bor!=NULL){
	  bor = NULL;}
	  printf("BorrowBooks=%d",nBookId);
	  
	  return nBookId;
  }
}

//返还书籍 
int RetBooks()
{
  int nReturnBookId;
  CBook *re =NULL;
  re = Choose();
  printf("returname=%s\n",re->sName);
  re->nTotal = 1;
  nReturnBookId = re->nId;
  SaveBooks();
  free(re);
  if(re!=NULL){
  	re = NULL;
  }  
  return nReturnBookId;
}

