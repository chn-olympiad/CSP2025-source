#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, B = 131;

using ll = unsigned long long;

using i64 = long long;

int n, q, sz[N];
string a[N][2];
ll h[N][2], g[N], p[N];

ll get(int l, int r)
{
	if (l > r) return 0;
	ll ans = 0;
	ans = g[r] - g[l - 1] * p[r - l + 1];
	return ans;
}

ll gg(int l, int r)
{
	if (l > r) return 0;
	return g[r] - g[l - 1];
}

int read()
{
	int x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
	return x;
}

void print(i64 x)
{
	if (x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	p[0] = 1;
	for (int i = 1; i <= 1000000; i++) p[i] = p[i - 1] * B;
	n = read(), q = read();
	for (int i = 1; i <= n; i++) {
		char c = getchar();
		while (!(c >= 'a' && c <= 'z')) c = getchar();
		while (c >= 'a' && c <= 'z') sz[i]++, h[i][0] = h[i][0] * B + c - 'a' + 1, c = getchar();
		while (!(c >= 'a' && c <= 'z')) c = getchar();
		while (c >= 'a' && c <= 'z') h[i][1] = h[i][1] * B + c - 'a' + 1, c = getchar(); 
	}
	for (int i = 1; i <= q; i++) {
		ll H = 0; string s = " ";
		char c = getchar();
		while (!(c >= 'a' && c <= 'z')) c = getchar();
		while (c >= 'a' && c <= 'z') s += c, c = getchar();
		while (!(c >= 'a' && c <= 'z')) c = getchar();
		while (c >= 'a' && c <= 'z') H = H * B + c - 'a' + 1, c = getchar();
		
		int m = s.size() - 1;
		for (int i = 1; i <= m; i++) g[i] = g[i - 1] * B + s[i] - 'a' + 1;
		i64 ans = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				int l = i, r = i + sz[j] - 1;
				if (r > m) continue;
				if (get(l, r) != h[j][0]) continue;
				ll o = (g[l - 1] * p[sz[j]] + h[j][1]) * p[m - r] + get(r + 1, m);
				if (o == H) ans++;
			}
		}
		print(ans), putchar('\n');
	}
	return 0;
}

