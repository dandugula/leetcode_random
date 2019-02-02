class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
      std::vector<string> res;
      std::for_each(words.begin(), words.end(), 
      [&res, &pattern](auto& aWord) {
        std::vector<int> letterMap(26, -1);
        std::vector<bool> letterRec(26, false);
        int i = 0;
        bool match = true;
        std::for_each(pattern.begin(), pattern.end(), 
        [&aWord, &letterMap, &letterRec, &i, &match] (auto& aLetter) {
            if(letterMap.at(aLetter - 'a') == -1 && !letterRec.at(aWord[i] - 'a')) {
                letterMap[aLetter - 'a'] = aWord[i];
                letterRec[aWord[i] - 'a'] = true;

            }else if(letterMap.at(aLetter - 'a') != aWord[i]) {
              match = false;
              return;
            }

            ++i;
        });
        if(match)
          res.push_back(aWord);
      });
      return res;
    }
};
