/*
函数名:_print()
功能：show全部图书记录
作者：
形参：void
返回值：void
*/
void _print()
{
	extern _bk books[MAX];
	extern int n; 
	int i;
	//show
	printf("书编号\t书名\t\t\t作者\t\t\t出版社\t\t\t类别\t\n");
	for(i = 0; i< 80; i++)
	{
		printf("=");
	}
	printf("\n");
	for(i = 0; i < n; i++)
	{
		printf("%d\t%-15s\t\t%-15s\t\t%-15s\t\t%-15s\t\n",books[i].id,books[i].bookname,books[i].autor,books[i].publisher,books[i].sort);	
	}
	_toContinue();
}

