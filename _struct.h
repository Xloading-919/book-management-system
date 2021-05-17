#define MAX 500//书的最大数量
typedef struct username
{
	
	char username[20];//用户名
	char password[20];
	int limit;//权限
}_USER;
_USER user[MAX];
int limit;//全局权限标识

typedef struct book
{
	int id ; //书编号
	//int num ; //书的数量
	char bookname[100] ;//书名
	char publisher[100] ; //出版社
	char autor[100] ;//作者姓名
	char sort[100] ;//书的分类 
	}_bk;
_bk books[MAX];
int n = 0 ;//当前图书馆中图书数量

/*
#define MAX 500//书的最大数量
typedef struct username
{
	
	char username[20];//用户名
	char password[20];
	int limit;//权限
}_USER;
_USER user[MAX];
int limit;//全局权限标识

typedef struct book
{
	int id ; //书编号
	int num ; //书的数量
	char bookname[20] ;//书名
	char publisher[20] ; //出版社
	char autor[20] ;//作者姓名
	char sort[20] ;//书的分类 
	}_bk;
_bk books[MAX];
int n = 0 ;//当前图书馆中图书数量
*/
