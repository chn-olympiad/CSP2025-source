#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 105;

int n, m, s, a[maxn];

int w, x, y;

inline int read()
{
	int ret = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	 ret = ret * 10 + ch - '0',
	ch = getchar();
	return ret * f;
}

signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = read();
	m = read();
	for (int i = 1; i <= n * m; ++i)
		a[i] = read();
	s = a[1];
	sort(a + 1, a + 1 + n * m);
	for (int i = n * m; i >= 1; --i)
		if (a[i] == s) w = n * m - i + 1;
	if (w % n == 0) x = w / n;
	else x = w / n + 1;
	if (x % 2 == 1) if (w % n == 0) y = n; else y = w % n;
	else if (w % n == 0) y = 1; else y = n - (w % n) + 1;
	printf("%lld %lld\n", x, y);
	return 0;
}
