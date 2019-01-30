#include <iostream>
void recursive_print(int n) {
  if(0 == n) {
    std::cout << n << std::endl;
    return;
  }
  std::cout << -1*n << std::endl;
  recursive_print(n-1);
  std::cout << n << std::endl;
  return;
}
int main () {
  recursive_print(10);
  return 0;
}
