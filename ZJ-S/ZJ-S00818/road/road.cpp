#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 10, M = 1e7, K = 20;
int n, m, k, cur, c[N], a[K][N], fa[N], ans = 1e18;
bool opt = 1;
int mi = 1e18;
struct Edge{int u, v, w;} e[M];
int find(int x){return (x == fa[x] ? x : fa[x] = find(fa[x]));}
bool cmp(Edge x, Edge y){return x.w < y.w;}
int kruskal(int all, int st, int ans)
{
	for(int i = 1; i <= n + k; i ++) fa[i] = i;
	int cnt = 0;
	for(int i = 1; i <= cur; i ++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		if(fu != fv && (u <= n || (u > n && (st & (1 << (u - n))))) && (v <= n || (v > n && (st & (1 << (v - n))))))
		{
			ans += w;
			fa[fu] = fv;
			cnt ++;
		}
		if(cnt == all - 1) break;
	}
	return ans;
}
void dfs(int l, int st, int sum, int cnt)
{
	if(l > k)
	{
		ans = min(ans, kruskal(n + cnt, st, sum));
		return ;
	}
	dfs(l + 1, st, sum, cnt);
	dfs(l + 1, st | (1 << l), sum + c[l], cnt + 1);
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) 
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	cur = m;
	for(int i = 1; i <= k; i ++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j ++) 
		{
			cin >> a[i][j];
			opt &= (a[i][j] == 1);
			e[++ cur] = {n + i, j, a[i][j]};
		}
		mi = min(mi, c[i]);
	}
	sort(e + 1, e + cur + 1, cmp);
	if(opt) ans = min(kruskal(n, 0, 0), mi);
	else dfs(0, 0, 0, 0);
	cout << ans << '\n';
	return 0;
}

