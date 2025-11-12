#include <bits/stdc++.h>
using namespace std;
#define ll long long
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
vector <pair<ll,ll> > e[10004],c[15];
int n,m,k;
long long d[10004],z[15],ans;
bool f[10004];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(d,0x3f,sizeof d);
	d[1] = 0;
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	q.push({0,1});
	while (!q.empty())
	{
		auto g = q.top();
		q.pop();
		ll u = g.second;
		if (f[u]) continue;
		f[u] = 1;
		for (auto g : e[u])
		{
			ll v = g.first,w = g.second;
			if (d[v] > w)
			{
				d[v] = w;
				q.push({d[v],v});
			}	
		}
	}
	for (int i = 1; i <= k; i ++)
	{
		long long x,a,minn = 0x3f;
		cin >> x;
		c[i].push_back({0,x});
		for (int j = 1; j <= n; j ++)
		{
			cin >> a;
			c[i].push_back({j,a});
			if (a - d[j] < minn)
			{
				minn = min(minn,a-d[j]);
				z[i] = j;
			}
		}
		c[i][0].second += minn;
	}
	long long minn = 0x3f;
	for (int i = 1; i <= k; i ++)
	{
		long long sum = c[i][0].second,num=1;
		for (auto g : c[i])
		{
			ll v = g.first,w = g.second;
			if (v == 0 || v == z[i]) continue;
			if (d[v] > w)
				sum -= d[v] - w;
			cout << sum << " " << i << " "<<d[v] << " " << w <<endl;
		}
		if (sum <= minn)
		{
			num = i;
			minn = sum;
		}
	}
	cout << minn<<endl;
	if (minn < 0)ans = minn;
	for (int i = 1; i <= n; i ++)
	{
		ans += d[i];
	}
	cout << ans;
	return 0;
}
