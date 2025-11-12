//xianshitieyizhongxue wangzhengqinghe 13891989834 chusan
#include<bits/stdc++.h>
#define fir first
#define sec second
#define ll long long
#define ull unsigned ll
#define ldb long double
#define inf 1000000010
#define infll 1000000000000000010ll
#define maxn 100000
#define maxk 10
using namespace std;
int aqx, n, m, k, C[maxk + 10], FA[maxn + maxk + 10];
vector<int> p;
struct edge
{
	int u, v, w;
};
vector<edge> V[maxk + 10], F[(1 << maxk) + 10];
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
int find(int x)
{
	return ((x == FA[x]) ? x : (FA[x] = find(FA[x])));
}
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	return;
}
void solve()
{
	cin >> n >> m >> k;
	while (m--)
	{
		int u, v, w; cin >> u >> v >> w;
		V[0].push_back(edge{u, v, w});
	}
	for (int i = 1;i <= k;i++)
	{
		cin >> C[i];
		for (int j = 1;j <= n;j++)
		{
			int x; cin >> x;
			V[i].push_back(edge{n + i, j, x});
		}
	}
	for (int i = 0;i <= k;i++) sort(V[i].begin(), V[i].end(), cmp);
	for (int i = 1;i <= n;i++) FA[i] = i;
	int cnt = n; ll ans = 0;
	for (edge i:V[0])
	{
		if (find(i.u) == find(i.v)) continue;
		F[0].push_back(i); ans += i.w; FA[find(i.u)] = find(i.v); cnt--;
		if (cnt == 1) break;
	}
	for (int s = 1;s < (1 << k);s++)
	{
		int id = 0;
		for (int i = k;i >= 1;i--) if ((s >> (i - 1)) & 1) {id = i; break;}
		int t = s - (1 << (id - 1));
		ll sum = 0; int now = n;
		int idx = 0, idy = 0;
		for (int i = 1;i <= k;i++) if ((s >> (i - 1)) & 1) {sum += C[i]; now++;}
		for (int i = 1;i <= n + k;i++) FA[i] = i;
		while (1)
		{
			int tt = 0;
			if ((idx != F[t].size()) && ((idy == V[id].size()) || (F[t][idx].w < V[id][idy].w)))
			{
				int p = find(F[t][idx].u), q = find(F[t][idx].v), r = F[t][idx].w; 
				F[s].push_back(F[t][idx]); idx++;
				if (p != q) {FA[p] = q; now--; sum += r;}
			}
			else
			{
				int p = find(V[id][idy].u), q = find(V[id][idy].v), r = V[id][idy].w; 
				F[s].push_back(V[id][idy]); idy++;
				if (p != q) {FA[p] = q; now--; sum += r;}
			}
			if (now == 1) break;
		}
		ans = min(ans, sum);
	}
	cout << ans << "\n";
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	init();
	aqx = 1;
	while (aqx--) solve();
	return 0;
}
