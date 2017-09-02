#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ChangeTime.h"
#include "reader/op_reader.h"
#include "book/op_book.h"
#include "book/ScanBook.h"

typedef struct _order {
	int iReadId;
	int iBookId;
	int BorDate;
	int RetDate;
} Order;


const char* OdFileName ="od.txt";
int TmpBookId;
void OrderBook(int BookId) {
	FILE *fp;
	int ReaderId;
	
	int ch;

	char sTime[20]= {0};
	getTimeByC(sTime);

	if((fp=fopen(OdFileName,"a"))==NULL) {
		perror("Error:\n");
		//exit(1);
	}
	printf("Input ReaderId:");

	ch = scanf("%d", &ReaderId);
	{

		printf("Get ReaderId\t\t BookId\n");
		fprintf(fp, "%d\t\t%d\t\t%s\n",ReaderId ,BookId, sTime);

	}
	op_reader(6,ReaderId,BookId);

	printf("%d\t\t\t%d\t\t%s",ReaderId, BookId, sTime);
	printf("Reader Write Done\n");
	fclose(fp);
	SaveReader();

}

void ReturnBook(int BookId) {
	FILE *fp;
	int ReaderId;	

	char sTime[20]= {0};
	getTimeByC(sTime);
	if((fp=fopen(OdFileName,"a"))==NULL) {
		perror("Error!\n");
		exit(1);
	}
	printf("Input ReaderId：");
	scanf("%d", &ReaderId);
	{
		printf("ReaderId\t\t BookId\n");
		fprintf(fp, "%d\t\t%d\t\t\t\t\t%s\n",ReaderId ,BookId, sTime);
	}
	op_reader(7,ReaderId,BookId);
	printf("%d\t\t\t%d\t\t\t\t\t%s",ReaderId, BookId, sTime);
	fclose(fp);
}

int main() {
	int operation, processing = 1;
	while(processing) {
		printf("Choose 1.借书 2.还书 3:查找书 4:添加书 5删除书 6.打印书\n ");
		printf("7.查找读者 8.添加读者9.设置读者10.删除读者11.打印读者\n");
		printf("输入选择. (Input ctrl+z to quit)");

		if (scanf("%d", &operation) == EOF) {    //判断输入 
			processing = 0;
			continue;
		}

		if (operation < 1 || operation > 11) {  //判断输入的选择是否在设定范围内 
			printf("Error Input！\n");
			//processing = 0;
			continue;
		}

		if (operation == 1) 
		{
			GetBooks();
            TmpBookId = op_book(3);			//通过传入参数3，调用借书 
            if(TmpBookId == -1)
            {	
            	printf("书本已借出！\n");	// 如果书本已借出，返回 
				continue;
			}
			else
			{
            	OrderBook(TmpBookId);		//在书籍管理中，对书进行更改 
        	}
		} 
		else if (operation == 2) 
		{
			GetBooks();
			printf("ReturnBook ing...\n");
			TmpBookId = op_book(5);				//还书处理 
			ReturnBook(TmpBookId);
		} 
		else if (operation == 3) 
		{
			op_book(1);
		} else if (operation ==4) 
		{
			op_book(2);
		} else if(operation==5) 
		{								//调用op_book对书籍管理 
			op_book(4);
		} else if (operation==6) 
		{
			op_book(6);
		} else if(operation ==7) 
		{
			op_reader(1,0,0);
		} else if(operation ==8) 
		{
			op_reader(2,0,0);
		} else if(operation ==9) 
		{
			op_reader(3,0,0);
		} else if(operation ==10) 
		{							//调用op_reader对读者管理 
			op_reader(4,0,0);
		} else if(operation==11) 
		{
			op_reader(5,0,0);
		}
	}
}
