#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, num[N], f[N], las;
int dp[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios:: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		f[i] = num[i] ^ f[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = las; j < i; j++)
			if ((f[i] ^ f[j]) == k) {
				cnt = 1, las = i;
				break;
			}
		dp[i] = dp[i - 1] + cnt;
	}
	cout << dp[n];
	return 0;
}

