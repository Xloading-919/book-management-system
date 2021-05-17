#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#define PORT_SERVER 8000
#define N 3
#include "_struct.h"
#include "string_To_num.h"
#include "_wcord.h"
#include "_rcord.h"
#include "_toContinue.h"
#include "_continue.h"
#include "_check.h"
#include "_insert.h"
#include "_select.h"
#include "_delete.h"
#include "_print.h"
#include "_update.h"
#include "_usermenu.h"
#include "_borrow.h"
#include "_updateuser.h"
#include "_glmenu2.h"
int PASSWORD[N] = {0};
int mysock_fd;//套接字描述符
struct sockaddr_in server_addr;
int main()
{
	char s[20];//控制字符串
	int id, password, x = 0;
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
	//先接收服务器发来的用户数据
	if (recv(mysock_fd, PASSWORD, sizeof(PASSWORD), 0) <= 0) //和服务器数据同步
	{
		perror("recv");
		exit(1);
	}
	printf("OK！客户端数据与服务器同步！\n");
	sleep(1);
	printf("OK！同步完成！\n");
	sleep(1);
	close(mysock_fd);

	_rcord(); //读取本地图书资料文件
	while (1) //输入登录代号
	{
		printf("输入代号以登陆(代号1为管理员)：");
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
	while (1) //输入登录密码
	{
		printf("密码：");
		scanf("%d", &password);
		if (password != PASSWORD[id - 1])
		{
			printf("密码错误！请核对后输入！\n");
		}
		else //密码正确
		{
			printf("欢迎！\n");
			sleep(1);
			x = 1;
			break;
		}
	}
	//调用菜单循环
	while (x)
	{
		if(id == 1)
		{
			_glmenu2();
			scanf("%s", s);
			//菜单
			switch (string_To_num(s, 20)) //调用字符串转数字函数,控制菜单
			{
			case 1:_insert();break;
			case 2:_delete();break;
			case 3:_update();break;
			case 4:_select();break;
			case 5:_print();break;
			case 6:_updateuser();break;
			case 0:exit(0); //退出
			default:printf("输入有误！请核对后输入！\n");continue;
			}
		}
		else
		{
			_usermenu();
			scanf("%s", s);
			//菜单
			switch (string_To_num(s, 20)) //调用字符串转数字函数,控制菜单
			{
			case 1:_insert();break;
			case 2:_select();break;
			case 3:_borrow();break;
			case 4:_print();break;
			case 0:exit(0); //退出
			default:printf("输入有误！请核对后输入！\n");continue;
			}
		}
	}
	exit(0);
}
