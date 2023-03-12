/*************************************************************************
	> File Name: channel.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月30日 星期一 13时19分29秒
 ************************************************************************/

#include"channel.h"
#include"eventloop.h"
#include<unistd.h>

Channel::Channel(EventLoop *_loop,int _fd) : loop(_loop),fd(_fd),events(0),revents(0),inEpoll(false)
{
}

Channel::~Channel()
{
	if(fd!=-1)
	{
		close(fd);
		fd=-1;
	}
}

void Channel::handleEvent()
{
	loop->addThread(callback);
}

void Channel::enableReading()
{
	events|=EPOLLIN|EPOLLET;
	loop->updateChannel(this);
}

int Channel::getFd()
{
	return fd;
}

uint32_t Channel::getEvents()
{
	return events;
}

uint32_t Channel::getRevents()
{
	return revents;
}

void Channel::setInEpoll()
{
	inEpoll=true;
}

bool Channel::getInEpoll()
{
	return inEpoll;
}

void Channel::setRevents(uint32_t _ev)
{
	revents=_ev;
}

void Channel::setCallback(std::function<void()> _cb)
{
	callback=_cb;
}
