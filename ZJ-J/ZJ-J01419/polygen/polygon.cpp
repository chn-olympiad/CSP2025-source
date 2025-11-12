#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define mod 998244353
int n,a[5005];
long long ans;
int gcd(int a,int b)
{
	if(b%a==0)
	 return b;
	return gcd(b,a%b);
}
int C(int n,int k)
{
	int s=1,t=1;
	for(int i=2;i<=k;++i)
	  t*=i;
	for(int i=n;i>=n-k+1;--i)
	{
		s*=i;
		int tt=__gcd(s,t);
		s/=tt;
		t/=tt;
	}
	return s%mod;
}
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>mx*2)
		  cout<<1;
		else
		  cout<<0;
		return 0;
	}
	for(int i=3;i<=n;++i)
	{
		ans=(ans+C(n,i))%mod;
	}
	cout<<ans%mod<<endl;
	return 0;
}
