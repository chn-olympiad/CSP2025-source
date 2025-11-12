#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, m, k, cnt, cnt2;
struct Bie{
	ll neww, u, v, w;
}edge[4000005];
ll kind[4000005], ans, dp[4000005];
bool is[4000005];

ll find(int x)
{
	if (kind[x] == x) return x;
	return kind[x] = find(kind[x]);
}

bool cmp(Bie a, Bie b)
{
	return a.w < b.w;
}

void Kruscal()
{
	ll nn = n;
	for (ll i = 1; cnt2 < nn - 1; i++)
	{
		if (find(edge[i].u) != find(edge[i].v))
		{
			ans += edge[i].w;
			kind[edge[i].u] = kind[edge[i].v];
			cnt2++;
			/*if (is[edge[i].u])
			{
				nn++;
				is[edge[i].u] = 0;
			}
			if (is[edge[i].v])
			{
				nn++;
				is[edge[i].v] = 0;
			}*/
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		edge[++cnt].u = u, edge[cnt].v = v, edge[cnt].w = w;
		kind[u] = u, kind[v] = v;
	}
	for (ll i = 1; i <= k; i++)
	{
		kind[n + i] = n + i;
		ll temp;
		cin >> temp;
		for (ll j = 1; j <= n; j++)
		{
			ll t;
			cin >> t;
			edge[++cnt].u = n + i, edge[cnt].v = j, edge[cnt].w = t, edge[cnt].neww = temp;
		 }
		is[n + i] = 1;
	}
	sort(edge + 1, edge + cnt + 1, cmp);
	
	Kruscal(); //???
	
	cout << ans << endl;
	
	return 0;
}

