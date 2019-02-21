class Solution {
public:
    bool isMonotonic(vector<int>& A) {
      int sign = 0;
      bool res = true;

      for(int i = 1; i< A.size(); ++i) { 
        int diff = A[i-1] - A[i];

        if(diff != 0 && sign == 0)
          sign = diff < 0 ? 1 : 2;

        if(diff > 0 && sign == 1 ||
           diff < 0 && sign == 2) {
          res = false;
          break;
        }
      }

      return res;
    }
};
