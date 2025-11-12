#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5005],sum,maxx,ans,pre[5005];
bool flag=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	long long now=a[1];
	for(int i=2;i<=n;i++) if(a[i]!=now) flag=0;
	if(flag)
	{
		for(int i=3;i<=n;i++)
		{
			long long x=1,y=1,z=1;
			for(int j=n;j>=2;j--) x=x*j%mod;
			for(int j=i;j>=2;j--) y=y*j%mod;
			for(int j=n-i;j>=2;j--) z=z*j%mod;
			ans=(ans+x/(y*z))%mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	maxx*=2;
	if(sum>maxx) ans++;
	for(int i=3;i<=n-1;i++)
	{
		int s=pre[i],d=a[i];
		for(int j=i;j<=n;j++)
		{
			if(s<=d*2)
			{
				if(j==n) break;
				for(int h=j-i+2;h<=j;h++)
				{
					int ss=s,dd=d;
					ss=ss-a[h]+a[j+1];
					dd=a[j+1];
					if(ss>dd*2) ans++;
				}
				s=s-a[j-i+1]+a[j+1];
				d=a[j+1];
			}
			else
			{
				ans++;
				if(j==n) break;
				for(int h=j-i+2;h<=j;h++)
				{
					int ss=s,dd=d;
					ss=ss-a[h]+a[j+1];
					dd=a[j+1];
					if(ss>dd*2) ans++;
				}
				s=s-a[j-i+1]+a[j+1];
				d=a[j+1];
			}
			ans%=mod;
		}
	}
	cout<<ans%mod<<"\n";
	return 0;
}
