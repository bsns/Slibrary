#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BookStruct.h"
#include "ScanBook.h"
#include "AddBook.h"
#include "FindBook.h"
#include "ChangeBook.h"
#include "FileBook.h"

int op_book(int op) {
	int nBookId = -1;
	int nOperation, nProcessing = 1;
	GetBooks();
	if (op < 1 || op > 7) {
		printf("Error Input! \n");//如果输入不在1~7中，则显示错误 
	}
	if (op == 1) {
		FindBooks();//输入1则查找书籍 
	} else if (op == 2) {
		AddBooks();//输入2添加书籍并保存 
		SaveBooks();
	} else if (op == 3) {
		nBookId = BorrowBooks();//输入3是借出书籍 
	} else if (op == 4) {
		DeleteBooks();//输入4删除书籍 
		SaveBooks();
	} else if (op == 5) {
		nBookId = RetBooks();//输入5返还书籍 
		//SaveBooks();
	} else if (op == 6) {
		PrintBooks();//输入6显示书籍
	}
	return nBookId;
}

