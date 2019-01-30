class Solution {
public:
    string removeDuplicateLetters(string s) {
      std::sort(s.begin(), s.end());
      std::string ret = "";
      int prev = 0;

      for(int i = 1; i < s.size(); ++i)
        if(s[prev] != s[i]) {
          ret += s[prev];
          prev = i;
        }
      if(prev != s.size() - 1)
        ret += s[s.size() - 1];

      return ret;
    }
};
