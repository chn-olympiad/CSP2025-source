#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,ans;
int a[25];
void dfs(int temp,int cnt,int sum,int maxx)
{
	if(temp==n+1)
	{
		if(cnt>=3 && sum>maxx*2)
		{
			ans++;
			ans%=MOD;
		}
		return;
	}
	dfs(temp+1,cnt+1,sum+a[temp],max(maxx,a[temp]));
	dfs(temp+1,cnt,sum,maxx);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=20)
	{
		dfs(1,0,0,-1);
		cout<<ans<<'\n';
	}
	else
	{
		//((1<<n)-n-n*(n-1)/2)-1;
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=2;
			ans%=MOD;
		}
		ans=(ans-n+MOD)%MOD;
		ans=(ans-((n-1)*n/2)%MOD+MOD)%MOD;
		cout<<(ans-1+MOD)%MOD;
	}
	return 0;
}

