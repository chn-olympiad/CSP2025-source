#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+9;
const int maxnn=2e4+9;
int n,m;
int tmpn;
int k;
int fa[maxn];
int tmpm;
struct edge
{
	int u,v,w;
	bool operator<(const edge b)const 
	{
		return w<b.w;
	};
}e[maxn+maxnn];
int findfa(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=findfa(fa[x]);
}
int ans=0;
int c[maxn];
int tot;
void kruskal()
{
	sort(e+1,e+m+1);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int fx=findfa(e[i].u),fy=findfa(e[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		ans+=e[i].w;
		if(cnt>n) break;
	}
}
int a[11][maxn];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>tmpn>>tmpm>>k;
	m=tmpm;n=tmpn;
	for(int i=1;i<=tmpm;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=tmpn;j++) 
		{
			cin>>a[i][j];
			m++;
			n++;
			e[m]={tmpn+i,j,a[i][j]};
			if(a[i][j]==0) fa[tmpn+i]=j;
		}
	}
	for(int i=1;i<=n;i++) if(!fa[i]) fa[i]=i;
	kruskal();
	cout<<ans<<'\n';
	/*
	for(int i=0;i<(1ll<<k);i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1)))
			{
				m=tm+n;
			}
		}
	}
	*/
	return 0;
}