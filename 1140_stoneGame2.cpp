#include<vector>
#include<iostream>
using namespace std;

int stoneGame_2(vector<int>& piles) {
	//dp方法解答：这可太复杂了
	//1.状态定义：
	//dp[i][j][0]表示从piles[i]开始拿，M=j的情况下先手的最优值
	//dp[i][j][1]表示………………后手

	//2.状态转移方程：
	//dp[i][j][0]=max(piles[i]+...+piles[k-1]+dp[k][max(j,k-i)][1]);
	//dp[i][j][1]=dp[k][max(j,k-i)][0];
	//k表示从第i堆拿到第k-1堆，一共拿了X=k-i堆，所以k的范围是[i+1,min(n,i+2j)]

	//3.初始化条件：
	//dp[i][ceil((n-i+1)/2)][0]=piles[i]+...+piles[n-1];
	//dp[i][ceil((n-i+1)/2)][1]=0

	//4.返回值
	//return dp[0][1][0]

	if (piles.size() == 0) return 0;
	if (piles.size() == 1) return piles[0];
	if (piles.size() == 2) return piles[0] + piles[1];

	//initialize:
	int n = piles.size();
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
	for (int i = 0; i < n; i++) {
		for (int j = getLarger((n - i) / 2.0); j < n; j++) {
			for (int k = i; k < n; k++) {
				dp[i][j][0] += piles[k];
			}
			dp[i][j][1] = 0;
		}
	}

	//迭代开始：
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j < getLarger((n - i) / 2.0); j++) {
			dp[i][j][0] = piles[i] + dp[i + 1][1][1];
			dp[i][j][1] = dp[i + 1][1][0];
			for (int k = i + 1; k < min(n + 1, i + 2 * j + 1); k++) {
				//getsum
				int sum = piles[i];
				for (int t = i + 1; t < k; t++) sum += piles[t];
				if (sum + dp[k][max(j, k - i)][1] > dp[i][j][0]) {
					dp[i][j][0] = sum + dp[k][max(j, k - i)][1];
					dp[i][j][1] = dp[k][max(j, k - i)][0];
				}
			}
		}
	}
	return dp[0][1][0];
}

int getLarger(double x) {
	if (x == int(x)) return int(x);
	else return int(x) + 1;
}

int main() {
	vector<int> piles;
	int a[9] = { 2,3,44,4,33,45,100,900 };
	piles.insert(piles.begin(), a, a + 10);
	return stoneGame_2(piles);
}