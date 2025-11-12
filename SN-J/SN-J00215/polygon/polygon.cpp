#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5005, mod=998244353;
int n, a[maxn], mx, s;
bool flag=0;
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) flag=1;
		mx=max(mx, a[i]);
		s+=a[i];
	}
	if(n<=20)
	{
		int ans=0;
		for(int i=0;i<=(1<<n)-1;i++)
		{
			int sum=0, maxx=0;
			for(int j=1;j<=n;j++)
			{
				if(i>>(j-1)&1)
				{
					maxx=max(maxx, a[j]);
					sum+=a[j];
				}
			}
			if(sum>maxx*2)
			{
				ans=(ans+1)%mod;
			}
		}
		cout<<ans;
		return 0;
	}
	if(flag==0)
	{
		cout<<(qpow(2, n)-(1+n+(n-1)*n/2)+mod)%mod;
		return 0;
	}
	cout<<0;
	return 0;
}
