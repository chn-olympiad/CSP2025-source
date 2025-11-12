#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100010][4],ans,b[100010],c[100010];
int cmp(long long x,long long y)
{
	return x>y;
}
void dfs(int sum1,int sum2,int sum3,long long sum,int step)
{
	ans=max(sum,ans);
	if(step==n+1) return ;
	if(sum1+1<=n/2)
	{
		dfs(sum1+1,sum2,sum3,sum+a[step][1],step+1);
	}
	if(sum2+1<=n/2)
	{
		dfs(sum1,sum2+1,sum3,sum+a[step][2],step+1);
	}
	if(sum3+1<=n/2)
	{
		dfs(sum1,sum2,sum3+1,sum+a[step][3],step+1);
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%lld",&a[i][j]);
		if(n<=30)
		{
			dfs(0,0,0,0,1);
			printf("%lld\n",ans);
			continue;
		}
		else
		{
			bool flag1=0,flag2=0;
			for(int i=1;i<=n;i++)
			{
				b[i]=a[i][1];
				c[i]=a[i][2];
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i][2]||a[i][3]) flag1=1;
				if(a[i][3]) flag2=1;
			}
			if(!flag1)
			{
				sort(b+1,b+n+1,cmp);
				for(int i=1;i<=n/2;i++)
					ans+=b[i];
				printf("%lld\n",ans);
				continue;
			}
		}
	}
	return 0;
}
