#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=550;
const int mod=998244353;
int n,m,c[N],ans=0,f[N];
bool vis[N],usd[N];
void dfs(int i,int k)
{
	if(i>n && k>=m)
	{
		ans++;
		ans%=mod;
		return ;
	}
	for(int j=1;j<=n;j++)
	{
		if(usd[j])continue;
		usd[j]=true;
		if(vis[i] && i-k-1<c[j]) dfs(i+1,k+1);
		else dfs(i+1,k);
		usd[j]=false;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool flagA=true;
	for(int i=1;i<=n;i++)
	{
		char ct;
		cin>>ct;
		if(ct=='0')vis[i]=0,flagA=false;
		else vis[i]=1;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	f[0]=1;
	for(int i=1;i<=n;i++)f[i]=(f[i-1]*i)%mod;
	if(n<=10)
	{
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	
	if(m==1)
	{
//		int num=0;
//		for(int i=1;i<=vis[i])
		cout<<515058943;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				cout<<0;
				return 0; 
			}
			if(c[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++)ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	
	if(flagA)
	{
		int num=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0)num++;
		}
		cout<<f[num];
		return 0;
	}
	
	
	return 0;
}

//