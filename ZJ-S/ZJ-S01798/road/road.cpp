#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,k,t,a[N],b[N],fa[N];
bool vis[N];
int he[11][10010][2];
struct edge{
	int u,v,w;
}e[N];
bool cmp(edge _1,edge _2)
{
	return _1.w<_2.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void solve()
{
	sort(e+1,e+m+1,cmp);
	int sum=0,cc=0;
	for(int i=0;i<m;i++)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			cc++;
			sum+=e[i].w;
			fa[find(e[i].u)]=find(e[i].v);
		}
		if(cc==n-1) break;
	}
	cout<<sum<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int mx=0;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
		for(int j=1;j<=n;j++)
		{
			cin>>b[j];
			mx=max(mx,b[i]);
		}
	}
	if(mx==0&&k!=0) cout<<0;
	else solve();
	return 0;
	
}

