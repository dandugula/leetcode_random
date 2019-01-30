class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      if(nums.size() <= 0) return 0;

      std::vector<int> maxSubArraySum(nums.size(), 0);
      maxSubArraySum[0] = nums[0];
      int max = 0; 
      
      for(int i = 1; i < nums.size(); ++i) 
          maxSubArraySum[i] = nums[i] + maxSubArraySum[i-1] > 0 ? maxSubArray[i-1] : 0;
      
      return maxSubArraySum[nums.size() - 1];

    }
};
