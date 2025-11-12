#include <bits/stdc++.h>
using namespace std;

const int N = 10010, M = 1000010;
int n, m, k, ans;

int fa[N], cnt;

int a[15][N], c[15], top;
bool flag[15];

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

struct nod{
	int u,v,w, mid;
} e[M+10*N];

bool cmp(nod a, nod b)
{
	return a.w < b.w;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k; flag[0] = 1;
	for (int i = 1; i <= n; i ++) fa[i] = i;
	for (int i = 1; i <= m; i ++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].mid = 0;
	}
	for (int i = 1; i <= k; i ++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j ++)
		{
			cin >> a[i][j];
		}
		for (int j = 1; j <= n; j ++)
		{
			for (int k = 1; k <= n; k ++)
			{
				if (k == j) continue;
				top ++;
				e[m+top]={j, k, a[i][j]+a[i][k], i};
			}
		}
	}
	
	if (n == 1)
	{
		cout << "0" << "\n";
		return 0;
	}
	
	sort(e+1, e+1+m+top, cmp);
	
	for (int i = 1; i <= m+top; i ++)
	{
		int x = find(e[i].u), y = find(e[i].v);
		if (x != y)
		{
			cnt ++;
			fa[x] = y;
			int id = e[i].mid;
			ans += e[i].w+(flag[id] ? 0 : c[id]);
			flag[id] = 1;
			if (cnt == n-1)
			{
				cout << ans << "\n";
				return 0;
			}
		}
	}
	
	return 0;
}
