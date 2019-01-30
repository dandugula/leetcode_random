#include <iostream>
#include <string>
#include <stack>
#include <vector>
#if 0
std::stack<std::pair<int, int>> neighbors;

inline bool isValid(int i, int j, int s, int t){
  if(i < 0 || j < 0  || i >= s || j >= t) return false;
  return true;
}

bool dfs(const std::vector<std::vector<char> >& m, const std::string& s){
  int z = 0;
  std::vector<std::vector<bool> > visited(m.size());
  for(int i = 0; i < m.size(); ++i)
    for(int j = 0; j < m[i].size(); ++j)
      visited[i].push_back(false);

  while(!neighbors.empty()) {
    std::pair<int, int> ch = neighbors.top();
    neighbors.pop();
    visited[ch.first][ch.second] = true;
    ++z;
    if(z == s.size()) return true;

    if(isValid(ch.first, ch.second + 1, m.size(), m[0].size())) {
      if(!visited[ch.first][ch.second + 1] && s[z] == m[ch.first][ch.second + 1]) {
        neighbors.push(std::pair<int, int>(ch.first, ch.second + 1));
        std::cout << ch.first << ", " << ch.second+1 << std::endl;
        //break;
      }
    }

    if(isValid(ch.first, ch.second - 1, m.size(), m[0].size())) {
      if(!visited[ch.first][ch.second - 1] && s[z] == m[ch.first][ch.second - 1]) {
        neighbors.push(std::pair<int, int>(ch.first, ch.second - 1));
        std::cout << ch.first << ", " << ch.second-1 << std::endl;
        //break;
      }
    }

    if(isValid(ch.first + 1, ch.second, m.size(), m[0].size())) {
      if(!visited[ch.first + 1][ch.second] && s[z] == m[ch.first + 1][ch.second]) {
        neighbors.push(std::pair<int, int>(ch.first + 1, ch.second));
        std::cout << ch.first + 1 << ", " << ch.second << std::endl;
        //break;
      }
    }

    if(isValid(ch.first - 1, ch.second, m.size(), m[0].size())) {
      if(!visited[ch.first - 1][ch.second] && s[z] == m[ch.first - 1][ch.second]) {
        neighbors.push(std::pair<int, int>(ch.first - 1, ch.second));
        std::cout << ch.first - 1 << ", " << ch.second << std::endl;
        //break;
      }
    }

  }
  return false;
}

bool exist(std::vector<std::vector<char> >& board, std::string word) {
      for(int i = 0; i < board.size(); ++i) {
        
        for(int j = 0; j < board[i].size(); ++j) {
          
          if(board[i][j] == word[0]) {
            neighbors.push(std::pair<int, int>(i, j));
            
            if(dfs(board, word) == true) return true;
            else
              while(!neighbors.empty())
                neighbors.pop();
          }
      }
    }
    return false;
}
#endif /* 0 */

class Solution {
  std::stack<std::pair<int, int>> neighbors;

  inline bool isValid(int i, int j, int s, int t){
    if(i < 0 || j < 0  || i >= s || j >= t) return false;
    return true;
  }

  bool dfs(const std::vector<std::vector<char> >& m, const std::string& s){
    int z = 0;
    std::vector<std::vector<bool>> visited(m.size());

    for(int i = 0; i < m.size(); ++i)
      for(int j = 0; j < m[i].size(); ++j)
        visited[i].push_back(false);
  
    while(!neighbors.empty()) {
      std::pair<int, int> ch = neighbors.top();
      neighbors.pop();
      ++z;
      if(z == s.size()) return true;
      
      visited[ch.first][ch.second] = true;

      if(isValid(ch.first, ch.second + 1, m.size(), m[0].size())) {
        if(!visited[ch.first][ch.second + 1] && s[z] == m[ch.first][ch.second + 1]) {
          neighbors.push(std::pair<int, int>(ch.first, ch.second + 1));
        }
      }

      if(isValid(ch.first, ch.second - 1, m.size(), m[0].size())) {
        if(!visited[ch.first][ch.second - 1] && s[z] == m[ch.first][ch.second - 1]) {
          neighbors.push(std::pair<int, int>(ch.first, ch.second - 1));
        }
      }

      if(isValid(ch.first + 1, ch.second, m.size(), m[0].size())) {
        if(!visited[ch.first + 1][ch.second] && s[z] == m[ch.first + 1][ch.second]) {
          neighbors.push(std::pair<int, int>(ch.first + 1, ch.second));
        }
      }

      if(isValid(ch.first - 1, ch.second, m.size(), m[0].size())) {
        if(!visited[ch.first - 1][ch.second] && s[z] == m[ch.first - 1][ch.second]) {
          neighbors.push(std::pair<int, int>(ch.first - 1, ch.second));
        }
      }

      visited[ch.first][ch.second] = false;

    }

    return false;
  }
  public:
    bool exist(std::vector<std::vector<char> >& board, std::string word) {
      for(int i = 0; i < board.size(); ++i) {
        
        for(int j = 0; j < board[i].size(); ++j) {
          
          if(board[i][j] == word[0]) {
            neighbors.push(std::pair<int, int>(i, j));
            
            if(dfs(board, word) == true) return true;
            else
              while(!neighbors.empty())
                neighbors.pop();
          }
      }
    }
    return false;
  }
};

int main () {
  /*std::vector<std::vector<char> > matrix = {
                                            {'A','B'},
                                            {'C','D'},
                                           };

  std::string toSearch = "ABCD";
  */                                          
  /*
  std::vector<std::vector<char> > matrix = {
                                            {'A','B','C','E'},
                                            {'S','F','C','S'},
                                            {'A','D','E','E'}
                                           };
 
  std::string toSearch = "SEE";
  */

  std::vector<std::vector<char> > matrix = {
                                            {'A','B','C','E'},
                                            {'S','F','E','S'},
                                            {'A','D','E','E'}
                                           };
 
  std::string toSearch = "ABCESEEEFS";
 
  Solution sol;
  std::cout << "is string present: " << std::boolalpha << sol.exist(matrix, toSearch) << std::endl;
  return 0;
}
