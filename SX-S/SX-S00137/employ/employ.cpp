#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 505, M = 505, P = 998244353;
ll b, n, m, c[N], ans, f[N], seq[N];
char s[N];

ll read() {
	ll s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}

void write(ll x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x <= 9)
		putchar(x + '0');
	else
		write(x / 10), putchar(x % 10 + '0');
	return ;
}

void dfs(ll x) {
	if (x >= n + 1) {
		ll cnt = 0, num = 0;
		for (ll i = 1; i <= n; i++) {
			if (c[seq[i]] <= cnt)
				cnt++;
			else {
				if (s[i] == '1')
					num++;
				else
					cnt++;
			}
		}
		if (num >= m)
			ans++;
	}
	for (ll i = 1; i <= n; i++) {
		if (f[i] == 1)
			continue;
		f[i] = 1;
		seq[x] = i;
		dfs(x + 1);
		f[i] = 0;
	}
	return ;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read();
	m = read();
	cin >> (s + 1);
	for (ll i = 1; i <= n; i++)
		c[i] = read();
	if (n <= 10)
		dfs(1);
	write(ans % P);
	return 0;
}