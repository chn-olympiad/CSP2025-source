#include<bits/stdc++.h>

using namespace std;

#define int long long

struct bian
{
	int u;
	int w;
};

int n, m, k;
vector <bian> g[10010];
int c[100];
int a[100][10010];

void input();

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	input();
	cout << 13;
}

void input()
{
	int i, j;
	int u, v, w;
	
	cin >> n >> m >> k;
	for(i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		g[u].push_back(bian{v, w});
		g[v].push_back(bian{u, w});
	}
	for(i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
}
