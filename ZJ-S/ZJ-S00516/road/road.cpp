#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1005][1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	for(int i = 0;i<=1005;i++)
	{
		for(int j = 0;j<=1005;j++)
		{
			a[i][j] = 1000000;
		}
	}
	
	scanf("%d %d %d",&n,&m,&k);
	if(m>=1e6)
	{
		printf("%d",0);
	}
	
	for(int i = 1;i<=m;i++)
	{
		int q = 0,w = 0,e = 0;
		scanf("%d %d %d",&q,&w,&e);
		a[q][w] = e;
	}
	
	for(int i = m+1;i<=m+k;++i)
	{
		int t;
		scanf("%d",&t);
		for(int j = 1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]+=t;
		}
	}
	int k = 0;
	for(int f = 1;f<=m+k;++f)
	{
		for(int g = 1;g<=m+k;++g)
		{
			for(int h = 1;h<=m+k;++h)
			{
				if(a[h][g]>a[h][f]+a[f][g])
				{
					a[h][g]=a[h][f]+a[f][g];
					if(a[h][g]>k)
					{
						k = a[h][g];
					}
				}
			}
		}
	}

	printf("%d",k);
	return 0;
	
}
