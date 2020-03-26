class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::vector<std::string> res;
        std::unordered_map<std::string, int> index_map;
        int min_index_sum = INT_MAX;

        for(int i = 0; i < list1.size(); ++i)
            index_map.insert(std::make_pair(list1[i], i));

        for(int j = 0; j < list2.size(); ++j) { 
            auto it = index_map.find(list2[j]);

            if(it != index_map.end()) { 
                int sum = it->second + j;

                if(sum < min_index_sum) {
                    res.clear();
                    res.push_back(it->first);

                    min_index_sum = sum;
                } else if (min_index_sum == sum) {

                    res.push_back(it->first);
                }
            }
        }

        return res;
    }
};

