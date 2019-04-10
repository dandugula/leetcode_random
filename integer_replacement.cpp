class Solution {
private:
    unsigned long iR2(unsigned long n) {
        return 1 == n ? 0 : 0 == n % 2 ? iR2(n/2) + 1 :
              std::min(iR2(n-1), iR2(n+1)) + 1;
    }    
public:
    int integerReplacement(int n) {
        return iR2(n);
    }
};
