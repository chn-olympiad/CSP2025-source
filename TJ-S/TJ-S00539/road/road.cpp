#include <bits/stdc++.h>
using namespace std;

vector <int> v1[100005];

long long w1[100005], w2[15][10005], c[15], ans, cnt;

int in[10005];

bool chk[10005], flag[15];

/*void dfs(int x)
{
	for (int i = 1; i <= in[x]; i++)
	{
		if (v[x][i])
	}
}*/

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d%lld", &u, &v, &w1[i]);
		ans += w1[i];
		v1[u].push_back(v), v1[v].push_back(u);
		in[u]++, in[v]++;
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> w2[i][j];
	}
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= in[i]; j++)
		{
			
		}
	}*/
	cout << ans << endl;
	return 0;
}
