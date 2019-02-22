class RecentCounter {
private:
  std::queue<int> milliSec;
  const int delta;

public:
  RecentCounter():delta(3000) {
  }
  
  int ping(int t) {
    while(!milliSec.empty()) { 
      if(delta >= t - milliSec.front()) break;

      milliSec.pop();
    }

    milliSec.push(t);
    return milliSec.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
