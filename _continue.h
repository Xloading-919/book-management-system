
int _continue()
{
	char flag[100];
	printf("input \"yes\" to continue! input \"no\" to EXIT!\n:");
	scanf("%s",flag);
	if(strcmp(flag,"no")==0 || strcmp(flag,"NO")==0) return 1;
	else return 0;
}

