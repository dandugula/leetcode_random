class Solution {
public:
    vector<int> countBits(int num) {
      std::vector<int> ret(num + 1, 0);
      for(int i = 1; i <= num; ++i) {
        if(i % 2 == 0) 
          ret[i] = ret[i>>1];
        else
          ret[i] = ret[i-1] + 1;
      }
      return ret;
    }
};
