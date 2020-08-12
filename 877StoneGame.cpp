class gamePair {
public:
	int first;
	int second;
	gamePair(int fir, int sec) {
		this->first = fir;
		this->second = sec;
	}
};
class Solution {
public:
	bool stoneGame(vector<int>& piles) {
		if (piles.size() == 1) return true;
		vector<vector<gamePair>> dp(piles.size(), vector<gamePair>(piles.size()));
		for (int i = 0; i < piles.size() - 1; i++) {
			dp[i][i] = new gamePair(piles[i], 0);
			dp[i][i + 1] = new gamePair(max(piles[i], piles[i + 1]), min(piles[i], piles[i + 1]));
		}
		dp[piles.size() - 1][piles.size() - 1] = new gamePair(piles[piles.size() - 1], 0);
		for (int l = 2; l <= piles.size(); l++) {
			//dp[i][j].first=max(dp[i+1][j].second+piles[i],dp[i][j-1].second+piles[i])
			//dp[i][j].second=dp[i+1][j].first(when choose left) or dp[i][j-1].first(when choose right)
			for (int i = 0; i < piles.size(); i++) {
				int j = j + i - 1;
				if (j >= n) continue;
				int left = dp[i + 1][j].second + piles[i];
				int right = dp[i][j - 1].second + piles[j];
				if (left > right) {
					dp[i][j].first = left;
					dp[i][j].second = dp[i + 1][j].first;
				}
				else {
					dp[i][j].first = right;
					dp[i][j].second = dp[i][j - 1].first;
				}
			}
		}
		return dp[0][piles.size() - 1].first > dp[0][piles.size() - 1].second;
	}
};