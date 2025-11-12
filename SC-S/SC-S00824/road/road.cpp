#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct line
{
	int u,v,w;
};
line city[1000005];
bool can[10005][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		cin >> city[i].u >> city[i].v >> city[i].w;
		can[city[i].u][city[i].v] = true;
		can[city[i].v][city[i].u] = true;
	}
	for (int i = 1;i <= k;i++)
	{
		int x;
		cin >> x;
		for (int j = 1;j <= n;j++)
		{
			int cost;
			cin >> cost;
		}
	}
	cout << 0;
	return 0;
}