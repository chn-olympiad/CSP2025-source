#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],s,sum,MAX,ss,mod=998244353;
void f(long long k,long long sum,long long ans,long long MAX)
{
	if(k==n+1)
	{
		if(ans<3) return;
		if(sum>MAX+MAX) s=(s+1)%mod;
		return;
	}
	f(k+1,sum,ans,MAX);
	f(k+1,sum+a[k],ans+1,a[k]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i],ss+=a[i];
	sort(a+1,a+n+1);
	if(a[n]==1) cout<<(1<<n)-1-n-n*(n-1)/2<<endl;
	else if(n<=20)
	{
		f(1,0,0,0);
	    cout<<s<<endl;
	}
	else
	{
		long long b[ss+10];
		for(long long i=1;i<=ss;i++) b[i]=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=a[i]+1;j<=MAX;j++)sum+=b[j];
			sum%=mod;
			for(long long j=1;j<=MAX;j++)
			{
				b[a[i]+j]+=b[j];
				b[a[i]+j]%=mod;
			}
			for(long long j=1;j<i;j++) b[a[j]+a[i]]++;
			MAX+=a[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
