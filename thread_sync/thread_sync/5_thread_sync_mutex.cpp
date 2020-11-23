// thread_sync.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <windows.h>

HANDLE g_mutex = nullptr;
int g_num_mutex = 0;

void func_1_mutex() {
  while (g_num_mutex < 20) {
    WaitForSingleObject(g_mutex, INFINITE);
    ++g_num_mutex;
    Sleep(100);

    std::cout << "func_1 g_num:" << g_num_mutex << std::endl;
    long lcount = 0;
    ReleaseMutex(g_mutex);
  }
}

void func_2_mutex() {
  while (g_num_mutex < 20) {
    WaitForSingleObject(g_mutex, INFINITE);
    ++g_num_mutex;
    Sleep(100);

    std::cout << "func_2 g_num:" << g_num_mutex << std::endl;
    long lcount = 0;
    ReleaseMutex(g_mutex);
  }
}

int main()
{
  g_mutex = CreateMutex(NULL, false, L"thread_sync_mutex");
  std::thread thread_1(func_1_mutex);
  std::thread thread_2(func_2_mutex);

  if (thread_1.joinable()) {
    thread_1.join();
  }
  if (thread_2.joinable()) {
    thread_2.join();
  }
  
  return 0;
}
