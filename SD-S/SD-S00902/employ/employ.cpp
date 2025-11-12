#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;
#define int long long
int read()
{
	int res = 0, f = 1;
	char s = getchar();
	while (s < '0' || s > '9')
	{
		if (s == '-') f = -1;
		s = getchar();
	}
	while ('0' <= s && s <= '9')
	{
		res = (res << 1) + (res << 3) + (s ^ 48);
		s = getchar();
	}
	return res * f;
}
void write(int v)
{
	if (v < 10)
	{
		putchar(v + '0');
		return ;
	}
	write(v / 10);
	putchar(v % 10 + '0');
}
void wt(int v, bool f = 1)
{
	if (v < 0) putchar('-'), v = -v;
	write(v);
	putchar(f ? '\n' : ' ');
}
#define rd read()

const int N = 505;
const int MOD = 998244353;
const int Fill = 0x3f3f3f3f;
const int INF = 0x7fffffff;

int n, m, refuse;
int c[N], id[N];
char s[N];

signed main()
{
	int i, j, k;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	n = rd, m = rd;
	cin >> (s + 1);
	for (i = 1; i <= n; i++)
	{
		if (s[i] == '0')
		{
			refuse++;
		}
	}
	int min_ = INF;
	for (i = 1; i <= n; i++)
	{
		c[i] = rd;
		min_ = min(min_, c[i]);
	}
	if (n <= 12)
	{
		int ans = 0;
		for (i = 1; i <= n; i++)
		{
			id[i] = i;
		}
		do
		{
			int cnt = 0;
			for (i = 1; i <= n; i++)
			{
				if (s[i] == '0' || cnt >= c[id[i]])
				{
					cnt++;
				}
			}
			if (n - cnt >= m)
			{
				ans++;
			}
		}while (next_permutation(id + 1, id + n + 1));
		wt(ans);
		return 0;
	}
	if (m == n)
	{
		if (refuse)
		{
			wt(0);
			return 0;
		}
		if (!min_)
		{
			wt(0);
			return 0;
		}
		int ans = 1;
		for (i = 2; i <= n; i++)
		{
			ans = ans * i % MOD;
		}
		wt(ans);
		return 0;
	}
	return 0;
}

