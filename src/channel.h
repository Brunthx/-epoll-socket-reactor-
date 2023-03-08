/*************************************************************************
	> File Name: channel.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 12时44分20秒
 ************************************************************************/

#pragma once
#include<sys/epoll.h>
#include<functional>

class EventLoop;
class Channel
{
private:
	EventLoop *loop;
	int fd;
	uint32_t events;
	uint32_t revents;
	bool inEpoll;
	std::function<void()> callback;

public:
	Channel(EventLoop *_loop,int _fd);
	~Channel();

	void handleEvent();
	void enableReading();

	int getFd();
	uint32_t getEvents();
	uint32_t getRevents();
	bool getInEpoll();
	void setInEpoll();

	void setRevents(uint32_t);
	void setCallback(std::function<void()>);
};
