class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::vector<std::string> res;
        int min_index_sum = INT_MAX;

        for(int i = 0; i < list1.size(); ++i) 
            for(int j = 0; j < list2.size(); ++j) 
                if(list1[i] == list2[j] && min_index_sum >= i + j) {
                    res.push_back(list1[i]);
                    min_index_sum = i + j;
                }

        return res;
    }
};
