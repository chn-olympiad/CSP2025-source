#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
#define LL long long
#define fi first
#define se second
#define mp make_pair
using namespace std;
//14:48 begin
//14:57 realize what I need to do
//15:1? find out Union-Find Set is wrong
//15:18 pass examples
//generate bigger(m = 1e6),if C is too hard
//O(2^k k^2 n)?but too hard to get the limit,0.5s in ex3 and 0.3s in ex4
struct E
{
	int u;
	int v;
	int w;
};

E e[1000010];
vector<E> te,a[20];
int c[20];
int fa[20010];
int findfa(int x)
{
	return x == fa[x] ? x : fa[x] = findfa(fa[x]);
}

bool cmp(E x,E y)
{
	return x.w < y.w;
}
LL ans = 0;
int n,m,k;
LL solve(int sit)
{
	vector<pair<int,int>> p;
	p.push_back(mp(0,0));
	int cnt = n;
	LL sum = 0;
	for(int i = 1; i <= k; i++)
	{
		if(sit & (1 << i - 1))
		{
			cnt++;
			p.push_back(mp(0,i));
			sum += c[i];
		}
	}
	for(int i = 1; i <= k + n; i++)
	{
		fa[i] = i;
	}
	while(sum < ans && cnt > 1)
	{
		E now;
		now.u = now.v = 114;
		now.w = 0x3f3f3f3f;
		int id = 0;
		for(int it = 0; it < p.size(); it++)
		{
			pair<int,int> i = p[it];
			if(i.fi != a[i.se].size() && cmp(a[i.se][i.fi],now))
			{
				now = a[i.se][i.fi];
				id = it;
			}
		}
		p[id].fi++;
		if(findfa(now.u) != findfa(now.v))
		{
			fa[fa[now.u]] = fa[now.v];
			sum += now.w;
			cnt--;
		}
//		cout << sum << ' ' << cnt << '\n';
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		e[i].u = u;
		e[i].v = v;
		e[i].w = w;
	}
	sort(e + 1,e + m + 1,cmp);
	for(int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for(int i = 1; i <= m; i++)
	{
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;
		if(findfa(u) != findfa(v))
		{
			fa[fa[u]] = fa[v];
			a[0].push_back(e[i]);
			ans += w;
		}
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
		{
			int w;
			cin >> w;
			E t;
			t.u = n + i;
			t.v = j;
			t.w = w;
			a[i].push_back(t);
		}
		sort(a[i].begin(),a[i].end(),cmp);
	}
	for(int i = 0; i < (1 << k); i++)
	{
		ans = min(ans,solve(i));
	}
	cout << ans;
	return 0;
}

