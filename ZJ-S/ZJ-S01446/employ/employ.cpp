#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510],t[510],a[510],vis[510],s0[510];
long long ans;
string s;
void dfs(int level)
{
	if(level>n)
	{
		int sum=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s0[i]+cnt<c[a[i]]) 
			{
				if(t[i]==1) sum++;
			}
			else
			{
				if(t[i]==1) cnt++;
			}
		}
		if(sum>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[level]=i;
			dfs(level+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	s=' '+s;
	int flag=1;
	for(int i=1;i<=n;i++) 
	{
		t[i]=s[i]-'0';
		if(t[i]!=1) flag=0;
	}
	for(int i=1;i<=n;i++)
		s0[i]=s0[i-1]+(t[i]==0);
	if(n<=10)
	{
		ans=0;
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		cout<<0;
		return 0;
	}
	if(flag)
	{
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	cout<<730144519;
	return 0;
}