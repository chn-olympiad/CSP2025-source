#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, k, a[N], sum[N], f[N][2], g[1 << 21];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		f[i][0] = max(f[i - 1][0], f[i - 1][1]);
		g[sum[i - 1]^k] = max(g[sum[i - 1] ^ k], f[i][0] + 1);
		f[i][1] = g[sum[i]];
	}
	cout << max(f[n][0], f[n][1]);
	return 0;
}
