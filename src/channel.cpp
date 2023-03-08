/*************************************************************************
	> File Name: channel.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 12时53分44秒
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
	callback();
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

bool Channel::getInEpoll()
{
	return inEpoll;
}

void Channel::setInEpoll()
{
	inEpoll=true;
}

void Channel::setRevents(uint32_t _ev)
{
	revents=_ev;
}

void Channel::setCallback(std::function<void()> _cb)
{
	callback=_cb;
}
