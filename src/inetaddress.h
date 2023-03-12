/*************************************************************************
	> File Name: inetaddress.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月29日 星期日 22时22分49秒
 ************************************************************************/

#pragma once
#include<arpa/inet.h>

class InetAddress
{
private:
	struct sockaddr_in addr;
	socklen_t addr_len;

public:
	InetAddress();
	InetAddress(const char *ip,uint16_t port);
	~InetAddress();

	void setInetAddress(sockaddr_in _addr,socklen_t _addr_len);
	sockaddr_in getAddr();
	socklen_t getAddr_len();
};
