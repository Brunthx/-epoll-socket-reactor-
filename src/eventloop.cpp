/*************************************************************************
	> File Name: eventloop.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月30日 星期一 20时50分57秒
 ************************************************************************/

#include"eventloop.h"
#include"epoll.h"
#include"channel.h"
#include"threadpool.h"
#include<vector>

EventLoop::EventLoop() : ep(nullptr),threadPool(nullptr),quit(false)
{
	ep=new Epoll();
	threadPool=new ThreadPool();
}

EventLoop::~EventLoop()
{
	delete ep;
}

void EventLoop::loop()
{
	while(!quit)
	{
		std::vector<Channel *> chs;
		chs=ep->poll();
		for(auto it=chs.begin();it!=chs.end();++it)
		{
			(*it)->handleEvent();
		}
	}
}

void EventLoop::updateChannel(Channel *ch)
{
	ep->updateChannel(ch);
}

void EventLoop::addThread(std::function<void()> func)
{
	threadPool->add(func);
}
