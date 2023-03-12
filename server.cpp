/*************************************************************************
	> File Name: server.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月31日 星期二 16时54分54秒
 ************************************************************************/

#include"src/eventloop.h"
#include"src/server.h"

int main()
{
	EventLoop *loop=new EventLoop();
	Server *server=new Server(loop);
	loop->loop();
	delete loop;
	delete server;
	return 0;
}
