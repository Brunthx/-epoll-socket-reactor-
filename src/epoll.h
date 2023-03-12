/*************************************************************************
	> File Name: epoll.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月30日 星期一 11时53分27秒
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
