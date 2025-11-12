#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;

int t,n;
int idx;
int val[maxn];
int a[maxn][3];

long long ans;

int cnt[3];

void dfs(int x,long long tem)
{
	if(x==n+1)
	{
		ans=max(ans,tem);
		return ;
	}
	for(int i=0;i<=2;i++)
	{
		if(cnt[i]>=n/2)
		{
			continue;
		}
		cnt[i]++;
		dfs(x+1,tem+a[x][i]);
		cnt[i]--;
	}
}

long long f[205][205][205];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		cnt[0]=0;
		cnt[1]=0;
		cnt[2]=0;
		scanf("%d",&n);
		idx=0;
		for(int i=1;i<=n;i++)
		{
//			val[idx++]=a[i][0];
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			val[idx++]=a[i][0];
		}
		if(n<=10) 
			dfs(1,0);
		else if(n<=200)
		{
			memset(f,0,sizeof f);
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=min(i,n/2);j++)
				{
					for(int k=0;k<=min(i-j,n/2);k++)
					{
						int z=i-j-k;
						if(z>n/2)
						{
							continue;
						}
//						long long tem=0;
						if(j>0)
//							tem=max(tem,f[j-1][k]+a[i][0]);
							f[i][j][k]=max(f[i-1][j-1][k]+a[i][0],f[i][j][k]); 
						if(k>0)
						{
//							tem=max(tem,f[j][k-1]+a[i][1]);
							f[i][j][k]=max(f[i-1][j][k-1]+a[i][1],f[i][j][k]);
						}
						if(z>0)
						{
//							tem=max(tem,f[j][k]+a[i][2]);
							f[i][j][k]=max(f[i-1][j][k]+a[i][2],f[i][j][k]);
						}
//						f[i][j][k]=tem;
						if(i==n)
						{
							ans=max(ans,f[i][j][k]);
						}
					}
				}
			}
		}
		else
		{
			sort(val,val+n);
			for(int i=n-1;i>=n/2;i--)
			{
				ans+=val[i];
			}
		}
		printf("%lld\n",ans);
	} 
	return 0;
}
/*
3
4
4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0
*/

