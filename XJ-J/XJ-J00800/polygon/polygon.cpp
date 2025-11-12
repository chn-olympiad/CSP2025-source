#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=5e2;
long long n,a[N],sum,b[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long tot=1<<n,top=0;
	for(long long i=0;i<=tot;i++)
	{
		long long cnt=0,maxn=0;
		long long p=i;
		for(int j=1;j<=n;j++)
		{
			if(p%2==1)
			{
				cnt+=a[j],maxn=max(maxn,a[j]);
			}
			p/=2;
		}
		if(cnt>maxn*2)
		{
			sum++;
		}
	}
	cout<<sum%mod;
	return 0;
} 
