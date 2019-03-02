class Solution {
private:
  int rc(int d, const std::set<int>& daySet, const std::vector<int>& c, std::vector<int>& dayCost) {
    if(d > 365) return 0;
    if(dayCost[d] != -1)
      return dayCost[d];

    int ans;
    if(daySet.find(d) != daySet.end()) {
      ans = std::min(rc(d+1, daySet, c, dayCost) + c[0], rc(d+7, daySet, c, dayCost) + c[1]);
      ans = std::min(ans, rc(d+30, daySet, c, dayCost) + c[2]);
    } else {
      ans = rc(d+1, daySet, c, dayCost);
    }
    dayCost[d] = ans;
    return ans;
  }
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    std::set<int> daySet(days.begin(), days.end());
    std::vector<int> dayCost(366, -1);
    return rc(1, daySet, costs, dayCost);
  }
};
