#include <iostream>       // std::cout
#include <iomanip>        // std::put_time
#include <thread>         // std::this_thread::sleep_until
#include <chrono>         // std::chrono::system_clock
#include "function.h"

 
int main(int argc, char *argv[]) 
{
  using std::chrono::system_clock;
  std::time_t tt = system_clock::to_time_t (system_clock::now());

  struct std::tm * ptm = std::localtime(&tt);
  std::cout << "Current time: " << std::put_time(ptm,"%X") << '\n';
  std::cout << "Waiting for the next minute to begin...\n";
  std::cout << "As long as time goes by we will write stars...\n";
  std::cout << "==============================================================\n";

  std::thread th(print_);

  th.detach();

  ++ptm->tm_min; ptm->tm_sec=0;
  std::this_thread::sleep_until(system_clock::from_time_t(mktime(ptm)));

  std::cout << "==============================================================\n";
  std::cout << std::put_time(ptm,"%X") << " reached!\n";

  return 0;
}