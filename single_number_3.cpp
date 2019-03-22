class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        int unique_num1 = 0;
        int unique_num2 = 0;

        for(int aNum : nums) 
            diff ^= aNum;

        diff &= -diff;

        for(int aNum : nums) 
            if(aNum & diff) unique_num1 ^= aNum;
            else unique_num2 ^= aNum;

        return std::vector<int>({unique_num1, unique_num2});
    }
};
