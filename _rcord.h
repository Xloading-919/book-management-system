/*
功能：初始化同步数据，将文件数据到取到程序
函数名：_record()
形参：void
返回值:void
*/
void _rcord()
{
	extern _bk books[MAX];
	extern int n; 
	FILE *fsave,*fcount;
	//打开book_server_save.dat图书记录数据文件，权限：rb 二进制读取
	fsave = fopen("book_server_save.dat","rb");
	//打开book_server_count.dat人数数据文件，权限r 
	fcount = fopen("book_server_count.dat","r");
	//读取书本数，同步到程序的全局变量n
	fscanf(fcount,"%d",&n);
	//将全部图书记录，同步到程序的全局结构体books[MAX]
	fread(books,sizeof(_bk),n,fsave);
	//关闭文件指针
	fclose(fsave);
	fclose(fcount);
}

