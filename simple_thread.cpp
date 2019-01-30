#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<chrono>
struct sync {
  std::mutex m;
  std::condition_variable cond;
  int count;
  bool even;
  sync():count(0), even(false){ }
};

void Print(int& i, const std::string& s){
  std::cout << s <<"[" << std::this_thread::get_id() << "]" << ": " <<  i << std::endl;
  i++;
}

void Print(bool&f ,int& i, const std::string& s){
  std::cout << s <<"[" << std::this_thread::get_id() << "]" << ": " <<  i << std::endl;
  i++;
  f = !f;
}


void runOdd(sync& s) {
  while(s.count < 25) {
    std::unique_lock<std::mutex> ul(s.m);
    s.cond.wait(ul, [&s](){return (s.count % 2 == 1);});
    Print(s.count, "[Odd]");
    ul.unlock();
    s.cond.notify_all();
  }
  return;
}
void runEven(sync& s) {
  while(s.count < 25) {
    std::unique_lock<std::mutex> ul(s.m);
    s.cond.wait(ul, [&s](){return (s.count % 2 == 0);});
    Print(s.count, "[Even]");
    ul.unlock();
    s.cond.notify_all();
  }
  return;
}

void run(sync& s) {
  std::unique_lock<std::mutex> ul(s.m);
  while(s.count < 25) {
    if(s.even) {
      s.cond.wait(ul, [&s](){return (s.even);});
      Print(s.even, s.count, "[Even]");
    } else {
      s.cond.wait(ul, [&s](){return (s.even == false);});
      Print(s.even, s.count, "[Odd]");
    }
  }
  ul.unlock();
  s.cond.notify_all();
  return; 
}

int main() {
  sync sync_obj;
  sync_obj.even = true;
  std::thread aThread2(runEven, std::ref(sync_obj));
  std::thread aThread1(runOdd, std::ref(sync_obj));
  //std::thread aThread3(runEven, std::ref(sync_obj));
  //std::thread aThread4(runOdd, std::ref(sync_obj));
  //cond.notify_one();
  aThread1.join();
  aThread2.join();
  //aThread3.join();
  //aThread4.join();
  return 0;
}
