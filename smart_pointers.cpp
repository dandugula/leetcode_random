#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
std::mutex m;
std::unique_ptr<int> getObj() {
  return std::unique_ptr<int> (new int (700));
}
std::unique_ptr<int> getObj1() {
  std::unique_ptr<int> res (new int (800) );
  return res;
}
std::unique_ptr<int>&& getObj2() {
  std::unique_ptr<int> res (new int (800) );
  return std::move(res);
}
void foo(std::shared_ptr<int> sPtr) {
  std::lock_guard<std::mutex> lg(m);
  *sPtr += 1; 
  std::cout << "In foo: " << *sPtr.get() << std::endl;
}

void bar(std::unique_ptr<int> uPtr) {
  (*uPtr)++;
  std::cout << "In bar: " << *uPtr.get() << std::endl;
}

void wfoo(std::weak_ptr<int> wPtr) {
  std::lock_guard<std::mutex> lg(m);
  if(auto sp = wPtr.lock()) 
    std::cout << "In foo (weak_ptr): " << *sp << std::endl;
  else
    std::cout << "wPtr expired" << std::endl;
}

int main () {
  std::unique_ptr<int> valuePtr (new int (500));
  //std::unique_ptr<int> dupPtr (std::move(valuePtr));
  //std::unique_ptr<int> dupPtr (new int (600));
  //std::unique_ptr<int> dupPtr (getObj2());
  //dupPtr.reset(std::move(valuePtr));

  //std::cout << "*dupPtr = " << *dupPtr << std::endl;
  //std::cout << "*getObj() = " << *getObj() << std::endl;
  std::cout << "is valuePtr valid? " << std::boolalpha << static_cast<bool>(valuePtr) << std::endl;

  bar(std::move(valuePtr));
  std::cout << "is valuePtr valid? " << std::boolalpha << static_cast<bool>(valuePtr) << std::endl;
  std::shared_ptr<int> sPtr(new int(998));
  std::thread t (foo, sPtr);
  std::thread u (wfoo, std::weak_ptr<int>(sPtr));
  {
    std::lock_guard<std::mutex> lg(m);
    std::cout << "In main thread: " << *sPtr.get() << std::endl;
    sPtr.reset();
  }

  t.join();
  u.join();
  return 0;
}
