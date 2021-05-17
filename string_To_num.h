/*
函数:string_To_num( char s[], int len)
功能：将字符数组中的数字字符转换为数字
参数：char s[], int len
返回值：int
*/ 
int string_To_num( char s[], int len)//s为要转换的数组，len为数组的长度
{
	int i, sum = 0;//sum存储转换的数字 
	//循环遍历数组，将输入的字符串转换为数字
	for(i = 0; i < len; i++) 
	{
		//若字符串中有不为数字的其他字符则忽略，仅将数字字符转换为数字
		if(s[i] != '\0' && s[i] <= '9' && s[i] >= '0') 
		{
			sum *= 10;
			sum += (s[i] - '0');
		}
		//数组结束，直接跳出循环
		else if(s[i] == '\0')
		{
			break;
		}
	}
	return sum;
}

