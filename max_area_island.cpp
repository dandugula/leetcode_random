class Solution {
private:
  inline bool isValid(std::pair<int, int>& t, int i, int j) {
    if(t.first < 0 || t.second < 0 || t.first >= i || t.second >= j) return false;
    return true;
  }

  int dfs(std::vector<std::vector<int>>& g, int i, int j) {
    int area = 0;
    std::vector<int> coOrdX = {-1, 1, 0, 0};
    std::vector<int> coOrdY = {0, 0, -1, 1};
    std::stack<std::pair<int, int>> depthStack;

    depthStack.push(std::make_pair(i, j));
    g[i][j] = -1;

    do {
      std::pair<int, int> aPair = depthStack.top();
      std::pair<int, int> temp;

      depthStack.pop();
      ++area;

      for(int z = 0; z < coOrdX.size(); ++z) {
        temp.first = aPair.first + coOrdX[z];
        temp.second = aPair.second + coOrdY[z];

        if(isValid(temp, g.size(), g[i].size())) {
          if(g[temp.first][temp.second] == 1) {

            depthStack.push(std::make_pair(temp.first, temp.second));
            g[temp.first][temp.second] = -1;
          }
        }  
      }
    }while(!depthStack.empty());

    return area;
  }

public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;

    for(int i = 0; i < grid.size(); ++i)
      for(int j = 0; j < grid[i].size(); ++j) 
        if(grid[i][j] == 1)
          maxArea = std::max(dfs(grid, i, j), maxArea);

    return maxArea;
  }
};
