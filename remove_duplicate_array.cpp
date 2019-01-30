class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      auto head = nums.begin();
      while(head != nums.end()) {
        auto next = head + 1;
        while(next != nums.end() && *next == *head) {
          next = nums.erase(next);
        }
        head = next;
      }
      return nums.size();
    }
    int removeDuplicates(vector<int>& nums) {
      int size = 0;

      for(int i = 1; i < nums.size(); ++i) 
        if(nums[i] != nums[i-1]) 
          nums[size++] = nums[i-1];

      return size;
    }

};
