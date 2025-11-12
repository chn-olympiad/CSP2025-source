#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10, N1 = 1e3 + 10, K = 15;
int n, m, k, s[K], v[K][N], p[N], g[N1][N1], h[N1][N1];
int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}
struct Edge
{
	int a, b, c;
	bool operator<(const Edge &aaa){ return c < aaa.c; }
} e[M];
int kruskal()
{
	for(int i = 1; i <= n; i ++) p[i] = i;
	sort(e + 1, e + m + 1);
	int ans = 0;
	for(int i = 1; i <= m; i ++)
	{
		int a = find(e[i].a), b = find(e[i].b), c = e[i].c;
		if(a != b) p[a] = b, ans += e[i].c;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if(k == 0)
	{
		for(int i = 1, x, y, z; i <= m; i ++) cin >> x >> y >> z, e[i] = {x, y, z};
		cout << kruskal() << "\n";
	}
	else
	{
		
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				g[i][j] = h[i][j] = 1e9;
		for(int i = 1, x, y, z; i <= m; i ++)
		{
			cin >> x >> y >> z;
			if(x > y) swap(x, y);
			g[x][y] = min(g[x][y], z);
			h[x][y] = g[x][y];
		}
		int sigmas = 0;
		for(int i = 1; i <= k; i ++)
		{
			cin >> s[i], sigmas += s[i];
			for(int j = 1; j <= n; j ++) cin >> v[i][j];
		}
		if(sigmas == 0)
		{
			for(int i = 1; i <= k; i ++)
			{
				for(int j = 1; j <= n; j ++)
					for(int k = 1; k < j; k ++)
						g[k][j] = min(g[k][j], v[i][k] + v[i][j]);
			}
			int m1 = 0;
			for(int i = 1; i <= n; i ++)
				for(int j = 1; j < i; j ++)
					if(g[j][i] != 1e9) e[++ m1] = {j, i, g[j][i]};	
			m = m1;
			cout << kruskal() << "\n";
		}
		else
		{
			int ans = 1e9;
			for(int st = 0; st < (1 << k) - 1; st ++)
			{
				int res = 0;
				for(int j = 1; j <= n; j ++)
					for(int k = 1; k < j; k ++)
						g[j][k] = h[j][k];
				for(int i = 1; i <= k; i ++)
					if((st >> i - 1) & 1)
					{
						for(int j = 1; j <= n; j ++)
							for(int k = 1; k < j; k ++)
								g[k][j] = min(g[k][j], v[i][k] + v[i][j]);
						res += s[i];
					}
				if(res > ans) continue;
				int m1 = 0;
				for(int i = 1; i <= n; i ++)
					for(int j = 1; j < i; j ++)
						if(g[j][i] != 1e9) e[++ m1] = {j, i, g[j][i]};	
				m = m1;
				res += kruskal();
				ans = min(res, ans);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
