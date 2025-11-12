#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int ans=0;
const int N=5e2+10;
int sta[N],rg[N],d[N],c[N],sum[N],mp[N];
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
		{
			res=(res*x)%mod;
		}
		y>>=1;
		x=(x*x)%mod;
	}
	return res;
}
int A(int x,int y)
{
	return sta[x]*qpow(sta[x-y],mod-2)%mod;
}
int n,m;
int tot=0;
void dfs(int now,int run)
{
	if(now==n+1&&run<=m)
	{
		for(int i=1;i<=tot;i++)
		{
			ans=(ans+A(rg[i],d[i]))%mod;
		}
	}
	for(int i=0;i<=tot;i++)
	{
		if(sum[mp[i]]>c[now])
		{
			if(d[i]>=rg[i])
			{
				continue;
			}
			d[i]++;
			dfs(now+1,run+1);
			d[i]--;
		}
		else
		{
			if(d[i]>=rg[i])
			{
				continue;
			}
			d[i]++;
			dfs(now+1,run);
			d[i]--;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		sta[i]=(sta[i-1]*i)%mod;
	}
	cin>>s;
	s=" "+s;
	int las=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
		sum[i]=sum[i-1]+s[i]-'0';
		if(c[i]=='1')
		{
			rg[tot]=i-las+1;
			mp[++tot]=i;
			las=i;
		}
	}
	dfs(1,1);
	printf("%lld\n",ans);
	return 0;
}

