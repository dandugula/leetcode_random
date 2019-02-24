class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_ones = 0;

    for(int c = 0; c < nums.size(); ++c) {
      int t = 0;
      while(c < nums.size() && nums[c]) t += nums[c++]; 

      max_ones = std::max(max_ones, t);
    }

    return max_ones;
  }
};
