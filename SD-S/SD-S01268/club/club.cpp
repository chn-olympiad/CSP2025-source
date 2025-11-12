#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pii;
const int N=1e5+10;
int n,sx;
ll ans,a[N][5],dp[210][110][5];
bool flaga,flagb;
pii p[N];
void dfs(int step,ll sum,int sum1,int sum2,int sum3)
{
	if(sum1>sx or sum2>sx or sum3>sx)return;
	if(step==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	dfs(step+1,sum+a[step][1],sum1+1,sum2,sum3);
	dfs(step+1,sum+a[step][2],sum1,sum2+1,sum3);
	dfs(step+1,sum+a[step][3],sum1,sum2,sum3+1);
}
bool cmp(ll x,ll y)
{
	return x>y;
}
bool cmp1(pii x,pii y)
{
	return abs(x.first-x.second)>abs(y.first-y.second);
}
void solve()
{
	scanf("%d",&n);
	ans=0;
	sx=n/2;
	flaga=flagb=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			scanf("%lld",&a[i][j]);
		}
		if(a[i][2] or a[i][3])flaga=1;
		if(a[i][3])flagb=1;
	}
	if(!flaga)
	{
		vector<ll>v;
		for(int i=1;i<=n;i++)v.push_back(a[i][1]);
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<sx;i++)ans+=v[i];
		printf("%lld\n",ans);
		return;
	}
	if(!flagb)
	{
		for(int i=1;i<=n;i++)p[i]={a[i][1],a[i][2]};
		sort(p+1,p+1+n,cmp1);
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt1==sx)ans+=p[i].second;
			else if(cnt2==sx)ans+=p[i].first;
			else if(p[i].first>p[i].second)cnt1++,ans+=p[i].first;
			else if(p[i].second>p[i].first)cnt2++,ans+=p[i].second;
			else if(p[i].first==p[i].second)
			{
				if(cnt1>cnt2)cnt2++,ans+=p[i].second;
				else if(cnt2>cnt1)cnt1++,ans+=p[i].first;
				else cnt1++,ans+=p[i].first;
			}
		}
		printf("%lld\n",ans);
		return;
	}
	ans=0;
	dfs(1,0,0,0,0);
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
/*
看着像个DP 但不好表示 因为有n/2这个限制 
*/
