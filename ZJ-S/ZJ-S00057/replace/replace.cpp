#include <bits/stdc++.h>

#define int long long

using namespace std;

itn n, q;

string s[maxn][2], t[maxn][2];

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

signed main()
{
	n = read();
	q = read();
	for (int i = 1; i <= n; ++i)
		cin >> s[i][0] >> s[i][1];
	for (int i = 1; i <= q; ++i)
		cin >> t[i][0] >> t[i][1];
	for (int i = 1; i <= q; ++i)
	{
	}
	return 0;
}