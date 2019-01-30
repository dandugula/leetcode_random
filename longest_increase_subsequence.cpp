class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      if(nums.size()  == 0) return 0;
      std::vector<int> dp(nums.size(), 1);
      dp[0] = 1;
      int ret = 1;
      for(int i = 1; i < nums.size(); ++i) {
        int m = 0;
        for(int j = 0; j < i; ++j) {
          if(nums[j] < nums[i])
            dp[i] = max(dp[j] + 1, dp[i]);
        }
        ret = max(dp[i], ret);
      }
      return ret; 
    }
};
