// thread_sync.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <windows.h>

int g_num = 0;

void func_1() {
  while (g_num < 20) {
    ++g_num;
    Sleep(100);

    std::cout << "func_1 g_num:" << g_num << std::endl;
  }
}

void func_2() {
  while (g_num < 20) {
    ++g_num;
    Sleep(100);

    std::cout << "func_2 g_num:" << g_num << std::endl;
  }
}

int main1()
{
  std::thread thread_1(func_1);
  std::thread thread_2(func_2);

  if (thread_1.joinable()) {
    thread_1.join();
  }
  if (thread_2.joinable()) {
    thread_2.join();
  }
  
  return 0;
}
