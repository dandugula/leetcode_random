class Solution {
public:
	int singleNumber(vector<int>& nums) {
		std::set<int> solo;

		for (auto aNum : nums) {
			auto aElemIt = solo.find(aNum);

			if (aElemIt != solo.end())
				solo.erase(aElemIt);
			else
				solo.insert(aNum);

		}

		return *solo.begin();
	}
};