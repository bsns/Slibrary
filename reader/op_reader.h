typedef struct _reader
{
    int nReaderId;
    char *sName;
    char *sCategory;
    char *sBook;
    int nKeepBook;
    struct _reader *pre;
    struct _reader *next;
} CReader;

CReader *ReaderChoose(int nReaderId);
void InsertReader(CReader *reader, CReader *pos);
void SaveReader();
int IsReader(int key, CReader *pos);
void ReaderBorrow(int nReaderId,int nBookId);
void ScanReaders();
void AddReaders();
void FindReaders(int nReaderId);
void RsetReader();
void DeleteReaders();
void PrintReaders();
int op_reader(int op,int nReaderId ,int nBookId);
int ReaderReturnBook(int nReaderId);
