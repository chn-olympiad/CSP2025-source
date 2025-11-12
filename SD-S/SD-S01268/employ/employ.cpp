#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=520;
const int mod=998244353;
ll n,m,ans;
int c[N];
string s;
bool f[N];
void dfs(int step,int cnt,int pe)
{
	if(pe<m)return;
	if(step==n+1)
	{
		ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			if(s[step]=='0')dfs(step+1,cnt+1,pe-1);
			if(s[step]=='1')
			{
				if(cnt>=c[i])dfs(step+1,cnt+1,pe-1);
				else dfs(step+1,cnt,pe);
			}
			f[i]=0;
		}
	}
}
void find(int step,int cnt)
{
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			if(s[step]=='0')find(step+1,cnt+1);
			if(s[step]=='1')
			{
				if(cnt>=c[i])find(step+1,cnt+1);
				else
				{
					ll sum=1;
					for(ll j=1;j<=n-step;j++)sum=sum*j%mod;
					ans=(ans+sum)%mod;
					f[i]=0;
					continue;
				}
			}
			f[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	if(m==1)
	{
		find(1,0);
		printf("%lld",ans);
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				printf("0");
				return 0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!c[i])
			{
				printf("0");
				return 0;
			}
		}
		ans=1;
		for(ll i=1;i<=n;i++)ans=ans*i%mod;
		printf("%lld",ans);
		return 0;
	}
    dfs(1,0,n);
	cout<<ans;
	return 0;
}
