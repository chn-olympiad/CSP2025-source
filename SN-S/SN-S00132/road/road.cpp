//tyy tyz 8z03
#include <bits/stdc++.h>
using namespace std;
int n , m , k , c[15] , a[15][10004] , fa[10004] , f[15];
long long ans;
vector <pair <int , int> > ve[10004];
priority_queue <pair <int , pair <int , int> > > pq;
int Find (int x)
{
	if (! f[x]) return x;
	return f[x] = Find (f[x]);
}
int main ()
{
	freopen ("road.in" , "r" , stdin);
	freopen ("road.out" , "w" , stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> n >> m >> k;
	while (m --)
	{
		int u , v , w;
		cin >> u >> v >> w;
		ve[u].push_back ({v , w});
		ve[v].push_back ({u , w});
	}
	for (int i = 1;i <= k;i ++)
	{
		cin >> c[i];
		for (int j = 1;j <= n;j ++)
		{
			cin >> a[i][j];
			if (! a[i][j]) fa[j] = i;
			else pq.push ({- a[i][j] , {i , j}});
		}
	}
	for (int i = 1;i <= n;i ++)
		if (fa[i])
			for (pair <int , int> j : ve[i])
				if (! fa[j.first]) pq.push ({- j.second , {fa[i] , j.first}});
	while (! pq.empty ())
	{
		if (fa[pq.top ().second.second])
		{
			pq.pop ();
			continue;
		}
		fa[pq.top ().second.second] = pq.top ().second.first;
		ans -= pq.top ().first;
		for (pair <int , int> j : ve[pq.top ().second.second])
			if (! fa[j.first]) pq.push ({- j.second , {fa[pq.top ().second.second] , j.first}});
		pq.pop ();
	}
	for (int i = 1;i <= n;i ++)
		for (pair <int , int> j : ve[i])
			if (fa[i] != fa[j.first]) pq.push ({- j.second , {fa[i] , fa[j.first]}});
	while (! pq.empty ())
	{
		pair <int , pair <int , int> > t = pq.top ();
		pq.pop ();
		int s = Find (t.second.first) , b = Find (t.second.second);
		if (s == b) continue;
		f[s] = b;
		ans -= t.first;
	}
	cout << ans;
	return 0;
}
