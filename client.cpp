/*************************************************************************
	> File Name: client.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月31日 星期二 12时47分19秒
 ************************************************************************/

#include<iostream>
#include<unistd.h>
#include<string.h>
#include"src/util.h"
#include"src/buffer.h"
#include"src/inetaddress.h"
#include"src/socket.h"

using namespace std;

int main()
{
	Socket *sock=new Socket();
	InetAddress *addr=new InetAddress("127.0.0.1",1234);
	sock->connect(addr);

	int sockfd=sock->getFd();

	Buffer *sendBuffer=new Buffer();
	Buffer *readBuffer=new Buffer();

	while(true)
	{
		sendBuffer->getline();
		ssize_t write_bytes=write(sockfd,sendBuffer->c_str(),sendBuffer->size());
		if(write_bytes==-1)
		{
			printf("socket already disconnected, can't write anymore!\n");
			break;
		}
		int already_read=0;
		char buf[1024];
		while(true)
		{
			bzero(&buf,sizeof(buf));
			ssize_t read_bytes=read(sockfd,buf,sizeof(buf));
			if(read_bytes>0)
			{
				readBuffer->append(buf,read_bytes);
				already_read+=read_bytes;
			}
			else if(read_bytes==-1)
			{
				printf("continue reading");
				continue;
			}
			else if(read_bytes==0)
			{
				printf("server disconnected!\n");
				exit(EXIT_SUCCESS);
			}
			if(already_read>=readBuffer->size())
			{
				printf("message from server: %s\n",readBuffer->c_str());
				break;
			}
		}
		readBuffer->clear();
	}
	delete addr;
	delete sock;
	return 0;
}
