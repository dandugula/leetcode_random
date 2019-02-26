class Solution {
public:
  int repeatedNTimes(vector<int>& A) {
    bool isPresent[10000];
    memset(isPresent, 0, sizeof(isPresent));
    int i, res = -1;
      
    for(i = 0; i <= A.size()/2; ++i) {
      if(isPresent[A[i]]) { res = A[i]; break; }
      isPresent[A[i]] = 1;
    }
      
    res = -1 == res ? A[i] : res;
      
    return res;
  }
};
