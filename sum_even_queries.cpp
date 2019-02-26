class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    std::vector<int> res;
    int sum = 0;

    std::for_each(A.begin(), A.end(), [&sum](auto a) {sum += a % 2 ? 0 : a;});

    std::for_each(queries.begin(), queries.end(), [&](auto aQuery){
                    sum -= A[aQuery[1]] % 2 ? 0 : A[aQuery[1]];
                    A[aQuery[1]] += aQuery[0];
                    sum += A[aQuery[1]] % 2 ? 0 : A[aQuery[1]];
                    res.push_back(sum);
                  });

    return res;
  }
};
