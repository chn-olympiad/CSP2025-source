#include <bits/stdc++.h>
#define int long long
using namespace std;
int fa[5000006],n,m,k,u,v,w,a[20][5000006],f,c[20],ans,sum;
vector <int>dp[20];
struct node{
	int u,v,w;
	bool friend operator < (node a,node b)
	{
		return a.w<b.w;
	}
}e[5000006];
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void For_k_0()
{
	ans=0;
	int p=m;
	for(int i=1;i<=p;i++)
	{
		int x=e[i].u,y=e[i].v,w=e[i].w;
		int fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			fa[fx]=fy;
			ans+=w;
		}
	}
	printf("%lld",ans);
	exit(0);
}
void For_A()
{
	ans=0;
	int p=m;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]!=0)
			{
				for(auto k:dp[i])
				{
					e[++p]={j,k,a[i][j]};
				}
			}
		}
	}
	sort(e+1,e+p+1);
	for(int i=1;i<=p;i++)
	{
		int x=e[i].u,y=e[i].v,w=e[i].w;
		int fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			fa[fx]=fy;
			ans+=w;
		}
	}
	printf("%lld",ans);
	exit(0);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	f=0;	
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i])f=1;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
			if(a[i][j]==0)dp[i].push_back(j);
		}
	}
	sort(e+1,e+m+1);
	if(!f)
	{
		For_A();
		return 0;
	}
	if(k==0){
		For_k_0();
		return 0; 
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
