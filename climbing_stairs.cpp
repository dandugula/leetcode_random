class Solution {
public:
    int climbStairs(int n) {
      if(n < 2) return n;

      std::vector<int> toReach(n + 1, 0);
      toReach[1] = 1;
      toReach[2] = 2;

      for(int i = 3; i <= n; ++i)
        toReach[i] = toReach[i-2] + toReach[i-1];

      return toReach[n];
    }
};
