#include <iostream>
#include <string>
#include <stack>
#include <vector>
std::stack<std::pair<int, int>> neighbors;

inline bool isValid(int i, int j, int s){
  if(i < 0 || j < 0  || i >= s || j >= s) return false;
  return true;
}

bool dfs(const std::vector<std::string>& m, const std::string& s){
  int z = 1;
  while(!neighbors.empty()){
    std::pair<int, int> ch = neighbors.top();
    neighbors.pop();
    if(z == s.size()) return true;
    for(int i = -1; i <= 1; ++i){
      for(int j = -1; j <= 1; ++j) {
        if(0 == i && 0 == j) continue;
        if(isValid(ch.first + i, ch.second + j, m.size())) {
          //if(z == s.size()) goto ret;
          if(s[z] == m[ch.first + i][ch.second + j]) {
            neighbors.push(std::pair<int, int>(ch.first + i, ch.second + j));
            //std::cout << "i: " << ch.first + i << ", j: " << ch.second + j << std::endl;
            ++z;
          }
        }
      }
    }
  }
  return false;
}

bool isPresent(const std::vector<std::string>& m, const std::string& s) {
  int z = 0;
  for(int i = 0; i < m.size(); ++i) {
    for(int j = 0; j < m[i].size(); ++j) {
      if(m[i][j] == s[0]){
        //std::cout << "i: " << i << ", j: " << j << std::endl;
        neighbors.push(std::pair<int, int>(i, j));
        if(dfs(m, s) == true) return true;
        else 
          while(!neighbors.empty())
            neighbors.pop();
      }
    }
  }
 return false;
}

int main () {
  std::vector<std::string> matrix = { "xasr",
                                      "qata",
                                      "ulmh",
                                      "onpz"};
  std::string toSearch = "alpha";
  std::cout << "is string present: " << std::boolalpha << isPresent(matrix, toSearch) << std::endl;
  return 0;
}
