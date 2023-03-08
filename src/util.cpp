/*************************************************************************
	> File Name: util.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2023年01月26日 星期四 12时52分46秒
 ************************************************************************/

#include "util.h"
#include <stdio.h>
#include <stdlib.h>

void errif(bool condition, const char *errmsg)
{
    if(condition)
	{
        perror(errmsg);
        exit(EXIT_FAILURE);
    }
}
