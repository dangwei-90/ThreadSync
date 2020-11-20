// thread_sync.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <windows.h>

HANDLE g_event = nullptr;
int g_num_event = 0;

void func_1_event() {
  while (g_num_event < 20) {
    WaitForSingleObject(g_event, INFINITE);
    ++g_num_event;
    Sleep(100);

    std::cout << "func_1 g_num:" << g_num_event << std::endl;
    SetEvent(g_event);
  }
}

void func_2_event() {
  while (g_num_event < 20) {
    WaitForSingleObject(g_event, INFINITE);
    ++g_num_event;
    Sleep(100);

    std::cout << "func_2 g_num:" << g_num_event << std::endl;
    SetEvent(g_event);
  }
}

int main()
{
  g_event = CreateEvent(NULL, FALSE, TRUE, L"thread_sync_event");
  std::thread thread_1(func_1_event);
  std::thread thread_2(func_2_event);

  if (thread_1.joinable()) {
    thread_1.join();
  }
  if (thread_2.joinable()) {
    thread_2.join();
  }
  
  return 0;
}
