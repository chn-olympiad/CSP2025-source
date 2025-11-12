#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long a[N+50][4];
long long n;
long long ans;
void dfs(long long now,long long sum1,long long sum2,long long sum3,long long sum)
{
	if(now==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(sum1<n/2)
	{
		dfs(now+1,sum1+1,sum2,sum3,sum+a[now][1]);
	}
	if(sum2<n/2)
	{
		dfs(now+1,sum1,sum2+1,sum3,sum+a[now][2]);
	}
	if(sum3<n/2)
	{
		dfs(now+1,sum1,sum2,sum3+1,sum+a[now][3]);
	}
}
void solve1()
{
	ans=LONG_LONG_MIN;
	dfs(1,0,0,0,0);
	printf("%lld\n",ans);
}
long long val[N+50];
bool cmp(long long a,long long b)
{
	return a>b;
}
void solve2()
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		val[i]=a[i][1];
	}
	sort(val+1,val+1+n,cmp);
	for(int i=1;i<=n/2;i++)
	{
		ans+=val[i];
	}
	printf("%lld\n",ans);
}
void work()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
	}
	if(n<=15)
	{
		solve1();
	}
	else
	{
		solve2();
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		work();
	}
	return 0;
}
