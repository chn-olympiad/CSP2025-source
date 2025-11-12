#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 15;

string s;

int num[maxn];

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
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; s[i]; ++i)
		if (s[i] >= '0' && s[i] <= '9') ++num[s[i] - '0'];
	for (int i = 9; i >=0; --i)
		for (int j = 1; j <= num[i]; ++j)
			printf("%lld", i);
	printf("\n");
	return 0;
}
