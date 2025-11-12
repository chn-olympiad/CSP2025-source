#include <bits/stdc++.h>
using namespace std;
#define int long long
int uf[11005];
struct edge
{
	int from,to,val;
} g[2000005];
bool cmp(edge x,edge y)
{
	return x.val < y.val;
}
vector<int> gph[11005];
int find(int u)
{
	return (uf[u] == u?u:uf[u] = find(uf[u]));
}
bool vis[10005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i <= 2000000;i++) uf[i] = i;
	if(k == 0)
	{
		for(int i = 1;i <= m;i++) cin >> g[i].from >> g[i].to >> g[i].val;
		sort(g + 1,g + m + 1,cmp);
		int cnt = 0,ans = 0;
		for(int i = 1;i <= m;i++)
		{
			if(find(g[i].from) != find(g[i].to))
			{
				cnt++;
				ans += g[i].val;
				uf[find(g[i].from)] = g[i].to;
			}
			if(cnt == n - 1) break;
		}
		cout << ans;
	}
	else
	{
		for(int i = 1;i <= m;i++) cin >> g[i].from >> g[i].to >> g[i].val;
		for(int i = 0;i < k;i++)
		{
			cin >> g[0].val;
			for(int j = 1;j <= n;j++)
			{
				int tmp = m + i * n + j;
				cin >> g[tmp].val;
				g[tmp].from = n + i + 1;
				g[tmp].to = j;
			}
		}
		m = m + (k * n);
		sort(g + 1,g + m + 1,cmp);
		int ans = 0;
		for(int i = 1;i <= m;i++)
		{
			if(find(g[i].from) != find(g[i].to))
			{
				ans += g[i].val;
				uf[find(g[i].from)] = g[i].to;
				bool tag = 1;
				vis[g[i].from] = vis[g[i].to] = 1;
				for(int j = 1;j <= n;j++) tag &= vis[j];
				if(tag) break;
			}
		}
		cout << ans;
	}
	return 0;
}