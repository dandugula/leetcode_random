class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
      std::vector<int> ret(T.size(), 0);
      for(int i = 0; i < T.size()-1; ++i) {
        int days = 0;
        for(int j = i + 1; j < T.size(); ++j) {
          ++days;
          if(T[i] < T[j]) {
            ret[i] = days;
            break;
          }
        }
      }
      return ret;
    }
};
