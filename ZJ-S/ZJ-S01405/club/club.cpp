#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long a,b,c;
}a[100010];
long long t,n,maxx;
bool f;
void dfs(long long x,long long sum,long long cnt1,long long cnt2,long long cnt3)
{
	if(x==n+1)
	{
		maxx=max(maxx,sum);
		return ;
	}
	if(cnt1!=n/2) dfs(x+1,sum+a[x].a,cnt1+1,cnt2,cnt3);
	if(cnt2!=n/2) dfs(x+1,sum+a[x].b,cnt1,cnt2+1,cnt3);
	if(cnt3!=n/2) dfs(x+1,sum+a[x].c,cnt1,cnt2,cnt3+1);
	return ;
}
bool cmp(node x,node y)
{
	return x.a>y.a;
}
void solve()
{
	maxx=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
		if(a[i].b!=0||a[i].c!=0) f=1;
	}
	if(!f)
	{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)
			maxx+=a[i].a;
		printf("%lld\n",maxx);
		return ;
	}
	dfs(1,0,0,0,0);
	printf("%lld\n",maxx);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
		solve();
	return 0;
}
