// thread_sync.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <windows.h>

HANDLE g_semaphore = nullptr;
int g_num_semaphore = 0;

void func_1_semaphore() {
  while (g_num_semaphore < 20) {
    WaitForSingleObject(g_semaphore, INFINITE);
    ++g_num_semaphore;
    Sleep(100);

    std::cout << "func_1 g_num:" << g_num_semaphore << std::endl;
    long lcount = 0;
    ReleaseSemaphore(g_semaphore, 1, &lcount);
  }
}

void func_2_semaphore() {
  while (g_num_semaphore < 20) {
    WaitForSingleObject(g_semaphore, INFINITE);
    ++g_num_semaphore;
    Sleep(100);

    std::cout << "func_2 g_num:" << g_num_semaphore << std::endl;
    long lcount = 0;
    ReleaseSemaphore(g_semaphore, 1, &lcount);
  }
}

int main4()
{
  g_semaphore = CreateSemaphore(NULL, 1, 100, L"thread_sync_semaphore");
  std::thread thread_1(func_1_semaphore);
  std::thread thread_2(func_2_semaphore);

  if (thread_1.joinable()) {
    thread_1.join();
  }
  if (thread_2.joinable()) {
    thread_2.join();
  }
  
  return 0;
}
