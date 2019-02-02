class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
      std::vector<vector<int>> ret(A[0].size());
      std::for_each(ret.begin(), ret.end(), [&A](std::vector<int>& v) { v.resize(A.size()); });

      for(int i = 0; i < ret.size(); ++i) 
        for(int j = 0; j < ret[i].size(); ++j)
          ret[i][j] = A[j][i];

      return ret;
    }
};
