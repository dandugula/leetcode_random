class Solution {
public:
    int numJewelsInStones(string J, string S) {
      std::vector<std::vector<bool>> jewels(2);
      int count = 0;
      jewels[0].resize(26);
      jewels[1].resize(26);

      for(auto ch : J) {
        if(ch >= 'a' && ch <= 'z')
          jewels[0][ch - 'a'] = true;
        else
          jewels[1][ch - 'A'] = true;
      }

      for(auto ch : S) {
        if(ch >= 'a' && ch <= 'z')
          count += jewels[0][ch - 'a'] ? 1 : 0;
        else
          count += jewels[1][ch - 'A'] ? 1 : 0;
      }

      return count;
    }
};
