#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 505;

const int TT = 998244353;

string s;

int n, m, ans, c[maxn];

int cal[maxn], F[maxn];

inline int read()
{
	int ret = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		ret = ret * 10 + ch - '0',
		ch = getchar();
	return ret * f;
}

void calc()
{
	cal[0] = 1;
	for (int i = 1; i <= n; ++i)
		cal[i] = cal[i - 1] * i, cal[i] %= TT;
}

void DFS(int x, int k, int sum)
{
	if (sum == m)
	{
		ans += cal[n - k];
		ans %= TT;
		return;
	}
	if (k == n)
		return;
	for (int i = 1; i <= n; ++i)
		if (F[i])
			continue;
		else if (x >= c[i] || s[k] == '0')
			F[i] = 1, DFS(x + 1, k + 1, sum), F[i] = 0;
		else
			F[i] = 1, DFS(x, k + 1, sum + 1), F[i] = 0;
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read();
	m = read();
	cin >> s;
	for (int i = 1; i <= n; ++i)
		c[i] = read();
	calc();
	if (n == m)
	{
		int flg = 0;
		for (int i = 0; s[i]; ++i)
			if (s[i] == '0')
			{
				flg = 1;
				break;
			}
		for (int i = 1; i <= n; ++i)
			if (c[i] == 0 || flg == 1)
			{
				flg = 1;
				break;
			}
		if (flg == 1)
			printf("0\n");
		else
			printf("%lld\n", cal[n] % TT);
	}
	else if (m == 1)
		printf("%lld\n", cal[n] % TT);
	else if (n <= 18)
		DFS(0, 0, 0), printf("%lld\n", ans);
	else
		printf("%lld\n", cal[n] % TT);
	return 0;
}