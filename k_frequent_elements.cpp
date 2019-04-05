class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> freq_map;
        std::vector<std::pair<int, int>> sorted;
        std::vector<int> res;

        std::for_each(nums.begin(), nums.end(), [&freq_map](auto i){
                if(freq_map.find(i) == freq_map.end())
                    freq_map.insert(std::make_pair(i, 1));
                else
                    freq_map[i]++;
        });

        std::copy(freq_map.begin(), freq_map.end(), std::back_inserter(sorted));

        std::sort(sorted.begin(), sorted.end(), [](auto l, auto r){
                if(l.second == r.second)
                    return l.first < r.first;
                return l.second > r.second;    
        });
        
        for(int i = 0; i < k; ++i)
            res.push_back(sorted[i].first);
        
        return res;
    }
};
