/*************************************************************************
	> File Name: eventloop.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月30日 星期一 13时33分47秒
 ************************************************************************/

#pragma once
#include<functional>

class Epoll;
class Channel;
class ThreadPool;
class EventLoop
{
private:
	Epoll *ep;
	ThreadPool *threadPool;
	bool quit;

public:
	EventLoop();
	~EventLoop();

	void loop();
	void updateChannel(Channel *);

	void addThread(std::function<void()>);
};
