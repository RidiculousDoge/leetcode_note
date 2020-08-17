#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool winnerSquareGame(int n) {
	//dp[i][0]表示有i+1个石子的情况下,先手的胜负关系
	//dp[i][1]......
	//dp[i][0]=!(dp[i-k][1]求积)
	if (n == 1) return true;
	if (n == 2) return false;
	vector<vector<bool>> dp(n, vector<bool>(2, false));
	dp[0][0] = true;
	dp[0][1] = false;
	for (int i = 1; i < n; i++) {
		int limit = int(sqrt(i));
		bool flag = false;
		for (int k = 1; k <= limit; k++) {
			if (!dp[i - k * k][0]) {
				dp[i][0] = true;
				dp[i][1] = false;
				flag = true;
				break;
			}
		}
		if (!flag) {
			dp[i][0] = false;
			dp[i][1] = true;
		}
	}
	return dp[n - 1][0];
}
int get_max_square(int n) {
	return int(sqrt(n))*int(sqrt(n));
}