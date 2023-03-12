/*************************************************************************
	> File Name: threadpool.h
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月30日 星期一 13时41分08秒
 ************************************************************************/

#pragma once

#include<functional>
#include<vector>
#include<queue>
#include<thread>
#include<mutex>
#include<condition_variable>

class ThreadPool
{
public:
	std::vector<std::thread> threads;
	std::queue<std::function<void()>> tasks;
	std::mutex tasks_mtx;
	std::condition_variable cv;
	bool stop;

public:
	ThreadPool(int size=10);
	~ThreadPool();

	void add(std::function<void()>);
};
