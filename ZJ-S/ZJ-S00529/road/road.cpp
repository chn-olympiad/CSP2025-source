//100
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
long long f[10005][10005],dis[10005],ans;
int n,m,t0t,flag[10005],cnt=1;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t0t);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int t0,t1;long long t2;
		scanf("%d%d%lld",&t0,&t1,&t2);
		f[t0][t1]=min(f[t0][t1],t2);
		f[t1][t0]=min(f[t1][t0],t2);
	}
	for(int i=1;i<=t0t;i++)
	{
		long long z,ta[10004];
		scanf("%lld",&z);
		for(int j=1;j<=n;j++)
		{
			int t0;
			scanf("%lld",&ta[j]);
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				f[j][k]=min(f[j][k],ta[j]+ta[k]+z);
				f[k][j]=min(f[k][j],ta[j]+ta[k]+z);
			}
		}
	}
	flag[1]=1;
	for(int i=2;i<=n;i++)
	{
		dis[i]=f[1][i];
	}
	while(cnt<n)
	{
		int minn=inf,p;
		for(int i=1;i<=n;i++)
		{
			if(dis[i]<minn&&!flag[i])
			{
				minn=dis[i];
				p=i;
			}
		}
		ans+=minn;
		flag[p]=1;
		cnt++;
		for(int i=1;i<=n;i++)
		{
			dis[i]=min(dis[i],f[p][i]);
		}
	}
	printf("%lld",ans);
	return 0;
}