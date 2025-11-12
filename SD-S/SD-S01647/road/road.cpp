#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <list>
using namespace std;
typedef long long ll;
inline int read()
{
	int s = 0, w = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-'){w = -1;}ch = getchar();}
	while(isdigit(ch)) s = s * 10 + ch - 48, ch = getchar();
	return s * w;
}
int n, m, k, K;
int f[10013];
struct E
{
	int u, v, val;
} t[1000003], e[2000003];
ll ans = 0;
int c[13], ct, cb;
int b[13];
int a[13][10003];
int dis[1003][1003];
inline int ff(int x)
{
	return ((f[x] == x) ? (x) : (f[x] = ff(f[x])));
}
inline bool cmp(E a, E b)
{
	return a.val < b.val; 
}
inline void solve0()
{
	int cnt = 0, x, y;
	for(int i = 1;i <= m;++ i) t[i].u = read(), t[i].v = read(), t[i].val = read();
	for(int i = 1;i <= n;++ i) f[i] = i;
	sort(t + 1, t + m + 1, cmp);
	for(int i = 1;i <= m;++ i)
	{
		x = ff(t[i].u), y = ff(t[i].v);
		if(x == y) continue;
		f[x] = y;
		++ cnt;
		ans += t[i].val;
		if(cnt == n - 1) break;
	}
	cout << ans << '\n';
}
ll cnt;
inline void D(int w, int sz = n)
{
	cnt = 0;
	cb = m;
	for(int i = 1;i <= k;++ i) if(w & (1 << (i - 1))) b[i] = ++ sz, cnt += c[i];else b[i] = 0;
	for(int i = 1;i <= cb;++ i) e[i] = t[i];
	for(int i = 1;i <= sz;++ i) f[i] = i;
	for(int i = 1;i <= k;++ i)
	{
		if(!b[i]) continue;
		for(int j = 1;j <= n;++ j)
		{
			e[++ cb].u = b[i];
			e[cb].v = j;
			e[cb].val = a[i][j];
		}
	}
	int cn = 0, x, y;
	sort(e + 1, e + cb + 1, cmp);
	for(int i = 1;i <= cb;++ i)
	{
		x = ff(e[i].u), y = ff(e[i].v);
		if(x == y) continue;
		++ cn;
		f[x] = y;
		cnt += e[i].val;
		if(cnt > ans) return;
		if(cn == sz - 1) break;
	}
	ans = min(ans, cnt);
}
inline void solve()
{
	for(int i = 1;i <= m;++ i) t[i].u = read(), t[i].v = read(), t[i].val = read();
	sort(t + 1, t + m + 1, cmp);
	for(int i = 1;i <= k;++ i)
	{
		c[i] = read();
		for(int j = 1;j <= n;++ j) a[i][j] = read();
	}
	K = (1 << k);
	ans = 1e14;
	for(int i = 0;i < K;++ i) D(i);
	cout << ans << '\n';
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	if(k == 0) return solve0(), 0;
	if(n <= 1000 && k <= 5 && m <= 100000) return solve(), 0;
	for(int i = 1;i <= m;++ i)
	{
		e[i].u = read(), e[i].v = read(), e[i].val = read();
	}
	for(int i = 1;i <= k;++ i)
	{
		c[i] = read();
		for(int j = 1;j <= n;++ j)
		{
			a[i][j] = read();
			e[++ m].u = i + n;
			e[m].v = j;
			e[m].val = a[i][j];
		}
	}
	int cn = 0, x, y;
	n += k;
	for(int i = 1;i <= n;++ i) f[i] = i;
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1;i <= m;++ i)
	{
		x = ff(e[i].u), y = ff(e[i].v);
		if(x == y) continue;
		++ cn;
		ans += e[i].val;
		f[x] = y;
		if(cn == n - 1) break;
	}
	cout << ans << '\n';
	return 0;
}
