#include<bits/stdc++.h>
using namespace std;
#define lson (u*2)
#define rson (lson+1)
#define mid ((l+r)>>1)
#define LL long long
const LL N = 3e6 + 10, M = 1e4 + 10, INF = 0x3f3f3f3f3f3f3f3f;
LL n, m, k;
LL p[M];
LL sum;
LL h[M], e[N], ne[N], w[N], idx;
LL b[M];
LL depth[M], top[M], fa[M], dfn[M], undfn[M], cnt = 1, siz[M], son[M];
LL c[M];
struct Node
{
	LL u, v, w;
	bool operator < (const Node &a) const
	{
		return w < a.w;
	}
}a[N];
struct Tree
{
	LL sum, i;
}tr[N << 2];
Tree longest[M][M];
void add(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}
int find(int n)
{
	if (p[n] != n) p[n] = find(p[n]);
	return p[n];
}
void kr()
{
	for (int i = 1; i <= m; i ++)
	{
		int u, v, w;
		u = a[i].u, v = a[i].v, w = a[i].w;
		if (find(u) != find(v))
		{
			add(u, v, w), add(v, u, w);
			sum += w;
			p[find(u)] = p[find(v)];
		}
	}
}
void dfs(int u, int father)
{
	depth[u] = depth[father] + 1;
	fa[u] = father;
	siz[u] = 1;
	int maxn = -1;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j == father) continue;
		dfs(j, u);
		siz[u] += siz[j];
		c[j] = w[i];
		if (maxn < siz[j])
		{
			maxn = siz[j];
			son[u] = j;
		}
	}
}
void dfs2(int u, int t)
{
	undfn[u] = cnt;
	dfn[cnt ++] = u;
	top[u] = t;
	if (son[u] != 0) dfs2(son[u], t);
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j == son[u] || j == fa[u]) continue;
		dfs2(j, j);
	}
}
int lca(int u, int v)
{
	while (top[u] != top[v])
	{
		if (depth[top[u]] < depth[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	if (depth[u] > depth[v]) return v;
	else return u;
}
Tree maxv(Tree a, Tree b)
{
	Tree ans;
	if (a.sum > b.sum)
		ans.sum = a.sum, ans.i = a.i;
	else
		ans.sum = b.sum, ans.i = b.i;
	return ans;
}
void push_up(int u)
{
	tr[u] = maxv(tr[rson], tr[lson]);
}
void build(int l, int r, int u)
{
	if (l == r)
	{
		tr[u].sum = c[dfn[l]];
		tr[u].i = u;
		return;
	}
	build(l, mid, lson), build(mid + 1, r, rson);
	push_up(u);
}
Tree query(int lk, int rk, int l, int r, int u)
{
	if (lk <= l && r <= rk)
		return tr[u];
	if (r < lk || l > rk) 
	{
		Tree ans;
		ans.i = 0, ans.sum = -INF;
		return ans;
	}
	Tree ans = maxv(query(lk, rk, l, mid, lson), query(lk, rk, mid + 1, r, rson));
	push_up(u);
	return ans;
}
void change(int x, int k, int l, int r, int u)
{
	if (l == r && l == x)
	{
		tr[u].sum = k;
		return;
	}
	if (x > r || x < l) return;
	change(x, k, l, mid, lson), change(x, k, mid + 1, r, rson);
	push_up(u);
}
Tree get(int father, int u)
{
	Tree ans;
	ans.i = 0, ans.sum = -INF;
	while (top[father] != top[u])
	{
		ans = maxv(ans, query(undfn[top[u]], undfn[u], 1, cnt, 1));
		u = fa[top[u]];
	}
	ans = maxv(ans, query(undfn[son[father]], undfn[u], 1, cnt, 1));
	return ans;
}
void init()
{
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
		{
			int f = lca(i, j);
			longest[i][j] = maxv(get(f, i), get(f, j));
		}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(h, -1, sizeof h);
	scanf("%lld %lld %lld", &n, &m, &k);
	for (int i = 1; i <= n; i ++)
		p[i] = i;
	for (int i = 1; i <= m; i ++)
	{
		LL u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		a[i].u = u, a[i].v = v, a[i].w = w;
	}
	sort(a + 1, a + m + 1);
	kr();
	dfs(1, 0);
	dfs2(1, 1);
	cnt --;
	build(1, cnt, 1);
	init();
	for (int i = 1; i <= k; i ++)
	{
		LL c;
		scanf("%lld", &c);
		for (int i = 1; i <= n; i ++)
			scanf("%lld", &b[i]);
		LL new_sum = sum + c;
		for (int i = 1; i <= n; i ++)
			for (int j = i + 1; j <= n; j ++)
			{
				LL spend = b[i] + b[j];
				Tree maxn = longest[i][j];
				if (new_sum - maxn.sum + spend < sum)
				{
					sum = new_sum - maxn.sum + spend;
					change(maxn.i, spend, 1, cnt, 1);
					int f = lca(i, j);
					longest[i][j] = maxv(get(f, i), get(f, j));
				}
			}
	}
	printf("%lld\n", sum);
	return 0;
}
