#include <iostream>
class Base {
  public:
    static void aStaticFunc() {
      std::cout << "Base::aStaticFunc()" << std::endl;
    }
    static int i;
};

int Base::i = 0;

class Derived : public Base {
};

template <typename T>
class Singleton {
  public:
    static T val;
    static Singleton<T>& getInstance() {
      static Singleton<T> mInstance;
      ++val;
      return mInstance;
    }
  static void disp() {
    std::cout << "This is a Singleton Object" << std::endl;
  }
  private:
    Singleton() { }
#ifdef CXX_11
    Singleton(const Singleton& rhs) = delete;
    void operator=(const Singleton& rhs) = delete;
#else /* CXX_11 */
  private:
    Singleton(const Singleton& rhs) { }
    void operator=(const Singleton& rhs) { }
#endif /* CXX_11 */
};

template <typename T>
T Singleton<T>::val = 0;

int main () {
  Base b;
  b.aStaticFunc();
  Base::aStaticFunc();
  Derived::aStaticFunc();

  std::cout << "<int> val: " << Singleton<int>::val << std::endl;
  std::cout << "<float> val: " << Singleton<float>::val << std::endl;

  Singleton<int>& singular = Singleton<int>::getInstance();
  singular.disp();

  std::cout << "<int> val: " << Singleton<int>::val << std::endl;
  std::cout << "<float> val: " << Singleton<float>::val << std::endl;

  Singleton<float>& dual = Singleton<float>::getInstance();
  dual.disp();

  std::cout << "<int> val: " << Singleton<int>::val << std::endl;
  std::cout << "<float> val: " << Singleton<float>::val << std::endl;

  b.i;
  Base::i;
  Derived::i;
  return 0;
}
