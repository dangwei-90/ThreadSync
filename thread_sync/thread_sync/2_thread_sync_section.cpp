// thread_sync.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <windows.h>

CRITICAL_SECTION g_critical;		//定义临界区句柄
int g_num_section = 0;

void func_1_section() {
  while (g_num_section < 20) {
    EnterCriticalSection(&g_critical);
    ++g_num_section;
    Sleep(100);

    std::cout << "func_1 g_num:" << g_num_section << std::endl;
    LeaveCriticalSection(&g_critical);
  }
}

void func_2_section() {
  while (g_num_section < 20) {
    EnterCriticalSection(&g_critical);
    ++g_num_section;
    Sleep(100);

    std::cout << "func_2 g_num:" << g_num_section << std::endl;
    LeaveCriticalSection(&g_critical);
  }
}

int main2()
{
  InitializeCriticalSection(&g_critical);
  std::thread thread_1(func_1_section);
  std::thread thread_2(func_2_section);

  if (thread_1.joinable()) {
    thread_1.join();
  }
  if (thread_2.joinable()) {
    thread_2.join();
  }
  
  return 0;
}
