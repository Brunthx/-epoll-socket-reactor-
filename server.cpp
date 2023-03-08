/*************************************************************************
	> File Name: server.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 22时30分51秒
 ************************************************************************/

#include "src/EventLoop.h"
#include "src/Server.h"

int main() 
{
    EventLoop *loop = new EventLoop();
    Server *server = new Server(loop);
    loop->loop();
    delete server;
    delete loop;
    return 0;
}
