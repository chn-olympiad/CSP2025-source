#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
const int INF = 998554;
int city[MAXN + 100];
int city2[200][200] = {INF};

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	for (int i = 1; i <= 200; i++)
	{
		for(int j = 1; j <= 200; j++)
		{
			city2[i][j] = INF;
		}
	}
	int n, m, k;
	cin >> n >> m >> k;
	int u, v, w;
	for(int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		if(city2[u][v] > w) city2[u][v] = w;
	}
	int c;
	int help;
	for(int i = 1; i <= k; i++)
	{
		cin >> c;
		for(int j = 1; j <= m; j++)
		{
			cin >> city[j];
		}
		for(int x = 1; x <= m; x++)
		{
			for(int y = x+1; y <= m; y++)
			{
				help = city[x] + city[y] + c;
				if(help < city2[x][y]) city2[x][y] = help;
			}
		}
	}
	priority_queue<int, vector<int>, greater<int> > q;
	int h1, h2;
	for(int i = 1; i <= m; i++)
	{
		for(int j = i+1; j <= m; j++)
		{
			h1 = city2[i][j];
			h2 = city2[j][i];
			if(h1 < h2) q.push(h1);
			else q.push(h2);
		}
	}
	long long ans = 0;
	for(int i = 1; i <= m-1; i++)
	{
		ans += q.top();
		q.pop();
	}
	cout << ans << endl;
	return 0;
}
