#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll mod=998244353;
const int N=600;
int n,m,a[N],f;
char s[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)if(!s[i])f=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==1)
	{
		if(s[1]=='1')
		{
			ll sum=1;
			for(ll i=n;i>=2;i--)
			sum=sum*i%mod;
			printf("%lld",sum);
		}
		else if(s[1]=='0')
		{
			int pp=0,cnt=0;
			ll sum=1; 
			for(int i=2;i<=n;i++)
			{
				if(s[i]=='1')
					{pp=i;break;}	
			}
			for(int i=1;i<=n;i++)
			if(a[i]>pp)cnt++;
			for(ll i=cnt;i>=2;i--)
				sum=sum*i%mod;
			printf("%lld",sum);
		}
		return 0;
	}
	if(m==n)
	{
		ll cnt=0,tot=0;
		for(int i=1;i<=n;i++) 
			if(s[i]=='0')cnt++;
		for(int i=1;i<=n;i++)
			if(s[i]<=cnt)tot++;
			ll sum=1;
			for(ll i=1;i<=n-min(tot,cnt);i++)
			sum=sum*i%mod;
			printf("%lld",sum);
		return 0;
	}
	if(!f)
	{
		ll cnt=0;
		for(int i=1;i<=n;i++)
			if(a[i]==0)cnt++;
		if(m+cnt>n)
		{
			if(m+1==n)
			{
				ll sum=1;
				for(int i=n-1;i>=1;i--)
				sum=sum*i%mod;
				sum=sum*cnt%mod;
				printf("%lld",sum);
			}
			else printf("0");
			return 0;
		}
		if(m+cnt<=n)
		{
			ll sum=1;
			for(int i=n;i>=1;i--)
			sum=sum*i%mod;
			printf("%lld",sum);
		}
	
	}
 	return 0;
}

