#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e5 + 100;
int n, ans;
vector<int> f[3];
inline void Adj(int o) {
	sort(f[o].begin(), f[o].end());
	int ned = f[o].size() - n / 2;
	for(int i = 0; i < ned; ++i) ans -= f[o][i];
}
inline void solve() {
	f[0].clear(), f[1].clear(), f[2].clear();
	n = read(), ans = 0;
	for(int i = 1; i <= n; ++i) {
		int a = read(), b = read(), c = read();
		int mx = max({a, b, c});
		ans += mx;
		if(a == mx) f[0].push_back(a - max(b, c));
		else if(b == mx) f[1].push_back(b - max(a, c));
		else f[2].push_back(c - max(a, b));
	}
	if(f[0].size() > n / 2) Adj(0);
	if(f[1].size() > n / 2) Adj(1);
	if(f[2].size() > n / 2) Adj(2);
	cout << ans << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while(T--) solve();
	return 0;
}