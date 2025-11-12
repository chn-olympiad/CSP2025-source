#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],s[5005],ans=0,t=0,f[505][50005],g[505][50005];
int ksm(int x,int y)
{
	int s=1;
	while(y)
	{
		if(y%2==1) s=(s*x)%mod;
		y/=2;
		x=(x*x)%mod;
	}
	return s;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t=max(t,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=500)
	{
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		f[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=s[i];j++)
			{
				f[i][j]=f[i-1][j];
				if(j>=a[i]) f[i][j]=(f[i][j]+f[i-1][j-a[i]])%mod;
			}
		for(int i=3;i<=n;i++)
			for(int j=a[i]*2+1;j<=s[i];j++)
			{
				g[i][j]=(g[i][j]+f[i-1][j-a[i]])%mod;
				ans=(ans+g[i][j])%mod;
			}
		cout<<ans<<endl;
		return 0;
	}
	if(t==1)
	{
		ans=0;
		int s=(n*(n-1))%mod,s1=2;
		for(int i=3,j=n-2;i<=n;i++,j--)
		{
			s1=(s1*i)%mod;
			s=(s*j)%mod;
			ans=(ans+(s*ksm(s1,mod-2))%mod)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}/*
xie xie CCF
xie xie CCF
xie xie CCF
CCF wo ai ni
wo zong yu zai kao shi jie shu qian 20 minutes ba n<=500 de dp tiao dui le
*/
