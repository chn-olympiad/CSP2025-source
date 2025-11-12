// T3 xor
// 3848
#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], g[500010], f[500010], dp1[500010], dp2[500010], ans;
map<int, int> mp1, mp2;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		g[i] = g[i - 1] ^ a[i];
	for (int i = 1; i <= n; i++) {
		if (g[i] != k && mp1[g[i] ^ k] == 0) dp1[i] = dp1[i - 1];
		else dp1[i] = max(dp1[i - 1], dp1[mp1[g[i] ^ k]] + 1);
		mp1[g[i]] = i;
	}
	reverse(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		f[i] = f[i - 1] ^ a[i];
	for (int i = 1; i <= n; i++) {
		if (f[i] != k && mp2[f[i] ^ k] == 0) dp2[i] = dp2[i - 1];	
		else dp2[i] = max(dp2[i - 1], dp2[mp2[f[i] ^ k]] + 1);
		mp2[f[i]] = i;
	}
	reverse(dp2 + 1, dp2 + 1 + n);
	for (int i = 1; i <= n; i++) 
		ans = max(ans, dp1[i] + dp2[i + 1]);
	cout << ans;
	return 0;
}