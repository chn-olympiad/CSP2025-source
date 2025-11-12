#include <bits/stdc++.h>
using namespace std;

struct node
{
	int v;
	int w;
};

int n, m, k, c[13], a[13][10055];
vector <node> g[10015];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		node s;
		s.v = v;
		s.w = w;
		g[u].push_back(s);
	}
	int sum = 0;
	for(int i = 1; i <= k; i++)
	{
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			if (i == 1)
			{
				sum += a[i][j];
			}
		}
	}
	sum += c[1];
	cout << sum;
	return 0;
}
