#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
std::string longest_common_substring(const std::string& a, const std::string& b) {

  std::vector<std::vector<int>> lcs(b.size() + 1, std::vector<int>(a.size() + 1, 0));  
  std::pair<int, int> index;
  std::string res = "";
  int max_len = 0;

  for(int i = 1; i <= b.size(); ++i)
    for(int j = 1; j <= a.size(); ++j)
      if(b[i-1] == a[j-1]) {
        lcs[i][j] = lcs[i-1][j-1] + 1;
        if(max_len < lcs[i][j]) {
          max_len = lcs[i][j];
          index = std::make_pair(i, j);
        }
      }

  while(index.first > 0 && index.second > 0 && 
        lcs[index.first][index.second] != 0) {
    res += b[index.first-1];
    index.first--;
    index.second--;
  }

  std::reverse(res.begin(), res.end());
  return res;
}

int main () {
  std::string s1 = "deltapath";
  std::string s2 = "aspathand";
  std::string s3 = "d";
  std::string s4 = "d";
  std::cout << longest_common_substring(s1, s2) << std::endl;
  std::cout << longest_common_substring(s3, s4) << std::endl;
  std::cout << longest_common_substring("", "") << std::endl;
  return 0;
}
