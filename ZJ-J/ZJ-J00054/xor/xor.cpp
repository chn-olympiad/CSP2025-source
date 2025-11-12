#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 500005;

int n, k, sum, a[maxn];

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
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read();
	k = read();
	for (int i = 1; i <=n; ++i) a[i] = read();
	if (k == 0)
		for (int i = 1; i <=n; ++i)
			if (a[i] == k) ++sum;
		else if (a[i] == a[i + 1]) ++sum, ++i;
	if (k == 1)
		for (int i = 1; i <=n; ++i)
			if (a[i] == k) ++sum;
	printf("%lld\n", sum);
	return 0;
}
