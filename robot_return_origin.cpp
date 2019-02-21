class Solution {
public:
  bool judgeCircle(string moves) {
    int one_dir = 0;
    int two_dir = 0;

    if(moves.size() % 2 != 0) return false;

    for(auto ch : moves) {
      switch(ch) {
        case 'U':
          one_dir += 1;
          break;
        case 'D':
          one_dir -= 1;
          break;
        case 'L':
          two_dir += 1;
          break;
        case 'R':
          two_dir -= 1;
          break;
      }
    }

    if(!one_dir && !two_dir)
      return true;

    return false;  
  }
};

