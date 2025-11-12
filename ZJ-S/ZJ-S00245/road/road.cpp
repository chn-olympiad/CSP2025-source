#include<bits/stdc++.h>
using namespace std;
//just stdc++14.:)
//unfinished
//expected score: 32pts
typedef long long LL;
const int N = 1e4 + 10, M = 1e6 + 10, K = 15;
//int h[N], e[M], w[M], ne[M], idx;
int n, m, k;
int a[K][N];
int p[N];
LL ans = LONG_LONG_MAX;
bool st[K];

struct Edge
{
	int u, v, w;
	Edge() : u(0), v(0), w(0) {}
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}
	
	bool operator < (const Edge &p) const
	{
		return w < p.w;
	}
}edges[M], aedges[M + N];
#define ei edges[i]
#define aei aedges[i]

//void add(int u, int v, int c) // a bit unconvenient :(
//{
//	e[idx] = v, w[idx] = c, ne[idx] = h[u], h[u] = idx ++;
//}
void set_init()
{
	for(int i = 1; i <= n; i ++) p[i] = i;
}
int find(int x)
{
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}
LL kruskal(int sk)
{
	set_init();
	int eidx = m;
	for(int i = 1; i <= m; i ++) aedges[i] = edges[i];
	if(sk)
		for(int i = 1; i <= n; i ++)
			aedges[++ eidx] = Edge(n + 1, i, a[sk][i]);
	sort(aedges + 1, aedges + eidx + 1);
	LL res = 0;
	int cnt = 0;
	for(int i = 1; i <= eidx; i ++)
	{
		int u = find(aei.u), v = find(aei.v);
		if(u == v) continue;
		p[u] = v; // merge
		cnt ++, res += aei.w;
		if(cnt == n - (sk ? 0 : 1)) break;
	}
	return res;
}
int main()
{
	//init the code
freopen("road2.in", "r", stdin);
freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	//input
	cin >> n >> m >> k;
	int u, v, c;
	for(int i = 1; i <= m; i ++)
	{
		cin >> ei.u >> ei.v >> ei.w;
//		add(ei.u, ei.v, ei.w), add(ei.v, ei.u, ei.w);
	}
	for(int i = 1; i <= k; i ++)
		for(int j = 0; j <= n; j ++)
			cin >> a[i][j];
	//body
	for(int i = 0; i <= k; i ++)
		ans = min(ans, kruskal(i) + a[i][0]);
	//output
	cout << ans << "\n";
	
	return 0;
}
//rp++
