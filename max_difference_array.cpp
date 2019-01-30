#include <iostream>
#include <vector>
#include <cassert>

int max_difference(const std::vector<int>& v) {
  int max_diff = -1;
  int max_num = v[0];
  for(int i = 1; i < v.size(); ++i) {
    if(max_num < v[i]) {
      max_diff = max_diff != -1 ? max_diff + v[i] - max_num : v[i] - max_num;
      max_num = v[i];
    }
  }
  return max_diff;
}

int main () {
  std::vector<int> case1 = {1, 2};
  std::vector<int> case2 = {2, 1};
  std::vector<int> case3 = {1, 2, 3};
  std::vector<int> case4 = {2, 10, 1, 2, 3};
  std::vector<int> case5 = {2, 10, 1, 2, 3, 22};
  std::vector<int> case6 = {-2, -10, -1, -2, -3, -22};
  std::vector<int> case7 = {10, 5, 11};

  std::cout << "Running Tests..." << std::endl;
  assert (max_difference(case1) == 1);
  assert (max_difference(case2) == -1);
  assert (max_difference(case3) == 2);
  assert (max_difference(case4) == 8);
  assert (max_difference(case5) == 20);
  assert (max_difference(case7) == 6);
  std::cout << "All Tests passed!!" << std::endl;

  return 0;
}
