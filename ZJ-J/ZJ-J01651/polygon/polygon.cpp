#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5003],mx=-1,ans,sum;
bool f[5003];
void dfs(int bian,int mxs,int sums,int la)
{
	if(bian==0)
	{
		if(mxs<sums-mxs)ans++;
		ans%=mod;
		return;
	}
	if(la>=n)return;
	for(int i=la+1;i<=n;i++)
	{
		if(f[i])continue;
		f[i]=1;
		dfs(bian-1,max(mxs,a[i]),sums+a[i],i);
		f[i]=0;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1)
	{
		for(int i=3;i<=n;i++)
		{
			int X=1,Y=1,Z=1;
			for(int j=n;j>=1;j--)
				X*=j,X%=mod;
			for(int j=i;j>=1;j--)
				Y*=j,Y%=mod;
			for(int j=n-i;j>=1;j--)
				Z*=j,Z%=mod; 
			ans+=X/Y/Z;
		}
		cout<<ans;
		return 0;
	}
	if(n==3)
	{
		if(mx<sum-mx)ans=1;
		else ans=0;
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		for(int i=1;i<=n;i++)f[i]=0;
		dfs(i,0,0,0);
	}
	cout<<ans;
	return  0;
}
