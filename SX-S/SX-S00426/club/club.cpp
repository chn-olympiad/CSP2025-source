#include <bits/stdc++.h>
using namespace std;
const int maxn = 201;
int T = 0, n = 0, maxp = 0, ans = 0, a[maxn][3], cnt[3];

inline void fastread(int &x)
{
	x = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c))
	{
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar();
	}
}
inline void fastprint(int x)
{
	if(x > 9)
		fastprint(x / 10);
	putchar(x % 10 + '0');
}

inline void dfs(int x, int val)
{
	if(x == n + 1)
	{
		ans = max(ans, val);
		return;
	}
	for(int i = 0; i <= 2; ++i)
		if(cnt[i] + 1 <= maxp)
		{
			++cnt[i];
			dfs(x + 1, val + a[x][i]);
			--cnt[i];
		}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	fastread(T);
	while(T--)
	{
		fastread(n);
		ans = cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j <= 2; ++j)
				fastread(a[i][j]);
		maxp = n >> 1;
		dfs(1, 0);
		fastprint(ans);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
