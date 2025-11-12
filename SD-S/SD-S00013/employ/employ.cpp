#include <iostream>
#include <algorithm>
#define int long long
const int N = 505, mod = 998244353;
int n, m;
int ans;
int c[N];
int p[N];
int pos[N], tot;
int ch[N], idx;
bool vis[N];
std::string s;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

inline void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 10) write(x / 10);
	putchar(x % 10 + '0');
}

signed main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	std::cin >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) 
		c[i] = read(), p[i] = i;
	if (n <= 11) {
		do {
			int cnt = 0, sum = 0;
			for (int i = 1; i <= n; i++) {
				if (cnt >= c[p[i]]) {
					cnt++;
					continue;
				} 
				if (s[i] == '0') cnt++;
				else sum++;
			} 
			ans += (sum >= m);
			if (ans >= mod) ans %= mod;
		} while (std::next_permutation(p + 1, p + 1 + n));
	} else if (m == n) {
		ans = 1;
		for (int i = 1; i <= n; i++) 
			ans = ans * i % mod;
		for (int i = 1; i <= n; i++) 
			if (s[i] == '0' || c[i] == 0) ans = 0;
	} 
	write(ans);
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}

