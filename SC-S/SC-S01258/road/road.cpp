#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0, f = 1;
	int ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}

	return x * f;
}
typedef long long ll;
const int Maxn = 1e4+100;
bool vis[Maxn];
int n, m, k;
struct Edge{
	int u, v, val;
	Edge():u(0), v(0), val(0){}
	Edge(int x, int y, int w):u(x), v(y), val(w){}
	bool operator > (const Edge &a) const
	{
		return this->val > a.val;
	}
};
vector<Edge> edge[Maxn];
int price[11][Maxn];
int fa[Maxn];
int Find(int x)
{
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

inline void Merge(int x, int y)
{
	x = Find(x), y = Find(y);
	fa[y] = x;
}
priority_queue<Edge, vector<Edge>, greater<Edge> > ori;
inline ll getans(int status)
{
	int addcnt = 0;
	ll res = 0;
	priority_queue<Edge, vector<Edge>, greater<Edge> > q = ori;
	for(int i = 0; i < k; ++i)
	{
		if((status >> i) & 1)
		{
			addcnt++; res += price[i][0];
			for(int j = 1; j <= n; ++j)
			{
				q.push(Edge(addcnt + n, j, price[i][j]));
			}
		}
	}
	int tempn = n + addcnt;
	for(int i = 1; i <= tempn; ++i)	fa[i] = i;
	int tot = 0;
	while(!q.empty() && tot < tempn - 1)
	{
		Edge eg = q.top();
		q.pop();
		int u = eg.u, v = eg.v;
		int fau = Find(u), fav = Find(v);
		if(fau == fav) continue;
		Merge(u, v);
		res += eg.val;
		++tot; 
	}
	return res;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out","w",stdout);
	n = read(), m = read(), k = read();
	for(int i = 0; i < m; ++i)
	{
		int u = read(), v = read(), w = read();
		edge[u].emplace_back(Edge(u, v, w));
		edge[v].emplace_back(Edge(v, u, w));
		ori.push({u, v, w});
	}
	for(int i = 0; i ^ k; ++i)
	{
		price[i][0] = read();
		for(int j = 1; j <= n; ++j)
		price[i][j] = read();
	}
	ll ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 0; i < (1 << k); ++i)
	{
		ans = min(ans, getans(i));
	}
	cout << ans;
	return 0;
}