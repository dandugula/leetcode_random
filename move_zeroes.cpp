class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int i = 0;
    while(i< nums.size() && nums[i]) ++i;

    for(int j = i+1; j < nums.size(); ++j) 
      if(0 != nums[j]) {
        nums[i++] = nums[j];
        nums[j] = 0;
      }
  }
};
