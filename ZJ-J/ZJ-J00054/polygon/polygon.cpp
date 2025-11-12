#include <bits/stdc++.h>

#define int long long

using namespace std;

const int TT = 998244353;

const int maxn = 5005;

int n, k, ans, Sum, F[maxn], a[maxn];

int f[maxn][maxn];

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

void DFS(int x, int lst, int sum)
{
	if (x == 0)
	{
		if (sum > 2 * a[lst] && k >= 3) ++ans, ans %= TT;
		if ((n - k) >= 3 && n != k * 2)
		{
			for (int i = n; i >= 1; --i)
			if (!F[i])
			{
				if ((Sum - sum) > 2 * a[i]) ++ans, ans %= TT;
				break;
			}
		}
		return;
	}
	for (int i = lst + 1; i <=n - x + 1; ++i)
		F[i] = 1, DFS(x - 1, i, sum + a[i]), F[i] = 0;
}

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	for (int i = 1; i <=n; ++i) a[i] = read(), Sum += a[i];
	sort(a + 1, a + 1 + n);
	if (n == 3)
		if (a[1] + a[2] > a[3])
			printf("1\n");
		else printf("0\n");
	if (n > 3 && n <= 20)
	{
		for (int i = n / 2 + (n % 2); i <=n; ++i)
			k = i, DFS(i, 0, 0);
	}
	f[1][1] = 1;
	for (int i = 0; i <=n; ++i) f[i][0] = 1;
	for (int i = 2; i <=n; ++i)
	for (int j = 1; j <=i; ++j)
		f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % TT;
	if (n > 20)
		for (int i = 3; i <=n; ++i) ans += f[n][i], ans %= TT;
	printf("%lld\n", ans);
	return 0;
}
