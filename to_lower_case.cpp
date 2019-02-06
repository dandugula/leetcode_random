class Solution {
public:
    string toLowerCase(string str) {
      std::transform(str.begin(), str.end(), str.begin(), [](auto ch){return std::tolower(ch);});
      return str;
    }
};

