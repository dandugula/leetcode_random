#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
class Solution {
private:
  std::vector<int> alpha_row;
public:
  Solution():alpha_row(26){
    //First row alphabets.
    alpha_row['e'-'a'] = 0;
    alpha_row['i'-'a'] = 0;
    alpha_row['o'-'a'] = 0;
    alpha_row['p'-'a'] = 0;
    alpha_row['q'-'a'] = 0;
    alpha_row['r'-'a'] = 0;
    alpha_row['t'-'a'] = 0;
    alpha_row['u'-'a'] = 0;
    alpha_row['w'-'a'] = 0;
    alpha_row['y'-'a'] = 0;
    //Second row alphabets.
    alpha_row['a'-'a'] = 1;
    alpha_row['d'-'a'] = 1;
    alpha_row['f'-'a'] = 1;
    alpha_row['g'-'a'] = 1;
    alpha_row['h'-'a'] = 1;
    alpha_row['j'-'a'] = 1;
    alpha_row['k'-'a'] = 1;
    alpha_row['l'-'a'] = 1;
    alpha_row['s'-'a'] = 1;
    //Third row alphabets.
    alpha_row['b'-'a'] = 2;
    alpha_row['c'-'a'] = 2;
    alpha_row['m'-'a'] = 2;
    alpha_row['n'-'a'] = 2;
    alpha_row['v'-'a'] = 2;
    alpha_row['x'-'a'] = 2;
    alpha_row['z'-'a'] = 2;
  }
  std::vector<std::string> findWords(std::vector<std::string>& words) {
    std::vector<std::string> res;
    for(auto aWord : words) {
      int r = alpha_row[tolower(*aWord.begin()) - 'a'];
      bool include = true;
      std::for_each(std::next(aWord.begin()), aWord.end(), [&](auto ch) {
                   if(r != alpha_row[tolower(ch) - 'a']) {include = false; return;}
                   });
      if(include) res.push_back(aWord);
    } 
    return res;
  }
};
int main () {
  std::vector<std::string> words = {"Hello", "Alaska", "Dad", "Peace"};
  Solution sol;
  std::vector<std::string> ret = sol.findWords(words);
  for(auto aWord : ret) {
    std::cout << aWord << std::endl;
  }
  return 0;
}
