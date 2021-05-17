/*
功能:不同程序操作到文件
函数名：_wcord();
形参：void
返回值:void
*/
void _wcord()
{
	extern _bk books[MAX];
	extern int n; 
	FILE *fsave,*fcount;
	//打开book_server_save.dat的图书记录文件，权限：wb二进制写
	fsave = fopen("book_server_save.dat","wb");
	//打开book_server_count.dat书本数数据文件，权限：w
	fcount = fopen("book_server_count.dat","w");
	//更新书本数n，到文件
	fprintf(fcount,"%d",n);
	//更新全部书本记录数据，到文件
	fwrite(books,sizeof(_bk),n,fsave);
	//关闭文件指针
	fclose(fsave);
	fclose(fcount);
}

