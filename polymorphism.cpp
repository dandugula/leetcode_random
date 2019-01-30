#include <iostream>
int foo() {
  std::cout << "1" << std::endl;
  return 0;
}
void foo(int i) {
  std::cout << "2" << std::endl;
  i = i + 1;
}
int foo(int j) {
  std::cout << "3" << std::endl;
  return j + 1;
}
int main() {
  foo();
  int k = foo(10);
  std::cout << k << std::endl;
  foo(100);
}
