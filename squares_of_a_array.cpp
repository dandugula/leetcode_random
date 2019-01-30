class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
      std::for_each(A.begin(), A.end(), [](int &aNum){ aNum *= aNum; });
      std::sort(A.begin(), A.end());
      return A;
    }
};
