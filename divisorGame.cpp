class Solution {
public:
    bool divisorGame(int N) {
      bool result[N+1];
      result[0] = result[1] = false;
      if( N > 1)
        result[2] = true;
      if( N > 2)
        result[3] = false;
      for(int i = 4; i <= N; ++i) {
        result[i] = false;
        for(int j = 1; j < i; ++j) {
          if(i % j == 0 && result[j] == true){
            result[i] = true;
            break;
          }
        }
      }
      return result[N]; 
    }
};
