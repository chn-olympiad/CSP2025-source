#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],tj[501],sum[501],sum1[501];
string s;
long long ans,mod=998244353;
bool pd1,pd2;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	cin>>s;
	pd1=true;
	pd2=true;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
		{
			pd1=false;
		}
		tj[a[i]]++;
	}
	for(i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			pd2=false;
		}
	}
	if(m==n)
	{
		if(pd1==false || pd2==false)
		{
			puts("0");
			return 0;
		}
		else
		{
			ans=1;
			for(i=2;i<=n;i++)
			{
				ans=ans*i%mod;
			}
			cout<<ans;
			return 0;
		}
	}
	else if(m==1)
	{
		long long x=1,cnt=0,mi=1e9;
		sum[0]=tj[0];
		for(i=1;i<=n;i++)
		{
			sum1[i]=sum1[i-1]+s[i]-'0';
			sum[i]=sum[i-1]+tj[i];
			mi=min(mi,(long long)(sum[i-1]-sum1[i]));
			if(mi<0)
			{
				mi=0;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				x=x*min(mi,(long long)(n-i+1));
				x%=mod;
			}
			else
			{
				x=x*min((sum[i-1]-cnt),(long long)(n-i+1));
				cnt++;
				x%=mod;
			}
		}
		ans=1;
		for(i=2;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		cout<<(ans+mod-x)%mod;
	}
	else
	{
		puts("0");
	}
	return 0;
}

