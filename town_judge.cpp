class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        std::vector<std::vector<int>> trust_matrix(N, std::vector<int>(N, 0));
        int ret = -1;
        bool bflag = false;

        for(auto aPair : trust) {
            trust_matrix[aPair[0]-1][aPair[1]-1] = 1;
        }

        for(int i = 0; i < N; ++i) {
            bflag = false;

            for(int j = 0; j < N; ++j)
                if(trust_matrix[i][j] == 1) {
                    bflag = true;
                    break;
                }

            if(bflag) continue;
            bflag = false;

            for(int j = 0; j < N; ++j)
                if(trust_matrix[j][i] == 0 && i != j) {
                    bflag = true;
                    break;
                }

            if(bflag) continue;
            else {
                ret = i + 1;
                break;
            }

        }
                
        return ret;
    }
};
