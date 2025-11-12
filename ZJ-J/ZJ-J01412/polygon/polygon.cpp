#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],res[5010];
long long ans,zh[5010];
void dfs(int level,int cnt)
{
	if(level>n)
	{
		if(cnt<3) return;
		int mx=0,sum=0;
		for(int i=1;i<=cnt;i++)
		{
			mx=max(mx,res[i]);
			sum+=res[i];
		}
		if(sum>mx*2) ans=(ans+1)%mod;
		return;
	}
	dfs(level+1,cnt);
	res[cnt+1]=a[level];
	dfs(level+1,cnt+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag)
	{
		zh[3]=n*(n-1)*(n-2)/6;
		zh[3]%=mod;
		for(int i=4;i<=n;i++) zh[i]=(zh[i-1]*(n-i+1)/i)%mod;
		for(int i=3;i<=n;i++) ans=(ans+zh[i])%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}