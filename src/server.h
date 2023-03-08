/*************************************************************************
	> File Name: server.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 21时28分58秒
 ************************************************************************/

#pragma once
#include<map>

class EventLoop;
class Socket;
class Acceptor;
class Connection;
class Server
{
private:
	EventLoop *loop;
	Acceptor *acceptor;
	std::map<int,Connection *> connections;

public:
	Server(EventLoop *);
	~Server();

	void handleReadEvent(int);
	void newConnection(Socket *sock);
	void deleteConnection(Socket *sock);
};
