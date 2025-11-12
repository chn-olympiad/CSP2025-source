#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
int n,m,k;
int fa[maxn];
struct node
{
	int to;
	ll w;
};
struct edge
{
	int u,to;
	ll w;
};
int find(int u)
{
	if(u == find(u))
		return fa[u];
	return u = find(fa[u]);
}
void add(int x,int y)
{
	int ax = find(x),ay = find(y);
	if(ax != ay)
	{
		fa[ay] = ax; 
	}
}
bool cmp(edge x,edge y)
{
	return x.w < y.w;
}
vector<node> a[maxn];
vector<node> b[maxn];
ll c[11];
ll ans = 0;
edge minn[maxn];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	int cnt = 1;
	for(int i = 1; i <= m; i++)
	{
		int u,v;
		ll w;
		cin >> u >> v >> w;
		a[u].push_back(node{v,w});
		a[v].push_back(node{u,w});
		minn[cnt].u = u;
		minn[cnt].to = v;
		minn[cnt++].w = w;
	}
	sort(minn + 1,minn + cnt,cmp);
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
		{
			ll w;
			cin >> w;
			b[i].push_back(node{j,w});
			b[j].push_back(node{i,w});
		}
	}
	for(int i = 1; i < cnt; i++)
	{
		edge x = minn[i];
		cout << x.u <<" " << x.to << " " << x.w << endl;
		cout << fa[x.u] << " " << fa[x.to] << endl;
		if(fa[x.u] != fa[x.to])
		{
			ans += x.w;
			cout << ans << endl;
			add(x.u,x.to);
			cout << fa[x.u] << " " << fa[x.to] << endl;		
		}
	}
	cout << ans << endl;
	fclose(0);
	return 0;
}
