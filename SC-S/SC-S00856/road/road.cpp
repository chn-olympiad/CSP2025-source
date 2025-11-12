#include <bits/stdc++.h>
#define ll long long
#define V vector
using namespace std;
template <typename T>
void read(T& x)
{
	int f = x = 0, v = getchar();
	while(v != '-' && (v < '0' || v > '9')) v = getchar();
	if(v == '-') f = 1, v = getchar();
	while(v >= '0' && v <= '9') x = (x << 3) + (x << 1) + (v & 15), v = getchar();
	if(f) x = -x;
}
const int maxn = 1e4;
const int maxm = 1e6;
const int maxk = 10;

int n, m, k;
ll ans = 1e18;
int fa[maxn + maxk + 5];
int val[maxk + 5];
int a[maxk + 5][maxn + 5];
struct node
{
	int u, v, w;
	node(int Nu = 0, int Nv = 0, int Nw = 0)
		: u(Nu), v(Nv), w(Nw) {} 
};
node e[maxm + 5];
V<node> te, yte;
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for(int i = 1; i <= m; ++i)
		read(e[i].u), read(e[i].v), read(e[i].w);
	for(int i = 1; i <= k; ++i)
	{
		read(val[i]);
		for(int j = 1; j <= n; ++j)
			read(a[i][j]);
	}
	sort(e + 1, e + m + 1, [](node o, node p) {
		return o.w < p.w;
	});
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
	for(int i = 1; i <= m; ++i)
	{
		int x = find(e[i].u), y = find(e[i].v);
		if(x != y)
			fa[x] = y, te.push_back(e[i]);
	}
	yte = te;
	for(int i = 0; i < (1 << k); ++i)
	{
		te = yte;
		int nown = n;
		ll now = 0; 
		for(int j = 1; j <= k; ++j)
			if(i & (1 << (j-1)))
			{
				now += val[j];
				for(int l = 1; l <= n; ++l)
					te.emplace_back(n + j, l, a[j][l]);
				++nown; 
			}
		sort(te.begin(), te.end(), [](node o, node p) {
			return o.w < p.w;
		});
		for(int j = 1; j <= n + nown; ++j)
			fa[j] = j;
		for(node j : te)
		{
			int x = find(j.u), y = find(j.v);
			if(x != y)
				fa[x] = y, now += j.w;
		}
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}