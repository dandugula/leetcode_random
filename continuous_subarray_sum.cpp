class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      if(nums.size() < 2) return false;
      if(nums.size() == 2) {
        return (nums[0]+nums[1]) % k == 0 ? true : false;
      }
      int i = 2;
      for(; i < nums.size(); ++i) {
        int s = 0;
        for(int j = 0; j < i; ++j) {
          s += nums[j];
        }
        s += nums[i];
        if(s % k == 0) {
          std::cout << "sum: " << s << std::endl;
          return true;
        }
      }
      return false;
    }
};
