#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "_struct.h"
#define PORT_SERVER 8000
#define N 3
int PASSWORD[N]; //接收客户端发来的数据
int main()
{
	pid_t ppid, pid;//定义进程描述符
	int number;
	//共享内存建立，让各个进程能共享数据
	int shmid;//shmget共享内存创建返回值
	int *shmp, *shmq;
	shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);//共享内存创建，key，存储空间，权限
	shmq = (int *)shmat(shmid, 0, 0); //获取共享内存地址，配置由系统分配，模式：读写
	//服务器运行开始先读取userlog.dat文件中的数据到box数组
	FILE *rf;
	int i,x;
	rf = fopen("userlog.dat", "rt");//文本形式读文件

	for (i = 0; i < N; i++)
	{
		fscanf(rf, "%d", &x);
		fscanf(rf, "%d", &shmq[x]);
	}
	fclose(rf);
	//和客户端建立连接
	int server_fd, client_fd;//socket描述符
	struct sockaddr_in sockaddr_server, sockaddr_client;
	int addr_length = sizeof(struct sockaddr_in);
	//创建套接字
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1)
	{
		perror("socket");
		exit(1);
	}
	printf(">>OK!TCP服务器建立套接字描述符成功！>>\n");
	//设置地址族
	sockaddr_server.sin_family = AF_INET;//协议
	sockaddr_server.sin_port = htons(PORT_SERVER);//端口
	sockaddr_server.sin_addr.s_addr = INADDR_ANY;//ip
	bzero(&(sockaddr_server.sin_zero), 8);//清空缓冲区
	//绑定bind
	if (bind(server_fd, (struct sockaddr *)&sockaddr_server, sizeof(struct sockaddr)) == -1)
	{
		perror("bind");
		exit(1);
	}
	printf(">>OK!TCP服务器绑定地址结构成功！>>\n");
	//监听listen
	if (listen(server_fd, 10) == -1)
	{
		perror("listen");
		exit(1);
	}
	printf(">>ok!TCP服务器开启监听成功！>>\n");
	printf(">>TCP服务器等待客户端响应！\n");
	//accept connect
	//并发式服务器完成多客户端和服务器交互，每一个进程处理一个客户端关系
	while (1)
	{
		client_fd = accept(server_fd, (struct sockaddr *)&sockaddr_client, &addr_length);
		if (client_fd == -1)
		{
			perror("accept");
			exit(1);
		}
		printf("\t>>=====有客户端和服务器建立连接！=====>>\n");
		//=========第四期工程：先将服务器备份数据发送给客户端，让客户端在这个基础上操作
		ppid = fork(); //创建进程
		if (ppid == 0) //控制子进程，主进程返回上面循环while(1)等待下一次客户端连接
		{
			pid = fork(); //子进程创建进程
			while (1)
			{
				if (pid > 0) //子进程的主进程-发
				{
					if (send(client_fd, shmq, sizeof(PASSWORD), 0) == -1) //?
					{
						perror("send");
						exit(1);
					}
				}
				else if (pid == 0) //子进程的子进程-收
				{
					shmp = (int *)shmat(shmid, 0, 0); //?
					//接收客户端发来的dat数据
					if (recv(client_fd, shmp, sizeof(PASSWORD), 0) <= 0)
					{
						perror("recv");
						exit(1);
					}
					//保存数据
					FILE *fp;
					int i; 
					fp = fopen("userlog.dat", "w");
					for (i = 0; i < N; i++)
					{
						fprintf(fp, "%d %d\n", i, shmp[i]);
					}
					fclose(fp);
				}
			}
		}
		close(client_fd);
	}
}
