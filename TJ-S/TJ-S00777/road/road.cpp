#include <bits/stdc++.h>

using namespace std;

struct pos
{
	int x, y;
};

int n, m, k, a[11][1001], b[11];
vector<pos> v[1001];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) 
	{
		int u, v1, w;
		cin >> u >> v1 >> w;
		pos p;
		p.x = v1;
		p.y = w;
		v[u].push_back(p);
	}
//	for (int i = 1; i <= k; i++)
//	{
//		cin >> a[i]
//	}
	return 0;
}
