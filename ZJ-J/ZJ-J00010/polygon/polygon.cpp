#include<bits/stdc++.h>
using namespace std;
int const MOD=998244353;
int n,ans,Max,a[5010],nsum,sum[5010],c[5010],k;
void sol(int x,int step)
{
	if(x>n) return ;
	sol(x+1,step);
	if(step==0) Max=a[x];
	if(sum[n]-sum[x-1]+nsum<=Max*2)
	{
		if(step==0) Max=0;
		return ;
	}
	nsum+=a[x];
	k=x;
	if(nsum>Max*2)
	{
		ans=(ans+c[n-k])%MOD;
	}
	else sol(x+1,step+1);
	if(step==0) Max=0;
	nsum-=a[x];
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1);
	c[0]=1;
	for(int i=1;i<=n;i++)
	  c[i]=c[i-1]*2%MOD;
	for(int i=1;i<=n/2;i++)
	  swap(a[i],a[n-i+1]);
	if(a[1]==1)
	{
		for(int i=1;i<=n-2;i++)
		  for(int j=i+1;j<n;j++)
		    ans+=c[n-j]-1;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	  sum[i]=sum[i-1]+a[i];
	sol(1,0);
	cout<<ans;
}