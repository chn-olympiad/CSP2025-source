#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin (), (x).end ()
#define vec vector
#define MAXN 19
#define mod 998244353
template <typename T> inline void read (T &x) {
	x = 0; T f = 1; char ch = getchar ();
	while (!isdigit (ch)) { if (ch == '-') f = -1; ch = getchar (); }
	while (isdigit (ch)) { x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar (); }
	x *= f;
}

template <typename T, typename ...Arp> inline void read (T &x, Arp &...arp) {
	read (x), read (arp...);
}

int n, m;
int c[MAXN];
ll dp[MAXN][1 << MAXN]; // dp[i][j] ：选择的状态如 j 的方案数，有 i 个人人放弃或失败。  
ll ans;
char s[MAXN];

int ppc (int x) {
	int cnt = 0;
	while (x) {
		x -= (x & -x);
		++cnt;
	}	
	
	return cnt;
}

signed main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	read (n, m);
	
	scanf ("%s", s + 1);
	for (int i = 1; i <= n; ++i) 
		read (c[i]);
	
	dp[0][0] = 1;
	
	for (int i = 1; i < (1 << n); ++i) { // 当前的排列选择状态 
		for (int j = 0; j < n; ++j) { // 当前是 j 
			if ((i >> j) & 1) {
				for (int k = 0; k <= ppc (i); ++k) {
					if (s[ppc (i)] == '1') {
						if (!k)
							dp[k][i] = 0;
						else
							(dp[k][i] += dp[k - 1][i ^ (1 << j)]) %= mod; 
					} else if (k - 1 >= c[j + 1]) {
						if (!k)
							dp[k][i] = 0;
						else
							(dp[k][i] += dp[k - 1][i ^ (1 << j)]) %= mod; 
					} else 
						(dp[k][i] += dp[k][i ^ (1 << j)]) %= mod;
				}
			}
		}
	}
	
	ll ans = 0;
	for (int i = 0; i <= n - m + 1; ++i)
		(ans += dp[i][(1 << n) - 1]) %= mod;
		
	printf ("%lld\n", ans);
	return 0;
}

/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/