class Solution {
public:
  string reverseWords(string s) {
    std::istringstream stream(s);
    std::string aWord;
    std::string ret = "";

    while(stream >> aWord) {
      std::reverse(std::begin(aWord), std::end(aWord));
      ret += aWord + " ";
    }

    ret.erase(ret.end() - 1);
    return ret;
  }
};
