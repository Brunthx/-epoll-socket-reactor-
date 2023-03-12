/*************************************************************************
	> File Name: threadpool.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月30日 星期一 16时59分31秒
 ************************************************************************/

#include"threadpool.h"

ThreadPool::ThreadPool(int size) : stop(false)
{
	for(int i=0;i<size;++i)
	{
		threads.emplace_back(std::thread(
					[this]()
					{
						while(true)
						{
							std::function<void()> task;
							{
								std::unique_lock<std::mutex> lock(tasks_mtx);
								cv.wait(lock,[this]()
										{
											return stop||!tasks.empty();	
										});
								if(stop&&tasks.empty())
								{
									return;
								}
								task=tasks.front();
								tasks.pop();
							}
							task();
						}
					}));
	}
}

ThreadPool::~ThreadPool()
{
	{
		std::unique_lock<std::mutex> lock(tasks_mtx);
		stop=true;
	}//猜测这部分等价于注释，实际运行貌似注释掉也不影响
	cv.notify_all();
	for(std::thread &th : threads)
	{
		if(th.joinable())
		{
			th.join();
		}
	}
}

void ThreadPool::add(std::function<void()>func)
{
	{
		std::unique_lock<std::mutex> lock(tasks_mtx);
		if(stop)
		{
			throw std::runtime_error("ThreadPool already stop, can't add task anymore");
		}
		tasks.emplace(func);
	}
	cv.notify_one();
}
