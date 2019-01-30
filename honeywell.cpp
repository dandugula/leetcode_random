#include <iostream>
#include <cmath>
int main ()
{
  unsigned long x, y, wall;
  int n, jumps = 0;

  std::cin >> x;
  std::cin >> y;
  std::cin >> n;

  for(int i = 0; i < n; ++i) {
    std::cin >> wall;
    jumps += ceil(double(wall + y - x)/x) + 1;
  } 
  std::cout << jumps;
  return 0;
}
