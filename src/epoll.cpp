/*************************************************************************
	> File Name: epoll.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月30日 星期一 12时05分03秒
 ************************************************************************/

#include"channel.h"
#include"util.h"
#include"epoll.h"
#include<unistd.h>
#include<string.h>

#define MAX_EVENTS 1000

Epoll::Epoll() : epfd(-1),events(nullptr)
{
	epfd=epoll_create1(0);
	errif(epfd==-1,"epoll create error");
	events=new epoll_event[MAX_EVENTS];
	bzero(events,sizeof(*events)* MAX_EVENTS);
}

Epoll::~Epoll()
{
	if(epfd!=-1)
	{
		close(epfd);
		epfd=-1;
	}
	delete [] events;
}

std::vector<Channel *>Epoll::poll(int timeout)
{
	std::vector<Channel *>activeChannels;
	int nfds=epoll_wait(epfd,events,MAX_EVENTS,timeout);
	errif(nfds==-1,"epoll wait error");
	for(int i=0;i<nfds;++i)
	{
		Channel *ch=(Channel *)events[i].data.ptr;
		ch->setRevents(events[i].events);
		activeChannels.push_back(ch);
	}
	return activeChannels;
}

void Epoll::updateChannel(Channel *channel)
{
	int fd=channel->getFd();
	struct epoll_event ev;
	bzero(&ev,sizeof(ev));
	ev.data.ptr=channel;
	ev.events=channel->getEvents();
	if(!channel->getInEpoll())
	{
		errif(epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&ev)==-1,"epoll add error");
	}
	else
	{
		errif(epoll_ctl(epfd,EPOLL_CTL_MOD,fd,&ev)==-1,"epoll modify error");
	}
}
