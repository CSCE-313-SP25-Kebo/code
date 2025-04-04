/*
Example: Thread synchronization without condition variable. Busy-wait implementation
*/

#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

std::mutex g_mutex;
bool g_ready = false;  // not a condition variable!

// Producer : generate the data
void workThread() {
  // Simulation of producing data
  std::this_thread::sleep_for(std::chrono::seconds(30));  // If the producer takes a long time to get the dat ready !
  std::unique_lock<std::mutex> ul(g_mutex);
  g_ready = true;
  // No need to unlock !
} // Once we are out the function scope - the lock is automatically released


// Consumer will busy wait loop - Polling !
void waitThread() {
  while(!g_ready){// Wait on the flag -- polling -- this is a busy wait mechanism

  }
  // Do not start using the data until g_ready is true!
  // Consume the data - use the data
  std::cout << "Wait Thread Executed! \n";
}

int main() {
  std::thread t1(workThread);
  std::thread t2(waitThread);
  t1.join();
  t2.join();
  return 0;
}