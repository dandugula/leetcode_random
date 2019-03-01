class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());

		bool res = false;
		auto aNumIt = nums.begin();

		std::vector<int>::iterator nextNumIt;

		if(nums.end() != aNumIt)
			nextNumIt = std::next(nums.begin());

		while(nums.end() != nextNumIt) {
			if(*aNumIt == *nextNumIt) {
				res = true;
				break;
			}
			aNumIt = nextNumIt;
			++nextNumIt;
		}	

		return res;
	}
};
