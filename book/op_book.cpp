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
		printf("Error Input! \n");//������벻��1~7�У�����ʾ���� 
	}
	if (op == 1) {
		FindBooks();//����1������鼮 
	} else if (op == 2) {
		AddBooks();//����2����鼮������ 
		SaveBooks();
	} else if (op == 3) {
		nBookId = BorrowBooks();//����3�ǽ���鼮 
	} else if (op == 4) {
		DeleteBooks();//����4ɾ���鼮 
		SaveBooks();
	} else if (op == 5) {
		nBookId = RetBooks();//����5�����鼮 
		//SaveBooks();
	} else if (op == 6) {
		PrintBooks();//����6��ʾ�鼮
	}
	return nBookId;
}

