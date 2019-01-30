class Solution {
private:
    bool stoneGame(vector<int>& p, int s, int e) {
      if(s - e == 1) {
        return p[s] > p[e] ? true : false;
      }

      return stoneGame(p, s + 2, e) || stoneGame(p, s + 1, e - 1) || 
             stoneGame(p, s , e - 2);
    }
public:
    bool stoneGame(vector<int>& piles) {
      return stoneGame(piles, 0, piles.size() - 1);
    }
};
