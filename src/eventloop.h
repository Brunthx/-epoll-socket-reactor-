/*************************************************************************
	> File Name: eventloop.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 17时06分59秒
 ************************************************************************/

#pragma once

class Epoll;
class Channel;
class EventLoop
{
private:
	Epoll *ep;
	bool quit;

public:
	EventLoop();
	~EventLoop();

	void loop();
	void updateChannel(Channel *);
};
