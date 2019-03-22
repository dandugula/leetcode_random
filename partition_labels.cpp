class Solution {
public:
    vector<int> partitionLabels(string S) {
        std::vector<int> last(26, 0);
        std::vector<int> res;

        for (int i = 0; i < S.size(); ++i)
            last[S[i] - 'a'] = i;

        for (int i = 0; i < S.size(); ++i) {
            std::string temp(1, S[i]);
            int lastIdx = last[S[i] - 'a'];

            for (int j = i + 1; j <= lastIdx; ++j) {
                if (last[S[j] - 'a'] <= lastIdx)
                    temp += S[j];
                else {
                    lastIdx = last[S[j] - 'a'];
                    temp += S[j];
                }
            }

            i = lastIdx;
            res.push_back(temp.size());
        }
        return res;
    }
};