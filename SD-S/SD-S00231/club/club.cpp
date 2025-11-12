#include<iostream>
#include<algorithm>
using namespace std;
int t,n,ai,bi,ci,acnt,bcnt,ccnt;
long long ans;
int jy[100010];
struct edge
{
	int f,s,t;
	long long ans;
} dp[100010][5];
struct node
{
	int f,s,t;
} a[100010];
bool cmp(node x,node y)
{
	if((x.f+x.s+x.t)<(y.f+y.s+y.t))
	{
		return (x.f+x.s+x.t)>(y.f+y.s+y.t);
	}
	if(x.f<y.f)
	{
		return x.f>y.f;
	}
	if(x.s<y.s)
	{
		return x.s>y.s;
	}
	return x.t>y.t;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int xi=1;xi<=t;xi++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].f,&a[i].s,&a[i].t);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=0;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				dp[i][j].f=0;
				dp[i][j].s=0;
				dp[i][j].t=0;
				dp[i][j].ans=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(j==1)
				{
					if((dp[i-1][1].f<(n/2))&&(dp[i-1][1].ans+a[i].f>dp[i][j].ans))
					{
						dp[i][j]=dp[i-1][1];
						dp[i][j].ans=dp[i-1][1].ans+a[i].f;
						dp[i][j].f++;
					}
					if((dp[i-1][2].f<(n/2))&&(dp[i-1][2].ans+a[i].f>dp[i][j].ans))
					{
						dp[i][j]=dp[i-1][2];
						dp[i][j].ans=dp[i-1][2].ans+a[i].f;
						dp[i][j].f++;
					}
					if((dp[i-1][3].f<(n/2))&&(dp[i-1][3].ans+a[i].f>dp[i][j].ans))
					{
						dp[i][j]=dp[i-1][3];
						dp[i][j].ans=dp[i-1][3].ans+a[i].f;
						dp[i][j].f++;
					}
				}
				else if(j==2)
				{
					if((dp[i-1][1].s<(n/2))&&(dp[i-1][1].ans+a[i].s>dp[i][j].ans))
					{
						dp[i][j]=dp[i-1][1];
						dp[i][j].ans=dp[i-1][1].ans+a[i].s;
						dp[i][j].s++;
					}
					if((dp[i-1][2].s<(n/2))&&(dp[i-1][2].ans+a[i].s>dp[i][j].ans))
					{
						dp[i][j]=dp[i-1][2];
						dp[i][j].ans=dp[i-1][2].ans+a[i].s;
						dp[i][j].s++;
					}
					if((dp[i-1][3].s<(n/2))&&(dp[i-1][3].ans+a[i].s>dp[i][j].ans))
					{
						dp[i][j]=dp[i-1][3];
						dp[i][j].ans=dp[i-1][3].ans+a[i].s;
						dp[i][j].s++;
					}
				}
				else
				{
					if((dp[i-1][1].t<(n/2))&&(dp[i-1][1].ans+a[i].t>dp[i][j].ans))
					{
						dp[i][j]=dp[i-1][1];
						dp[i][j].ans=dp[i-1][1].ans+a[i].t;
						dp[i][j].t++;
					}
					if((dp[i-1][2].t<(n/2))&&(dp[i-1][2].ans+a[i].t>dp[i][j].ans))
					{
						dp[i][j]=dp[i-1][2];
						dp[i][j].ans=dp[i-1][2].ans+a[i].t;
						dp[i][j].t++;
					}
					if((dp[i-1][3].t<(n/2))&&(dp[i-1][3].ans+a[i].t>dp[i][j].ans))
					{
						dp[i][j]=dp[i-1][3];
						dp[i][j].ans=dp[i-1][3].ans+a[i].t;
						dp[i][j].t++;
					}
				}
			}
		}
		if(dp[n][1].ans>dp[n][2].ans&&dp[n][1].ans>dp[n][3].ans)
		{
			ans=dp[n][1].ans;
		}
		else if(dp[n][2].ans>dp[n][3].ans)
		{
			ans=dp[n][2].ans;
		}
		else
		{
			ans=dp[n][3].ans;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
