/*************************************************************************
	> File Name: acceptor.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 18时45分12秒
 ************************************************************************/

#include"acceptor.h"
#include"channel.h"
#include"inetaddress.h"
#include"socket.h"

Acceptor::Acceptor(EventLoop *_loop) : loop(_loop),sock(nullptr),acceptChannel(nullptr)
{
	sock=new Socket();
	InetAddress *addr=new InetAddress("127.0.0.1",8888);
	sock->bind(addr);
	sock->listen();
	sock->setnonblocking();
	acceptChannel=new Channel(loop,sock->getFd());
	std::function<void()> cb=std::bind(&Acceptor::acceptConnection,this);
	acceptChannel->setCallback(cb);
	acceptChannel->enableReading();
	delete addr;
}

Acceptor::~Acceptor()
{
	delete sock;
	delete acceptChannel;
}

void Acceptor::acceptConnection()
{
	InetAddress *cli_addr=new InetAddress();
	Socket *cli_sock=new Socket(sock->accept(cli_addr));
	printf("new client fd %d!IP: %s Port: %d\n",cli_sock->getFd(),inet_ntoa(cli_addr->getAddr().sin_addr),ntohs(cli_addr->getAddr().sin_port));
	cli_sock->setnonblocking();
	newConnectionCallback(cli_sock);
	delete cli_addr;
}

void Acceptor::setNewConnectionCallback(std::function<void(Socket *)> _cb)
{
	newConnectionCallback=_cb;
}
