#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int read()
{
	int res = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * f;
}
struct Node
{
	int a, b, c;
};
Node a[200005];
int n, ans, sa, sb, sc, fla = 1, flb = 1;
bool cmp(Node x, Node y)
{
	if (x.a == y.a)
		if (x.b == y.b)
			return x.c > y.c;
		return x.b > y.b;
	return x.a > y.a;
}
void dfs(int now, int tot)
{
	if (now > n)
	{
		ans = max(ans, tot);
		return;
	}
	if (sa < n / 2)
	{
		sa++;
		dfs(now + 1, tot + a[now].a);
		sa--;
	}
	if (sb < n / 2)
	{
		sb++;
		dfs(now + 1, tot + a[now].b);
		sb--;
	}
	if (sc < n / 2)
	{
		sc++;
		dfs(now + 1, tot + a[now].c);
		sc--;
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = read();
	while (t--)
	{
		n = read(), ans = 0, sa = 0, sb = 0, sc = 0, fla = 1;
		for (int i = 1; i <= n; i++)
		{
			a[i].a = read(), a[i].b = read(), a[i].c = read();
			if (a[i].c != 0) fla = 0;
		}
		sort(a + 1, a + n + 1, cmp);
		if (fla)
		{
			for (int i = 1; i <= n / 2; i++)
			{
				ans += a[i].a;
			}
		}	
		else
		{
			dfs(1, 0);
		}
		cout << ans << '\n';
	} 
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
