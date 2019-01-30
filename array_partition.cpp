class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
      std::sort(nums.begin(), nums.end());
      int sum = 0;
      int i = 0;
      int j = 1;
      for(;j < nums.size(): j+=2, i+=2) {
        sum += min(nums[i], nums[j]);
      }
      return sum;
    }
};
