#include<bits/stdc++.h>
using namespace std;
long long n,maxx,a[10010],mod=998244353,ans,cnt,dp[10010],cha[10010];
void cx1()
{
	dp[3]=1;
	cha[3]=4;
	for(int i=4;i<=n;i++)
	{
		cha[i]=(cha[i-1]*2+i-1)%mod;
		dp[i]=(dp[i-1]+cha[i-1])%mod;
	}
	cout<<dp[n]<<endl;
	return ;
}
void dfs(long long x,long long sum,long long maxx,long long k)
{
	if(x==n+1)
	{
		if(k>=3&&sum>maxx*2)
		{
			cnt++;
			cnt%=mod;
		}
		return ;
	}
	long long mx=max(maxx,a[x]);
	dfs(x+1,sum+a[x],mx,k+1);
	dfs(x+1,sum,maxx,k);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<=2)
	{
		cout<<0<<endl;
		return 0;
	}
	else if(n<=20)
	{
		dfs(1,0,0,0);
		cout<<cnt<<endl;
		return 0;
	}
	else if(maxx==1)
	{
		cx1();
		return 0;
	}
}//40pts+24pts 已检查
//5
//2 2 3 8 10
//6

//5
//1 2 3 4 5
//9