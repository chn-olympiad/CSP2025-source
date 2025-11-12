#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N=1e4+20;
const int M=1e6+20;
const int inf=0x3f3f3f3f3f3f3f3f;
struct Edge
{
	int u,v,w;
}e[M],t[N];
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int n,m,k;
int ans=inf;
int fa[N];
int fifa(int x)
{
	return (x==fa[x]?x:fa[x]=fifa(fa[x]));
}
void kru()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	int tot=0,cnt=0;
	for(int i=1;i<=m;i++)
	{
		int u=fifa(e[i].u),v=fifa(e[i].v);
		if(u==v) continue;
		fa[u]=v;
		tot+=e[i].w,t[++cnt]=e[i];
		if(cnt==n-1) break;
	}
	ans=tot;
}
int c[20];
Edge a[11][N];
int pos[20];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			a[i][j]={n+i,j,x}; 
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	sort(e+1,e+m+1,cmp);
	kru();
	for(int s=1;s<(1<<k);s++)
	{
		int num=0,tot=0,cnt=0;
		for(int i=1;i<=k;i++) pos[i]=(s&(1<<(i-1)))?1:n+1,num+=(pos[i]==1),cnt+=(pos[i]==1)*c[i];
		for(int i=1;i<=n+10;i++) fa[i]=i;
		int p=1;
		while(tot!=n+num-1)
		{
			Edge x={inf,inf,inf};
			if(p<=n-1) x=t[p];
			int po=0;
			for(int i=1;i<=k;i++)
			{
				if(pos[i]<=n)
				{
					if(a[i][pos[i]].w<x.w) x=a[i][pos[i]],po=i;
				}
			}
			if(po) pos[po]++;
			else p++;
			cnt+=x.w;
			tot++;
			fa[fifa(x.u)]=fifa(x.v);
			if(tot==n+num-1) break;
			while(p<=n-1&&fifa(t[p].u)==fifa(t[p].v)) p++;
			for(int i=1;i<=k;i++)
			{
				while(pos[i]<=n&&fifa(a[i][pos[i]].u)==fifa(a[i][pos[i]].v)) pos[i]++;
			}
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}
