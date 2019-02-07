class NumArray {
private:
    std::vector<int> range_sums;        
public:
    NumArray(vector<int> nums){
      int sum = 0;
      std::transform(nums.begin(), nums.end(), std::back_inserter(range_sums),
                    [&sum](auto aNum){return sum += aNum;});
    }
    
    int sumRange(int i, int j) {
      return 0 == i ? range_sums[j] :
             range_sums[j] - range_sums[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
