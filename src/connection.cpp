/*************************************************************************
	> File Name: connection.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 20时40分56秒
 ************************************************************************/

#include"channel.h"
#include"connection.h"
#include"buffer.h"
#include"socket.h"
#include"util.h"
#include<string.h>
#include<unistd.h>
#include<iostream>

Connection::Connection(EventLoop *_loop,Socket *_sock) : loop(_loop),sock(_sock),channel(nullptr),inBuffer(new std::string()),readBuffer(nullptr)
{
	channel=new Channel(loop,sock->getFd());
	std::function<void()> cb=std::bind(&Connection::echo,this,sock->getFd());
	channel->setCallback(cb);
	channel->enableReading();
	readBuffer=new Buffer();
}

Connection::~Connection()
{
	delete channel;
	delete sock;
}

void Connection::echo(int sockfd)
{
	char buf[1024];//这个buf大小无所谓
	while(true)
	{
		bzero(&buf,sizeof(buf));
		ssize_t read_bytes=read(sockfd,buf,sizeof(buf));
		if(read_bytes>0)
		{
			readBuffer->append(buf,read_bytes);
		}
		else if(read_bytes==-1&&errno==EINTR)
		{
			printf("continue reading");
			continue;
		}
		else if(read_bytes==-1&&((errno==EAGAIN)||(errno==EWOULDBLOCK)))
		{
			printf("finish reading once\n");
			printf("message from client fd %d: %s\n",sockfd,readBuffer->c_str());
			errif(write(sockfd,readBuffer->c_str(),readBuffer->size())==-1,"socket write error");
			readBuffer->clear();
			break;
		}
		else if(read_bytes==0)
		{
			printf("EOF,client fd %d disconnected\n",sockfd);
			deleteConnectionCallback(sock);
			break;
		}
	}
}

void Connection::setDeleteConnectionCallback(std::function<void(Socket *)> _cb)
{
	deleteConnectionCallback=_cb;
}
