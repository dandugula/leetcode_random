class Solution {
private:
  enum rToInt {
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000    
  };
public:
    string intToRoman(int num) {
      std::vector<int> segments;
      std::string roman;
      for(int i = 1000; i >= 1; i /= 10) {
        segments.push_back((num / i) * i);
        num %= i;
      }
      for(auto aSegment : segments) {
        if(0 == aSegment) continue;
        if(900 == aSegment) {
          roman += "CM";
        } else if (500 == aSegment) {
          roman += "CD";
        } else if (90 == aSegment) {
          roman += "XC";
        } else if (40 == aSegment) {
          roman += "XL";
        } else if (9 == aSegment) {
          roman += "IX";
        } else if (4 == aSegment) {
          roman += "IV";
        } else {
          roman += 
        } 
      }
    }
};
