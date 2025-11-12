// SD-S01603

#include <bits/stdc++.h>
#define int long long

using namespace std;

inline int read () {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}

	return x * f;
}

const int N = 5e2 + 10, mod = 998244353;

int n, m, c[N], fac[N], ans;
char s[N];

signed main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	n = read(); m = read();
	
	fac[0] = 1;
	
	for (int i = 1; i <= n; ++i)
		fac[i] = fac[i - 1] * i % mod;
	
	scanf("%s", s + 1);
	
	for (int i = 1; i <= n; ++i)
		c[i] = read();
	
	bool SPEC = 1;
	
	for (int i = 1; i <= n; ++i)
		SPEC &= (s[i] == '1');
	
	if (SPEC) {
		printf("%lld\n", fac[n]);
		return 0;
	}
	
	if (m == n) {
		bool flag = 0;
		for (int i = 1; i <= n; ++i)
			flag |= (c[i] == 0),
			flag |= (s[i] == '0');
		if (flag) {
			printf("0\n");
			return 0;
		}
	}
	
	sort (c + 1, c + n + 1);
	
	for (int p = 1; p <= fac[n]; ++p) {
		int cnt = 0, cur = 0;
		for (int i = 1; i <= n; ++i) {
			if (cur >= c[i]) {
				cur ++; continue;
			}
			if (s[i] == '0') {
				cur ++; continue;
			}
			cnt ++;
			
			if (cnt >= m) {
				ans ++; ans %= mod; break;
			}
		}
		
		next_permutation(c + 1, c + n + 1);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}









