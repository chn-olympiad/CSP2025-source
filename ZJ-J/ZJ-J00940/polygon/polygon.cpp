#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5100],b[5100],ans=0;
const int mod=998244353;
void dfs(int x,int sum,int s,int maxn)
{
	if(sum+b[n]-b[x-1]<=maxn*2) return ;
	if(x>n)
	{
		if(sum>maxn*2&&s>=3) ans=(ans+1)%mod;
		return ;
	}
	dfs(x+1,sum+a[x],s+1,max(maxn,a[x]));
	dfs(x+1,sum,s+1,maxn);
}
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y%2==1) ans=ans%mod*x%mod;
		x=x*x%mod;
		y=y>>1; 
	}
	return ans;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	bool p=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) p=false;
		b[i]=b[i-1]+a[i];
	}
	if(p==false) dfs(1,0,0,0);
	else
	{
		cout<<(qpow(2,n)+mod-1+mod-n+mod-n*(n-1)/2)%mod;
		return 0;
	}
	cout<<ans;
	return 0;
}
