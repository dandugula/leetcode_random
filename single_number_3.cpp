class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        std::vector<int> ret = {0, 0};
        int diff = std::accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

        diff &= -diff;

        for(int aNum : nums) {
            if(aNum & diff)
                ret[0] ^= aNum;
            else
                ret[1] ^= aNum;
        }

        return ret;
    }
};
