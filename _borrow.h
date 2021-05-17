void _borrow()
{    
	int a;
	int i , id , ok ;
	char tips[100];
	int number;
	printf("是否需要借书\n");
	printf("需要借书请输入1,不需要借书请输入0\n");
	scanf("%d",&a);
    if(a==1){
	_print();
	printf("需要借哪本书请输入他的编号:");
	scanf("%d",&id); 
	printf("是否确认借读？1--确认，0--取消!\n");
	number = _check(id);
	scanf("%d",&ok);} 
	else if(a==0){
	printf("press \"yes\" to back menu!");
	 scanf("%s",tips);
		} 

	if( ok == 1)

	{
		printf("借书操作正在进行……\n");//进行借书操作
		sleep(1);
		for(i = number; i  <  n ; i++)
		{
		books[i] = books[i+1];
		}
		n--;
		printf("借书成功！\n");
		_wcord(); 
	}
	//判断是否继续操作
	printf("press \"yes\" to back menu!");
	scanf("%s",tips);
	} 


