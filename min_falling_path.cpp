class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& A) {
		std::vector<std::vector<int>> dp(A.size());
		const int sentinal = 101;

		dp[0].push_back(sentinal);
		std::copy(A[0].begin(), A[0].end(), std::back_inserter(dp[0]));
		dp[0].push_back(sentinal);

		for (int i = 1; i < A.size(); ++i) {
			dp[i].push_back(sentinal);

			for (int j = 1; j <= A[i].size(); ++j)
				dp[i].push_back(A[i][j - 1] + std::min(dp[i - 1][j - 1],
					std::min(dp[i - 1][j], dp[i - 1][j + 1])));

			dp[i].push_back(sentinal);
		}

		return *std::min_element(std::begin(*dp.rbegin()), std::end(*dp.rbegin()));
	}
};