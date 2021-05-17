/*
函数名：_toContinue()
功能：按yes 继续执行，按no退出，的组件
参数：void
返回值:void
*/
void _toContinue()
{
	char flag[100];//比对是否（yes or no） 的标记字符串
	printf("input \"yes\" to continue! input \"no\" to EXIT!\n");
	scanf("%s",flag);
	//比对
	if(strcmp(flag,"NO")==0 || strcmp(flag,"no")==0)
	{
		exit(0);
	}
	else 
	{
		return ;
	}
}

