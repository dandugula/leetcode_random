class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      std::vector<int> toReachCost (cost.size()+1);

      toReachCost[0] = 0;
      toReachCost[1] = 0;

      for(int i = 2; i <= cost.size(); ++i)
        toReachCost[i] = min(toReachCost[i-2] + cost[i-2],
                    toReachCost[i-1] + cost[i-1]);

      return toReachCost[cost.size()];
    }
};
