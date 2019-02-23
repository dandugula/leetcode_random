class Solution {
public:
  int calPoints(vector<string>& ops) {
    std::stack<int> scores;
    int res = 0;
    for(auto str : ops) {
      int s = 0;

      if(str == "C") {
        res -= scores.top();
        scores.pop();

      } else if(str == "+") {
        int t = scores.top();

        s += scores.top();
        scores.pop();

        s += scores.top();
        scores.push(t);

        res += s;
        scores.push(s);
      } else if(str == "D") {
        res += scores.top() * 2;
        scores.push(scores.top() * 2);

      } else {
        s = std::atoi(str.c_str());
        res += s;
        scores.push(s);

      }
    }
    return res;
  }
};
