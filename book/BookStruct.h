typedef struct _book
{
    int nId;
    char *sName;
    char *sCategory;
    char *sAuthor;
    int nTotal  ;
    float fPrice;
    struct _book *pre;
    struct _book *next;
} CBook;

CBook *Choose();       
void InsertBook(CBook *sBook, CBook *pos);
void SaveInFile();  
int Sort(CBook *insert, CBook *pos, int nWay); 
int IsBook(int nWay, char *key, CBook *pos); 
void GetBooks();
void AddBooks();   
int FindBooks();  
void ChangesssInfo();  
int BorrowBooks();
int RetBooks();
void DeleteBooks(); 
void PrintBooks();  
int op_book(int op);
