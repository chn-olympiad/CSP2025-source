#include<bits/stdc++.h>
#define sn 1000005
#define int long long
#define mod 998244353
using namespace std;
int n,m,ans,c[sn],s[sn],pre[sn];
char ch;
int jc[sn];
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
bool vis[sn];
int dly[sn];
int chk()
{
	int asn=0,los=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1)
		{
			los++;
		}
		else
		{
			if(los>=c[dly[i]])
			{
				los++;
			}
			else
			{
				asn++;
			}
		}
	}
	return asn>=m;
}
void dfs(int nw)
{
	if(nw==n+1)
	{
		ans+=chk();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			dly[nw]=i;
			dfs(nw+1);
			vis[i]=false;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m,jc[0]=1;
	for(int i=1;i<=2000;i++)
	{
		jc[i]=jc[i-1]*i%mod;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>ch;
		if(ch=='0')
		{
			s[i]=1;
		}
		else
		{
			s[i]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i],pre[i]=pre[i-1]+s[i];
	}
	if(n<=10)
	{
		dfs(1),cout<<ans%mod<<'\n';
		return 0;	
	}
	if(pre[n]==0)
	{
		cout<<jc[n]<<'\n';
		return 0;
	}
	if(m==n)
	{
		cout<<0<<'\n';
		return 0;
	}
	if(n-pre[n]<m)
	{
		cout<<0<<'\n';
		return 0;
	}
	return 0;
}
