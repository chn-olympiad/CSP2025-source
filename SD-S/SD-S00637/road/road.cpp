#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10, M = 1e6 + 20;

#define int long long

int n, m, k;
int f[N], f1[N], a[20][N];
struct Edge
{
	int u, v, w;
}e[M], e1[M];

inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while ( c < '0' || c > '9' )
	{
		if ( c == '-' )
			f = -1;
		c = getchar();
	}
	while ( c >= '0' && c <= '9' )
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

inline void write(int x)
{
	if ( x < 0 ) putchar('-'), x = -x;
	if ( x > 9 ) write(x / 10);
	putchar(x % 10 + '0');
}

int find(int x)
{
	if ( f[x] == x ) return x;
	return f[x] = find(f[x]);
}

void Union(int x, int y)
{
	int fx = find(x), fy = find(y);
	f[fx] = fy;
}

int find1(int x)
{
	if ( f1[x] == x ) return x;
	return f1[x] = find(f1[x]);
}

void Union1(int x, int y)
{
	int fx = find(x), fy = find(y);
	f1[fx] = fy;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read(), m = read(), k = read();
	
	for (int i = 1; i <= m; i ++ )
		e1[i] = e[i] = {read(), read(), read()};
	for (int i = 1; i <= n; i ++ )
		f1[i] = i;
		
	sort(e1 + 1, e1 + m + 1, [](const Edge& a, const Edge& b){
		return a.w < b.w;
	});
	
	int ans1 = 0;
	if ( m > n - 1 )
	{
		int cnt1 = 0;
		for (int i = 1; i <= m; i ++ )
		{
			int u = e1[i].u, v = e1[i].v, w = e1[i].w;
			if ( find1(u) != find1(v) )
			{
				Union1(u, v);
				ans1 += w;
				cnt1 ++;
			}	
			if ( cnt1 == n - 1 )
				break;
		}
	}
	if ( k == 0 )
	{
		write(ans1);
		return 0;
	}
	if ( ans1 == 0 ) ans1 = 1e9 + 10;
	
	int c, val = 1e9 + 10, id = 0;
	for (int i = 1; i <= k; i ++ )
	{
		c = read();
		for (int j = 1; j <= n; j ++ ) a[i][j] = read();
		if ( c < val )
			val = c, id = i;
	}
	
	if ( k != 0 )
	{
		for (int i = 1; i <= n; i ++ )
			e[++ m] = {n + 1, i, a[id][i]};
		n ++;
		for (int i = 1; i <= n; i ++ )
			f[i] = i;
		
		sort(e + 1, e + m + 1, [](const Edge& a, const Edge& b){
			return a.w < b.w;
		});
		
		int cnt = 0, ans = 0;
		for (int i = 1; i <= m; i ++ )
		{
			int u = e[i].u, v = e[i].v, w = e[i].w;
			if ( find(u) != find(v) )
			{
				Union(u, v);
				ans += w;
				cnt ++;
			}	
			if ( cnt == n - 1 )
				break;
		}
		
		if ( k != 0 )
			ans += val;
		write(min(ans, ans1));
	}

	return 0;
	
}
