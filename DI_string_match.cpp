class Solution {
public:
    vector<int> diStringMatch(string S) {
        int inc = 0;
        int dec = S.length();
        std::vector<int> res;

        std::for_each(S.begin(), S.end(), [&] (auto ch) {
             ch == 'I' ? res.push_back(inc++) : res.push_back(dec--); 
        });

        res.push_back(inc);

        return res;
    }
};
