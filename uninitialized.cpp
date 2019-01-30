#include <iostream>
#include <vector>
int global;
int garr[10];
void foo() {
  std::vector<std::vector<int> >v(10);
  std::cout << "*" << std::endl;
  v[0].push_back(0);
  std::cout << "**" << std::endl;
  return;
}
int main() {
  int local;
  int arr[10];
  std::cout << "global: " << global;
  std::cout << ", local: " << local << std::endl;
  std::cout << "arr[9]: " << arr[9] << std::endl;
  std::cout << "garr[9]: " << garr[9] << std::endl;
  foo();
  return 0;
}
