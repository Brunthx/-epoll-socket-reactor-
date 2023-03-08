/*************************************************************************
	> File Name: connection.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 20时03分10秒
 ************************************************************************/

#pragma once
#include<functional>
#include<string.h>

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

	void echo(int sockfd);
	void setDeleteConnectionCallback(std::function<void(Socket *)>);
};
