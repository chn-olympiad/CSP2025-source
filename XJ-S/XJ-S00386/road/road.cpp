#include<cstdio>
int n,m,k,r[1000010],a,b,c; 
int main()
{
	int i,j;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&r[i]);
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",&a);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-1;j++)
		{
			if(r[j]>r[j+1])
			{
				c=r[j];r[j]=r[j+1];r[j+1]=c;
			}
		}
	}
	int ans=0;
	for(i=1;i<=m-1;i++)
	{
		ans=ans+r[i];
	}
	printf("%d",ans);
	return 0;
 } 
