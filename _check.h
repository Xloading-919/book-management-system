/*
功能：记录查重,重复则返回下标，无重复记录则返回-1
函数名:_check()
形参：int idBuff
返回值: int 
*/
int _check(int number)
{
	int i;
	extern _bk books[MAX];
	extern int n; 
	for(i = n-1; i >= 0; i--)
	{
		if(books[i].id == number) 
		break;//终止循环
	}
	return i;//返回当前书的位置下标
}

