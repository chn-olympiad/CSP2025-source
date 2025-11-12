#include<bits/stdc++.h>
#define debug cout << "Debug" << endl;
using namespace std;
struct edge
{
	int u,v;
	long long w;
	int tag;
}e[10000001];
struct node
{
	long long x;
	int tag;
}g[10001][10001]; 
int n,m,k,u,v,a[10001],x,fa[10001],l = 0,cnt,d[11],flag[11];
long long w,ans;
int find(int x) {return (fa[x] == x ? x : fa[x] = find(fa[x]));}
int main()
{
	freopen("road2.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(g,0x3f,sizeof(g));
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++) g[i][i].x = 0,fa[i] = i;
	for(int i = 1;i <= m;i++) cin >> u >> v >> w,g[v][u].x = g[u][v].x = w,g[u][v].tag = g[v][u].tag = 0;
	for(int z = 1;z <= k;z++)
	{
		cin >> d[z];
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++) for(int j = i + 1;j <= n;j++)
		{
			if(g[i][j].tag == 0x3f3f3f3f) g[i][j].tag = 0;
			if(g[i][j].x + d[g[i][j].tag] >= a[i] + a[j] + d[z]) g[i][j].x = a[i] + a[j],g[i][j].tag = z;
		}
	}
	for(int i = 1;i <= n;i++) for(int j = i + 1;j <= n;j++) e[++l] = {i,j,g[i][j].x,g[i][j].tag};
	sort(e + 1,e + l + 1,[](edge a,edge b){return (a.w < b.w);});
	for(int i = 1;i <= l;i++)
	{
		int u = e[i].u,v = e[i].v,w = e[i].w,tag = e[i].tag;
		int fu = find(u),fv = find(v);
		if(fu != fv) fa[fu] = fv,ans += w,cnt++,flag[tag]++;
		if(cnt == n - 1) break;
	}
	for(int i = 1;i <= k;i++) if(flag[i] != 0) ans += d[i];
	cout << ans << endl;
	return 0;
}
