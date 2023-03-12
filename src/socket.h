/*************************************************************************
	> File Name: socket.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月29日 星期日 22时34分41秒
 ************************************************************************/

#pragma once

class InetAddress;
class Socket
{
private:
	int fd;

public:
	Socket();
	Socket(int _fd);
	~Socket();

	void bind(InetAddress *);
	void listen();
	void setnonblocking();

	int accept(InetAddress *);
	void connect(InetAddress *);

	int getFd();
};
