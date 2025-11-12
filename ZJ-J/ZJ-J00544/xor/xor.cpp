#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10, V = (1 << 20) + 10;

int n, k, a[N], lst[N], dp[N], pos[V];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	memset(pos, -1, sizeof(pos));
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] = (a[i] ^ a[i - 1]);
	for (int i = 0; i <= n; i++) {
		if (pos[a[i] ^ k] != -1) lst[i] = pos[a[i] ^ k] + 1;
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (lst[i]) dp[i] = dp[lst[i] - 1] + 1;
		dp[i] = max(dp[i - 1], dp[i]);
	}
    cout << dp[n];
	
	return 0;
}
