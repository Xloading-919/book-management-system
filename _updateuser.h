void _updateuser()
{
	extern int PASSWORD[N];
	extern int mysock_fd;
	extern struct sockaddr_in server_addr;
	int id, password;
	//和服务器建立连接
	//建立套接字
	mysock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (mysock_fd == -1)
	{
		perror("socket");
		exit(1);
	}
	//地址结构
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_SERVER);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(&(server_addr.sin_zero), 8);
	//connect
	if (connect(mysock_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("connect");
		exit(1);
	}
	//先接收服务器发来的基础数据
	if (recv(mysock_fd, PASSWORD, sizeof(PASSWORD), 0) <= 0)
	{
		perror("recv");
		exit(1);
	}
	printf("OK！客户端数据与服务器同步！\n");
	sleep(1);
	printf("OK！同步完成！\n");
	sleep(1);
	while (1) //输入登录代号
	{
		printf("输入要修改密码的代号：");
		scanf("%d", &id);
		getchar();
		if (!(id >= 1 && id <= N)) //验证用户是否存在
		{
			printf("无此用户，重新选择！\n");
			continue;
		}
		else
		{
			break;
		}
	}
	printf("输入修改密码：");
	scanf("%d", &password);
	getchar();
	PASSWORD[id - 1] = password;
	//保存数据到文件
	FILE *fp;
	int i; 
	fp = fopen("userlog.dat", "w");
	for (i = 0; i < N; i++)
	{
		fprintf(fp, "%d %d\n", i, PASSWORD[i]);
	}
	fclose(fp);
	//和服务器收发数据
	if (send(mysock_fd, PASSWORD, sizeof(PASSWORD), 0) == -1)
	{
		perror("send");
		exit(1);
	}
	printf("修改成功！\n");
	sleep(1);
	close(mysock_fd);
}
