#include <iostream>
class Base {
  public:
    virtual void foo () {
      std::cout << "Base class : foo" << std::endl;
    }
    void bar () {
      std::cout << "Base class : bar" << std::endl;
    }
};

int main ()
{
  Base b;
  int* ptr = nullptr;
  std::cout << "Size of Base: " << sizeof(b) << std::endl;
  std::cout << "Size of ptr: "<< sizeof(ptr) << std::endl;
  return 0;
}


