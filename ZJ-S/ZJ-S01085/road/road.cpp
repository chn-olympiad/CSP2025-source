#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int v,w;
};
int n,m,k,c[100],a[15][10005],minn = 1e9;
vector <Node> adj[10005];
bool cmp(Node x,Node y)
{
	return x.w < y.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
	}
	for(int i = 1;i <= k;i ++)
	{
		int sum = 0;
		cin >> c[i];
		sum += c[i];
		for(int j = 1;j <= n;j ++)
		{
			cin >> a[i][j];
			sum += a[i][j];
		}
		minn = min(minn,sum);
	}
	cout << minn;
	return 0;
}
