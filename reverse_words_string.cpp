#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
class Solution {
public:
    void reverseWords(std::string &s) {
      std::istringstream stream(s);
      std::string aWord;
      std::vector<std::string> res;
      while(stream >> aWord) {
        res.push_back(aWord);
      }

      if(res.size() == 0) {
        s = "";
      } else {
        s = *res.rbegin();
        std::for_each(std::next(res.rbegin()), res.rend(), [&s](auto w) {s += " "+w;});
      }

      return;
    }
};

int main() {
  Solution sol;
  std::string test1 = "the sky is blue";
  std::string test2 = "  the jackel is red";
  std::string test3 = "the sky is blue and dark    ";
  std::string test4 = "the";
  std::string test5 = "";
  sol.reverseWords(test1);
  std::cout << test1 << std::endl;
  sol.reverseWords(test2);
  std::cout << test2 << std::endl;
  sol.reverseWords(test3);
  std::cout << test3 << std::endl;
  sol.reverseWords(test4);
  std::cout << test4 << std::endl;
  sol.reverseWords(test5);
  std::cout << test5 << std::endl;
  return 0;
}

