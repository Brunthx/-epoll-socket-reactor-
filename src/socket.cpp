/*************************************************************************
	> File Name: socket.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 11时43分30秒
 ************************************************************************/

#include"socket.h"
#include"inetaddress.h"
#include"util.h"
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<string.h>

Socket::Socket() : fd(-1)
{
	fd=socket(AF_INET,SOCK_STREAM,0);
	errif(fd==-1,"socket create error");
}

Socket::Socket(int _fd) : fd(_fd)
{
	errif(fd==-1,"socket create error");
}

Socket::~Socket()
{
	if(fd!=-1)
	{
		close(fd);
		fd=-1;
	}
}

void Socket::bind(InetAddress *_addr)
{
	struct sockaddr_in addr=_addr->getAddr();
	socklen_t addr_len=_addr->getAddr_len();
	errif(::bind(fd,(sockaddr *)&addr,addr_len)==-1,"socket bind error");
	_addr->setInetAddress(addr,addr_len);
}

void Socket::listen()
{
	errif(::listen(fd,SOMAXCONN)==-1,"socket listen error");
}

void Socket::setnonblocking()
{
	fcntl(fd,F_SETFL,fcntl(fd,F_GETFL)|O_NONBLOCK);
}

int Socket::accept(InetAddress *_addr)
{
	struct sockaddr_in addr;
	socklen_t addr_len=sizeof(addr);
	bzero(&addr,sizeof(addr));
	int cli_sockfd=::accept(fd,(sockaddr *)&addr,&addr_len);
	errif(cli_sockfd==-1,"socket accept error");
	_addr->setInetAddress(addr,addr_len);
	return cli_sockfd;
}

void Socket::connect(InetAddress *_addr)
{
	struct sockaddr_in addr=_addr->getAddr();
	socklen_t addr_len=_addr->getAddr_len();
	errif(::connect(fd,(sockaddr *)&addr,addr_len)==-1,"socket connect error");
}

int Socket::getFd()
{
	return fd;
}
