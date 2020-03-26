class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    std::vector<int> res;
    int sum = 0;
    int n = A.size();

    for(int i = 0; i < n; ++i)
        sum += A[i] & 1 ? 0 : A[i];

    n = queries.size();

    for(int i = 0; i < n; ++i) {

        sum -= A[queries[i][1]] & 1 ? 0 : A[queries[i][1]];
        A[queries[i][1]] += queries[i][0];
        sum += A[queries[i][1]] & 1 ? 0 : A[queries[i][1]];

        res.push_back(sum);
    }

    return res;
  }
};
