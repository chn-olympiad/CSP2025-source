#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Lim = 5001;
const int mod = 998244353;
inline int read() {
	int x = 0,  f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
	    if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, a[5005], f[5005], g[5005], ans;
void solve(int x) {
	for(int i = 0; i <= Lim; ++i)	g[i] = 0;
	for(int i = 0; i <= Lim; ++i) {
		g[min(Lim, i + x)] += f[i];
		g[i] += f[i];
	}
	for(int i = 0; i <= Lim; ++i) {
		g[i] %= mod;
		f[i] = g[i];
	}
	return;
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; ++i) {
		a[i] = read();
	}
	sort(a + 1, a + n + 1);
	memset(f, 0, sizeof f);
	f[0] = 1;
	solve(a[1]); solve(a[2]);
	for(int i = 3; i <= n; ++i) {
		for(int j = a[i] + 1; j <= Lim; ++j) {
			ans += f[j];
		}
		ans %= mod;
		solve(a[i]);
	}
	printf("%lld", ans);
	return 0;
}
