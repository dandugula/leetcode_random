#include <iostream>
#include <vector>
#include <set>
class Solution {
private:
    int removeDuplicates(vector<int>& nums) {
      auto head = nums.begin();
      while(head != nums.end()) {
        auto next = head + 1;
        while(next != nums.end() && *next == *head) {
          next = nums.erase(next);
        }
        head = next;
      }
      return nums.size();
    }
public:
  std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    std::vector<int> ret;
    std::set_intersection(nums1.begin(), nums1.end(),
                          nums2.begin(), nums2.end(),
                          std::back_inserter(ret));
    return ret;
  }
  std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    removeDuplicates(nums1);
    removeDuplicated(nums2);
    std::vector<int> intersect;

    int i = 0;
    int j = 0;
    if(nums1.size() < nums2.size())
      std::swap(nums1, nums2);
    
    while(i < nums1.size()) {
      if(j < nums2.size() && nums1[i] == nums2[j]) {
        intersect.push_back(nums1[i]);
        ++j;
      }
      ++i;
    }

    return intersect;
  }

};
template<typename T>
std::vector<T> intersection(std::vector<T>& first, std::vector<T>& second) {
    std::vector<T> intersect;
    std::vector<T>& temp = first;

    if(first.size() < second.size()) {
      first = second;
      second = temp;
    }

    int i = 0;
    int j = 0;
    while(i < first.size()) {
      if(j < second.size() && first[i] == second[j]) {
        intersect.push_back(first[i]);
        ++j;
      }
      ++i;
    }
    return intersect;
}

int main () {
#if 0
  std::vector<int> first = {1, 2, 3, 4, 6, 7};
  std::vector<int> second = {3, 7};
#endif /* 0 */
  Solution sol;
  std::vector<int> nums1 = {4, 9, 5};
  std::vector<int> nums2 = {9, 4, 9, 8, 4};
 std::vector<std::string> first = {"Apple", "Bat", "Dog"};
  std::vector<std::string> second = {"Bat", "Dog", "Elephant"};
  //std::vector<int> result = intersection<int>(first, second);
  std::vector<std::string> result = intersection<std::string>(first, second);
  std::vector<int> ret = sol.intersection(nums1, nums2);
  for(auto a : ret) {
    std::cout << a << ", ";
  }
  std::cout << std::endl;

  return 0;
}
