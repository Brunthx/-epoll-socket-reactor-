/*************************************************************************
	> File Name: connection.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月30日 星期一 22时38分59秒
 ************************************************************************/

#pragma once
#include<functional>
#include<string>

class EventLoop;
class Socket;
class Channel;
class Buffer;
class Connection
{
private:
	EventLoop *loop;
	Socket *sock;
	Channel *channel;
	std::function<void(Socket *)> deleteConnectionCallback;
	std::string *inBuffer;
	Buffer *readBuffer;

public:
	Connection(EventLoop *_loop,Socket *_sock);
	~Connection();

	void echo(int fd);
	void setDeleteConnectionCallback(std::function<void(Socket *)>);
};
