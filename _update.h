void _update()
{
	printf("正在准备更改图书信息……\n");
	extern _bk books[MAX];
	extern int n; 
	int number ; //number
	int i;
	while(1)
	{
	      //printf("input ID:");
		printf("请输入要更改图书信息的ID:\n");
		scanf("%d",&number);
		if(_check(number) == -1)
		{
			printf("没有该图书，无法更改！\n");
			_toContinue();
			//break;
		}
		else{
		     break;
		 
		}
	
}     

                  i = _check(number);//返回当前图书的数组下标
		      printf("更改书名：\n");
		      scanf("%s",books[i].bookname);
		      //printf("\n");
		      printf("更改作者:\n");
		      scanf("%s",books[i].autor);
		      printf("更改出版社:\n");
		      scanf("%s",books[i].publisher);
		      printf("更改类别:\n");
		      scanf("%s",books[i].sort);
		      printf("信息更改完毕！\n");
		      //数据从程序同步到文件
			_wcord();
                  _toContinue();
}

