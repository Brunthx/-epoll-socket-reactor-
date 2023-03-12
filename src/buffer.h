/*************************************************************************
	> File Name: buffer.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月29日 星期日 22时10分38秒
 ************************************************************************/

#pragma once
#include<string>

class Buffer
{
private:
	std::string buf;

public:
	Buffer();
	~Buffer();

	void append(const char *_str,int _size);
	ssize_t size();
	const char *c_str();
	void clear();
	void getline();
};
