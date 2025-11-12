#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5;
const int M=1e6+6;
ll dp[N][N];
ll last[N][N];
struct node
{
	ll x1,x2,x3;
};
node a[M]; 
bool cmp1(node x,node y)
{
	return x.x1>y.x1;
}
bool cmp2(node x,node y)
{
	return abs(x.x1-x.x2)>abs(y.x1-y.x2);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	while (t--)
	{
		memset(dp,0,sizeof(dp));
		memset(last,0,sizeof(last));
		memset(a,0,sizeof(a));
		ll n;
		bool b=1;
		scanf("%lld",&n);
		for (ll i = 1;i <= n;i++)
		{
			scanf("%lld%lld%lld",&a[i].x1,&a[i].x2,&a[i].x3);
			
			if (a[i].x2!=0)
			{
				b=0;
			}
			
		}
		if (n>200)
		{
			if (b)
			{
				ll asn=0;
				sort(a+1,a+n+1,cmp1);
				for (ll i = 1;i <= n/2;i++)
				{
					asn+=a[i].x1;
				}
				printf("%lld\n",asn);
			}
			else
			{
				ll t1=0,t2=0;
				ll asn=0;
				sort(a+1,a+n+1,cmp2);
				for (ll i = 1;i <= n;i++)
				{
					if (a[i].x1>a[i].x2)
					{
						if (t1<=n/2)
						{
							t1++;
							asn+=a[i].x1;
						}
						else
						{
							asn+=a[i].x2;
						}
					}
					else
					{
						if (t2<=n/2)
						{
							t2++;
							asn+=a[i].x2;
						}
						else
						{
							asn+=a[i].x1;
						}
					}
				}
				printf("%lld\n",asn); 
			}
			continue;
		}
		for (ll i = 1;i <= n;i++)
		{
			for (ll j = 0;j <= n/2;j++)
			{
				for (ll u = 0;u <= n/2;u++)
				{
					if (i-u-j>n/2||i-j-u<0)
					{
						continue;
					}
					if (j>0)
					{
						dp[j][u]=max(dp[j][u],last[j-1][u]+a[i].x1);
					}
					if (u>0)
					{
						dp[j][u]=max(dp[j][u],last[j][u-1]+a[i].x2);
					}
					if (n-u-j>0)
					{
						dp[j][u]=max(dp[j][u],last[j][u]+a[i].x3); 
					}
				}
			}
			memcpy(last,dp,sizeof(last));
			memset(dp,0,sizeof(dp));
		}
		ll ans=-1;
		for (ll j = 0;j <= n/2;j++)
		{
			for (ll u = 0;u <= n/2;u++)
			{
				if (n-u-j>n/2||n-j-u<0)
				{
					continue;
				}
				ans=max(ans,last[j][u]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

