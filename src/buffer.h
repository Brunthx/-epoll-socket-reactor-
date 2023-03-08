/*************************************************************************
	> File Name: buffer.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月27日 星期五 20时13分08秒
 ************************************************************************/

#pragma once
#include<iostream>
#include<string.h>

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
