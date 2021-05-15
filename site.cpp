#include <WinSock2.h>           //网络库头文件
#include <stdio.h>
#include <stdlib.h>
#pragma comment(lib,"Ws2_32.lib")//动态链接库
 


int main()
{

	WORD wdVersion = MAKEWORD(2, 2);  //定义WORD型变量为调用的网络库版本  WORD型等同于 unsigned short
	WSADATA wdScokMsg;                //LPWWSADATA lpw =malloc(sizeof(WSADATA)) 也可以定义指针
	int nRes = WSAStartup(wdVersion, &wdScokMsg);//打开网络库，调用成功则返回值为0

	if (0 != nRes)
	{
		switch (nRes)
		{
		case WSASYSNOTREADY:                 //返回值10091
				printf("重启电脑，或检查网络库环境");
				break;
		case WSAVERNOTSUPPORTED:             //返回值10092
			printf("请更新网络库");         
					break;
		case WSAEINPROGRESS:                 //返回值10036
			printf("当前windows sockets实现超出限制数量，请重新启动"); 
					break;
		case WSAEPROCLIM:                    //返回值10067
			printf("运行阻塞，请尝试关闭不必要的软件");
					break;
		
		}
	}
	//校验版本
	if (2 != HIBYTE(wdScokMsg.wVersion) || 2 != LOBYTE(wdScokMsg.wVersion))//高位为副版本号 地位为主版本号 即2.2
	{
		//不满足则说明版本不对
		//关闭网络库
		WSACleanup ();
		return 0;
	}


	system("pause");
	return 0;
}