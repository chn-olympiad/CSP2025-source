#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int dp[5005*5005+5];
int s[5005];
long long calc(long long n)
{
	long long cnt=0;
	for(long long i=n;i;i>>=1)
	{
		if((i&1)) cnt++;
	}
	return cnt;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	  cin>>a[i];
	long long ans=0;
	for(long long j=1;j<(1ll<<n);j++)
	{
		if(calc(j)<3) continue;
		long long maxlen=0,sum=0;
		for(long long i=1;i<=n;i++)
		{
			if((j&(1ll<<(i-1ll)))==0) continue;
			sum+=a[i];
			maxlen=max(maxlen,a[i]);
		}
		if(maxlen*2<sum) ans++,ans%=998244353;
	}
	cout<<ans;
	return 0;
}
