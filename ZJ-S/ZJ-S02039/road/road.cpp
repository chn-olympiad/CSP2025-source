#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e4+20,M=1e6+10;
int n,m,k,c[12],f[12][N],fa[N];
long long ans=1e18;
bool mark[12];
struct node
{
	int x,y,z;
}e[M],tmp[M<<1];
bool cmp(node a,node b)
{
	return a.z<b.z;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
long long kruskal(int town)
{
	long long sum=0;
	int num=0;
	for(int i=1;i<=m;i++)
	  tmp[++num]=e[i];
	for(int i=1;i<=k;i++)
	  if(mark[i])
	    for(int j=1;j<=n;j++)
	      tmp[++num]={n+i,j,f[i][j]};
	sort(tmp+1,tmp+num+1,cmp);
	for(int i=1;i<=n+town;i++)
	  fa[i]=i;
	for(int i=1;i<=num;i++)
	{
		int a=find(tmp[i].x),b=find(tmp[i].y);
		if(a!=b)
		{
			fa[a]=b;
			sum+=tmp[i].z;
		}
	}
	return sum;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	  scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		  scanf("%d",&f[i][j]);
	}
	for(int i=0;i<(1<<k);i++)
	{
		int t=i,j=0,town=0;
		long long sum=0;
		memset(mark,0,sizeof(mark));
		while(t>0)
		{
			j++;
			if(t&1)
			{
				town++;
				mark[j]=1;
				sum+=c[j];
			}
			t>>=1;
		}
		ans=min(ans,sum+kruskal(town));
	}
	printf("%lld",ans);
	return 0;
}
//chzx_lfw AK IOI!!!!!
