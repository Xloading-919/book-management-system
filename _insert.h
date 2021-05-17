
void _insert()
{   
	extern _bk books[MAX];
	extern int n;
	int id;
	

	if(n >= MAX) 
	{
		printf("图书数量以满!\n");
		return ;
	}	//验证：图书满返回主函数
	
     while(1)	//调用_check()函数查重,无记录返回-1，有记录返回其下标
	{
		printf("input ID:");
		scanf("%d",&id);
		if(_check(id) == -1)//是新图书，insert
		{
			break;
		}
		else//信息重复，重新输入
		{
			printf("记录重复，请核对!\n");
			//调用判断继续函数，继续返回0，退出返回1
			if(_continue() == 0) continue;
			else return ;
		}
	}

	books[n].id = id;//验证成功，就直接把id赋入结构体成员
	printf("input bookname:");
	scanf("%s",books[n].bookname);
	printf("input publisher:");
	scanf("%s",books[n].publisher); 
	printf("input autor:");
	scanf("%s",books[n].autor);
	printf("input  sort:");
	scanf("%s",books[n]. sort);//录入新的图书信息 
	printf("添加图书信息成功！\n");
	n++;//实际书数增加
	sleep(1);//延迟1秒
	_wcord();
}


