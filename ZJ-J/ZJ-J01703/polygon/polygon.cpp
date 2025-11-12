#include<bits/stdc++.h>
using namespace std;
const long long N=5010,MOD=998244353;
long long n,a[N],ans,cnt/*,f[N*N],b[N]*/;
void dfs(long long ni,long long ns,long long tot,bool qu)
{
	if(ns>=3&&qu==1)
	{
		ans=(ans+1)%MOD;
//		for(int i=1;i<=ns;i++) cout<<b[i]<<" ";
//		cout<<endl;
	}
	if(ni>=n) return ;
	if(a[ni+1]<tot)
	{
//		b[ns+1]=a[ni+1];
		dfs(ni+1,ns+1,tot+a[ni+1],1);
	}
	else
	{
//		b[ns+1]=a[ni+1];
		dfs(ni+1,ns+1,tot+a[ni+1],0);
	}
	dfs(ni+1,ns,tot,0);
	return ;
}
int main()
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
		if(a[i]==1) cnt++;
	}
	if(cnt==n)
	{
		long long m1=1,m2=1*2;
		for(int i=2;i<=n;i++) m1=m1*i;
		for(int i=3;i<n;i++)
		{
			m2*=i;
			ans=(__int128)(ans+(m1/m2)/(n-i))%MOD;
		}
		ans=(ans+1)%MOD;
	}
	else dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
