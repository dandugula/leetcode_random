#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

int max_difference(const std::vector<int>& v) {
  int max_diff = -1;
  int min_num = *v.begin();
  std::for_each(v.begin() + 1, v.end(), [&max_diff, &min_num](auto& aNum) {
                if(aNum < min_num)
                  min_num = aNum;
                else
                  max_diff = std::max(max_diff, aNum - min_num);
               });
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
  std::vector<int> case8 = {2, 10, 5, 2, 3, 22};

  std::cout << "Running Tests..." << std::endl;
  assert (max_difference(case1) == 1);
  assert (max_difference(case2) == -1);
  assert (max_difference(case3) == 2);
  assert (max_difference(case4) == 8);
  assert (max_difference(case5) == 21);
  assert (max_difference(case6) == 9);
  assert (max_difference(case7) == 6);
  assert (max_difference(case8) == 20);
  std::cout << "All Tests passed!!" << std::endl;

  return 0;
}
