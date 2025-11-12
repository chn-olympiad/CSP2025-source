#include<bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define mem(s,t) memset(s,t,sizeof s)
#define ll long long
#define ld long double
#define endl '\n'
using namespace std;
const int N=5e4+5;
struct edge{int u,v,w;}g[N];
int n,m,h[N],idx,k,f[N],ans;
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void kruskal()
{
	rep(i,1,m)
	{
		int u=g[i].u,v=g[i].v,fu=find(u),fv=find(v);
		if(fu!=fv)
		{
			f[fu]=fv;
			ans+=g[i].w;
		}
	}
	cout<<ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	rep(i,1,n)f[i]=i;
	rep(i,1,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[i]={u,v,w};
	}
	sort(g+1,g+m+1,cmp);
	kruskal();
	return 0;
}
