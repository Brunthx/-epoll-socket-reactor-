/*************************************************************************
	> File Name: epoll.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 16时22分03秒
 ************************************************************************/

#pragma once
#include<sys/epoll.h>
#include<vector>

class Channel;
class Epoll
{
private:
	int epfd;
	struct epoll_event *events;

public:
	Epoll();
	~Epoll();

	void updateChannel(Channel *);
	
	std::vector<Channel *> poll(int timeout=-1);
};
