#include <bits/stdc++.h> 
using namespace std;
int n,m,k; 
struct ff{
	int u;
	int v;
	int w;
}d[1000005];
int c[15][10005];
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&d[i].u,&d[i].v,&d[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c[i][j]);
		}
		if(c[i][0]==0)
		{
			int sum=0;
			for(int j=1;j<=n;j++)
			{
				sum+=c[i][j];
			}
			ans=sum;
		}
	}
	printf("%lld",ans);
	return 0;
}
