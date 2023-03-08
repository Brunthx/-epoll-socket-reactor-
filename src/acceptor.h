/*************************************************************************
	> File Name: acceptor.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 18时38分27秒
 ************************************************************************/

#pragma once
#include<functional>

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
