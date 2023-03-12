/*************************************************************************
	> File Name: acceptor.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月30日 星期一 21时07分36秒
 ************************************************************************/

#pragma once
#include<functional>
#include<cstdio>

class EventLoop;
class Socket;
class Channel;
class Acceptor
{
private:
	EventLoop *loop;
	Socket *sock;
	Channel *acceptChannel;
	std::function<void(Socket *)> newConnectionCallback;

public:
	Acceptor(EventLoop *_loop);
	~Acceptor();

	void acceptConnection();
	void setNewConnectionCallback(std::function<void(Socket *)>);
};
