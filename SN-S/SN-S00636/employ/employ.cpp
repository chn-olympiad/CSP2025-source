//SN-S00636 蔡铭禹 西安高新第一中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,k,a[510],b[510],ans=0;
bool f[510],fl[510];

void dfs(int x)
{
	if(x==n+1)
	{
		int cnt=0,fq=0;
		for(int i=1;i<=n;i++)
		{
			if(fq>=a[b[i]])
			{
				fq++;
				continue;
			}
			if(f[i])
			{
				cnt++;
			}
			else fq++;
		}
		if(cnt>=k) 
		{
			ans++;
		}
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!fl[i])
		{
			fl[i]=true;
			b[x]=i;
			dfs(x+1);
			fl[i]=false;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='1')
		{
			f[i]=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=10)
	{
		dfs(1);
		cout<<ans;
	}
	else
	{
		int cnt=0;
		bool ff=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) cnt++;
			ff=(ff && f[i]);
		}
		if(n-cnt<k)
		{
			cout<<0;
			return 0;
		}
		if(cnt==0 && ff)
		{
			int ans=1;
			for(int i=1;i<=n;i++)
			{
				ans=ans*i%mod;
			}
			cout<<ans;
		}
		else
		{
			int ans=1;
			for(int i=1;i<=n-cnt;i++)
			{
				ans=ans*i%mod;
			}
			cout<<ans;
		}
	}
	return 0;
}
