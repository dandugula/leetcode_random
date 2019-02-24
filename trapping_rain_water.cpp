//Time limit exceed, although the alog works!
class Solution {
public:
  int trap(vector<int>& height) {
    std::stack<int> heightAt;
    int res = 0;
    int i = 0;
    while(i < height.size()) {
      while(!heightAt.empty() && height[i] > height[heightAt.top()]) {
        int t = heightAt.top();
        heightAt.pop();
        if(heightAt.empty())
          break;
        int d = i - heightAt.top() - 1;
        int bounded_h = min(height[i], height[heightAt.top()]) - height[t];
        res += bounded_h * d;
      }
      heightAt.push(i++);
    }
    return res;
  }
};
