#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 100005;

int T, n, a[maxn][4];

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

void DFS()
{
	for (int i = 1; i <=n; ++i) ;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T--)
	{
		n = read();
		for (int i = 1; i <= n; ++i)
			a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
		DFS();
	}
	return 0;
}