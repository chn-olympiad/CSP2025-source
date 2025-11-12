#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

vector<PII> g[10010];
bool st[10010];
int c[20];
int a[20][10010];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin >> n >> m >> k;
	
	for (int i = 1; i <= m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	
	priority_queue<PII,vector<PII>,greater<PII> > q;
	st[1] = 1;
	
	for (PII ite : g[1])
	{
		int v = ite.first;
		int w = ite.second;
		q.push({w,v});
	}
	
	long long ans = 0;
	while (!q.empty())
	{
		PII t = q.top();
		q.pop();
		
		int v = t.second;
		int w = t.first;
		
		if (st[v])
			continue;
			
		ans += w;
		st[v] = 1;
		
		for (PII ite : g[v])
		{
			int v1 = ite.first;
			int w1 = ite.second;
			
			if (!st[v1])
				q.push({w1,v1});
		}
	}
	
	cout << ans;
	
	return 0;
}