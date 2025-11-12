#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int K=20;
int kkk,T,n,m1,k,c[K],a[K][N],fa[N];
long long ww,mi=1e18;
bool ff[N];
struct node
{
	int u,v,w;
}m[3*N];
bool cmp(node x,node y){return x.w<y.w;}
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void uunion(int u,int v)
{
	int x=find(u),y=find(v);
	fa[y]=x;
}
void zxscs(int kkk)
{
	long long SCC=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(m+1,m+1+kkk,cmp);
	for(int i=1;i<=kkk;i++)
	{
		if(find(m[i].u)!=find(m[i].v))
		{
			uunion(m[i].u,m[i].v);
			SCC+=m[i].w;
		}
	}
	mi=min(mi,SCC+ww);
}
void dfs(int step)
{
	if(step==k)
	{
		ww=0;kkk=m1;
		for(int i=1;i<=k;i++)
		{
			if(ff[i]==1) ww+=c[i];
			for(int u=1;u<=n;u++)
				for(int v=1;v<=n;v++)
				{
					if(u!=v)
					{
						m[++kkk].u=u,m[kkk].v=v,m[kkk].w=a[i][u]+a[i][v];
						m[++kkk].u=v,m[kkk].v=u,m[kkk].w=a[i][u]+a[i][v];						
					}
				}
		}
		zxscs(kkk);
		return ;
	}
	ff[step+1]=1;
	dfs(step+1);
	ff[step+1]=0;
	dfs(step+1);
}
int main()
{
  	freopen("road.in","r",stdin);
  	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m1>>k;
	for(int i=1;i<=m1;i++)
	{
		cin>>m[i].u>>m[i].v>>m[i].w;
		m[m1+i].v=m[i].u;
		m[m1+i].u=m[i].v;
		m[m1+i].w=m[i].w;		
	}
	m1*=2;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	dfs(0);
	cout<<mi;
	return 0;
}

