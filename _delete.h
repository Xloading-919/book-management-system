/*
函数名:_delete()
功能：删除借出的书本
作者：
形参：void
返回值：void

*/
void delId()
{
	char tips[100];//本函数末按yes返回菜单的控制，无其他逻辑关系
	int number;//要删除课本的序号
	int i , id , ok ;
	printf("请输入要删除图书的ID:\n");
	scanf("%d",&id);
	//循环判断删除的图书信息
	number = _check(id);
	//如果n=0，表示当前图书馆无图书，返回程序;
	if(number < 0){
	 printf("现在图书馆已置空，无法删除!\n");
	 sleep(1);
	 return ;
	}
	printf("书编号\t书名\t\t\t作者\t\t\t出版社\t\t\t类别\t\n");
	printf("%d\t%-15s\t\t%-15s\t\t%-15s\t\t%-15s\t\n",books[number].id,books[number].bookname,books[number].autor,books[number].publisher,books[number].sort);		
	//是否删除提示：
	printf("是否确认删除？1--确认，0--取消!\n");
	scanf("%d",&ok);
	if( ok == 1)
	{
		printf("删除操作正在进行……\n");//进行删除操作
		sleep(1);
		for(i = number; i  <  n-1 ; i++)
		{
		books[i] = books[i+1];
	
		}
		n--;
		printf("删除成功！\n");
	}
	//判断是否继续操作
	printf("press \"yes\" to back menu!");
	scanf("%s",tips);
	
}
void delBookname()
{
	char tips[100];//本函数末按yes返回菜单的控制，无其他逻辑关系
	char name[50];
	int ok,number,i;
	int countInfo = 0;//记录符合匹配信息的书本数
	_bk *p,*q;//用于删除记录的指针
	printf("Input delete BOOKSNAME:");
	scanf("%s",name);
	//如果找到直接输出，未找到i值为-1
	//开始查找:结构体中书名 与 输入匹配的字符串
	printf("符合删除匹配条件的图书信息\n");
	printf("\t===========================================\n");
	printf("书编号\t书名\t\t\t作者\t\t\t出版社\t\t\t类别\t\n");
	for(i=n-1;i>=0;i--)
	{
		if(strcmp(books[i].bookname,name)==0)
		{
			printf("%d\t%-15s\t\t%-15s\t\t%-15s\t\t%-15s\t\n",books[i].id,books[i].bookname,books[i].autor,books[i].publisher,books[i].sort);		
			//符合删除条件的书本+1
			countInfo++;
		}
	}
	//查无此书
	if(countInfo == 0)
	{
		printf("无该书名的书本！\n");
		//节奏控制press any key to back!
		printf("press \"yes\" to back menu!");
		scanf("%s",tips);
		return;//无符合条件记录，返回菜单
	}
	//是否删除提示：
	printf("%d条符合删除条件的书本，是否确认删除？1--确认，0--取消!  ",countInfo);
	scanf("%d",&ok);	
	if(ok == 1)
	{
		//2,========删除-符合条件的记录，按书名删除
		for(p=books,q=books;p-books<n;p++)
		{
			if(strcmp(p->bookname,name)!=0) //让保留的成立
			{
				*q++ = *p;
			}
		}
		n = n - countInfo;//减去删除书本数
		printf("删除完毕!\n");
		//_shijian(countInfo);
		printf("press \"yes\" to back menu!");
		scanf("%s",tips);		
	}
}
void delPublisher()
{
	char tips[100];//本函数末按yes返回菜单的控制，无其他逻辑关系
	char publisher[50];
	int ok,number,i;
	int countInfo = 0;//记录符合匹配信息的书本数
	_bk *p,*q;//用于删除记录的指针
	printf("Input delete BOOKS-PUBLISHER:");
	scanf("%s",publisher);
	//如果找到直接输出，未找到i值为-1
	//开始查找:结构体中出版社 与 输入匹配的字符串
	printf("符合删除匹配条件的书本信息\n");
	printf("\t===========================================\n");
	printf("书编号\t书名\t\t\t作者\t\t\t出版社\t\t\t类别\t\n");
	for(i=n-1;i>=0;i--)
	{
		if(strcmp(books[i].publisher,publisher)==0)
		{
			printf("%d\t%-15s\t\t%-15s\t\t%-15s\t\t%-15s\t\n",books[i].id,books[i].bookname,books[i].autor,books[i].publisher,books[i].sort);		
			//符合删除条件的书本+1
			countInfo++;
		}
	}
	//查无此书
	if(countInfo == 0)
	{
		printf("无该书名的书本！\n");
		//节奏控制press any key to back!
		printf("press \"yes\" to back menu!");
		scanf("%s",tips);
		return;//无符合条件记录，返回菜单
	}
	//是否删除提示：
	printf("%d条符合删除条件的书本，是否确认删除？1--确认，0--取消!  ",countInfo);
	scanf("%d",&ok);	
	if(ok == 1)
	{
		//2,========删除-符合条件的记录，按书名删除
		for(p=books,q=books;p-books<n;p++)
		{
			if(strcmp(p->publisher,publisher)!=0) //让保留的成立
			{
				*q++ = *p;
			}
		}
		n = n - countInfo;//减去删除书本数
		printf("删除完毕!\n");
		//_shijian(countInfo);
		printf("press \"yes\" to back menu!");
		scanf("%s",tips);		
	}
}
void delAutor()
{
	char tips[100];//本函数末按yes返回菜单的控制，无其他逻辑关系
	char autor[50];
	int ok,number,i;
	int countInfo = 0;//记录符合匹配信息的书本数
	_bk *p,*q;//用于删除记录的指针
	printf("Input delete BOOKS-AUTOR:");
	scanf("%s",autor);
	//如果找到直接输出，未找到i值为-1
	//开始查找:结构体中作者 与 输入匹配的字符串
	printf("符合删除匹配条件的图书信息\n");
	printf("\t===========================================\n");
	printf("书编号\t书名\t\t\t作者\t\t\t出版社\t\t\t类别\t\n");
	for(i=n-1;i>=0;i--)
	{
		if(strcmp(books[i].autor,autor)==0)
		{
			printf("%d\t%-15s\t\t%-15s\t\t%-15s\t\t%-15s\t\n",books[i].id,books[i].bookname,books[i].autor,books[i].publisher,books[i].sort);	
			//符合删除条件的书本+1
			countInfo++;
		}
	}
	//查无此书
	if(countInfo == 0)
	{
		printf("无该书名的书本！\n");
		//节奏控制press any key to back!
		printf("press \"yes\" to back menu!");
		scanf("%s",tips);
		return;//无符合条件记录，返回菜单
	}
	//是否删除提示：
	printf("%d条符合删除条件的书本，是否确认删除？1--确认，0--取消!  ",countInfo);
	scanf("%d",&ok);	
	if(ok == 1)
	{
		//删除-符合条件的记录，按作者删除
		for(p=books,q=books;p-books<n;p++)
		{
			if(strcmp(p->autor,autor)!=0) //让保留的成立
			{
				*q++ = *p;
			}
		}
		n = n - countInfo;//减去删除书本数
		printf("删除完毕!\n");
		//_shijian(countInfo);
		printf("press \"yes\" to back menu!");
		scanf("%s",tips);		
	}
}
void _delete()
{
	//引入全局变量
	extern _bk books[MAX];
	extern int n; 
	int del;//选择删除方案
	printf("\t===================delete==================\n");
	printf("1----id\t\t2----booksname\t\t3----publisher\t\t4----autor\n");
	printf("请按相关数字键，选择删除关键字:");
	scanf("%d",&del);
	switch(del)
	{
		case 1:delId();break;//调用按Id删除函数
		case 2:delBookname();break;//调用按书名删除函数
		case 3:delPublisher();break;//调用按出版社删除函数
		case 4:delAutor();break;//调用按作者姓名删除
		default:printf("KEYWORK ERROR!");sleep(2);
	}
	//3，=============记录存储同步
	_wcord();
	
}









