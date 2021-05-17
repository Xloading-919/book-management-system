/*按id查找*/
void selId()
{
	char tips[100];//本函数末按yes返回菜单的控制，无其他逻辑关系
	int id,ok,number;
	printf("Input Select ID:");
	scanf("%d",&id);
	//调用验证Id是否存在，并返回值
	number = _check(id);
	if(number == -1)
	{
		printf("无此书!\n");
	}
	else       
	{
		printf("书编号\t书名\t\t\t作者\t\t\t出版社\t\t\t类别\t\n");
		printf("%d\t%-15s\t\t%-15s\t\t%-15s\t\t%-15s\t\n",books[number].id,books[number].bookname,books[number].autor,books[number].publisher,books[number].sort);
		//_shijian(1);
	}
	//节奏控制press any key to back!
	printf("press \"yes\" to back menu!");
	scanf("%s",tips);
}
/*按书名查找*/
void selBookname()
{
	char tips[100];//本函数末按yes返回菜单的控制，无其他逻辑关系
	char bookname[100];
	int i ;
	printf("Input Select BOOKNAME:");
	scanf("%s",bookname);//读入要查询图书的书名
	//开始查找:结构体中书名 与 输入匹配的字符串
	printf("书编号\t书名\t\t\t作者\t\t\t出版社\t\t\t类别\t\n");
	for( i = n-1 ; i >=0;i--)//循环输出符合条件的图书信息
	{
		if(strcmp(books[i].bookname,bookname)==0)
			{
				printf("%d\t%-15s\t\t%-15s\t\t%-15s\t\t%-15s\t\n",books[i].id,books[i].bookname,books[i].autor,books[i].publisher,books[i].sort);		
			}
	}
	//节奏控制press any key to back!
	printf("press \"yes\" to back menu!");
	scanf("%s",tips);		
}
void selAutor()
{
	char tips[100];//本函数末按yes返回菜单的控制，无其他逻辑关系
	char autor[100];
	int i;
	printf("input select the name of autor\n");//输入作者姓名
	scanf("%s",autor);
	printf("书编号\t书名\t\t\t作者\t\t\t出版社\t\t\t类别\t\n");
	for( i = n-1 ; i >=0;i--)//循环输出符合条件的图书信息
	{
		if(strcmp(books[i].autor,autor)==0)
			{
				printf("%d\t%-15s\t\t%-15s\t\t%-15s\t\t%-15s\t\n",books[i].id,books[i].bookname,books[i].autor,books[i].publisher,books[i].sort);			
			}
	}
	//节奏控制press any key to back!
	printf("press \"yes\" to back menu!");
	scanf("%s",tips);		
}
/*
功能：查询图书记录
	 1，可选查询方案，按什么关键字查询
函数名：_select()
形参: void
返回值: void
*/
void _select()
{
	//引入全局变量
	extern _bk books[MAX];
	extern int n; 
	int sel;//选择查询方案
	printf("\t===================select==================\n");
	printf("1----id\t\t2----bookname\t\t3----autor\n");
	printf("请按相关数字键，选择查询关键字:");
	scanf("%d",&sel);
	switch(sel)
	{
		case 1:selId();break;//调用按Id查找函数
		case 2:selBookname();break;//调用按书名查找函数
		case 3:selAutor();break;//调用按作者查找函数
		default:printf("KEYWORK ERROR!");sleep(2);
	}
	
}
	

