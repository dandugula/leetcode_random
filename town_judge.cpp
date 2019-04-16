class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        std::vector<std::vector<bool>> trust_matrix(N, std::vector<bool>(N, false));
        std::vector<bool> zero_rows (N, true);

        int zero_row = -1;
        int cur_row;

        for(auto aPair : trust) { 
            trust_matrix[aPair[0]-1][aPair[1]-1] = true;
            zero_rows[aPair[0]-1] = false;
        }
        
        for(int i = 0; i < zero_rows.size(); ++i) {
            if( zero_rows[i] && -1 == zero_row) {
                zero_row = i;
            } else if( zero_rows[i] && -1 != zero_row) {
                zero_row = -1;
                break;
            }
        }
    
        for(cur_row = 0; -1 != zero_row && cur_row < trust_matrix.size(); 
                ++cur_row) {

            if(zero_row == cur_row) continue;

            if(!trust_matrix[cur_row][zero_row]) break;
        }

        return -1 == zero_row || cur_row != trust_matrix.size()
               ? -1 : zero_row + 1;
    }
};
