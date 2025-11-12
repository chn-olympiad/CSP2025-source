#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 5, mod = 998244353;

int n, m, c[N];

int f[1 << 18][19];

char s[N];

int ct (int x) {
	int cnt = 0;
	while (x) {
		++ cnt;
		x ^= x & -x;
	}
	return cnt;
}

int dfs (int i, int j) { 
	if (i == (1 << n) - 1) return j <= n - m;
	if (f[i][j] != -1) return f[i][j];
	int ans = 0, id = ct(i);
	for (int k = 0; k < n; ++ k )
	    if (i >> k & 1 ^ 1) 
	        (ans += dfs (i | (1 << k), j + ((j >= c[k]) || (s[id] == '0')))) %= mod;
	   
	return f[i][j] = ans;
}

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s", &n, &m, s);
	for (int i = 0; i < n; ++ i ) scanf("%lld", c + i);
	if (n <= 18) {
		memset(f, -1, sizeof(f));
	    printf("%lld\n", dfs (0, 0));
	    return 0;
	}
	bool is = true;
	for (int i = 0; i < n; ++ i ) is &= (bool)c[i];
	for (int i = 0; i < n; ++ i ) is &= s[i] == '1';
	if (is) {
		int ans = 1;
		for (int i = 1; i <= n; ++ i ) (ans *= i) %= mod;
		printf("%lld\n", ans);
		return 0;
	}
	puts("0");
	return 0;
}
