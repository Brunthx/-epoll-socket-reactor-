/*************************************************************************
	> File Name: eventloop.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 18时25分26秒
 ************************************************************************/

#include"channel.h"
#include"eventloop.h"
#include"epoll.h"
#include<vector>

EventLoop::EventLoop() : ep(nullptr),quit(false)
{
	ep=new Epoll();
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
