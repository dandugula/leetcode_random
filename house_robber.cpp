class Solution {
public:
    int rob(vector<int>& nums) {
      if(nums.size() <= 0) return 0;

      std::vector<int> maxLoot(nums.size(), 0);
      maxLoot[0] = nums[0];

      if(nums.size() > 1)
        maxLoot[1] = max(nums[1], nums[0]);

      for(int i = 2; i < nums.size(); ++i) 
        maxLoot[i] =  max(nums[i] + maxLoot[i-2], maxLoot[i-1]);

      return maxLoot[nums.size()-1];
      
    }
};
