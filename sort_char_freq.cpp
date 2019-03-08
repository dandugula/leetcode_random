class Solution {
public:
    string frequencySort(string s) {
        std::map<char, int> char_freq;
        std::vector<std::pair<char, int>> sorted;
        std::string res ("");

        std::for_each(s.begin(), s.end(), [&char_freq](auto ch){
            if (!char_freq.count(ch)) char_freq[ch] = 1;
            else char_freq[ch]++;
        });

        std::copy(char_freq.begin(), char_freq.end(), std::back_inserter<std::vector<std::pair<char, int>>>(sorted));

        std::sort(sorted.begin(), sorted.end(), [](auto& l, auto& r) {
            if (l.second != r.second)
                return l.second > r.second;
            return l.first < r.first;
        });

        std::for_each(sorted.begin(), sorted.end(), [&res](auto& aPair){ 
            res += std::string(aPair.second, aPair.first); 
        });

        return res;
    }
};