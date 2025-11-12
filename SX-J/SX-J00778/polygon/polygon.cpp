#include <bits/stdc++.h>
using namespace std;
int a[8000], len, w, ans = 0, dp[8000];
bool vis[8000];

void dfs(int step, int sum, int x) {
	if (step > len || x == len) {
		return;
	}
	if (x == len) {
		dfs(1, 0, 1);
	}
	if (vis[step] == 0 && sum + a[step] > w) {
		ans++;
	}
	vis[step] = 1;
	dfs(step + 1, sum + a[step], x + 1);
	vis[step] = 0;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 3) {
		if (n < 3) {
			cout << 0;
			return 0;
		}
		int sum = 0, maxx = -2e9;
		for (int i = 1; i <= 3; i++) {
			maxx = max(maxx, a[i]);
			sum += a[i];
		}
		if (sum > maxx * 2) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	for (w = 3; w <= n; w++) {
		for (len = 1; len <= w - 1; len++) {
			ans = 0;
			dfs(1, 0, 0);
			dp[w] = max(dp[w], dp[w] + ans);
		}
	}
	cout << dp[n];
	return 0;
}
