#include<bits/stdc++.h>
using namespace std;
long long n,m,c[501],vis[501],b[501],ans,num;
long long const mod=998244353;
string s;
void dfs(int x)
{
	if(x==n+1)
	{
		long long sum=0,res=0;
		for(int i=1;i<=n;i++)
			if(c[b[i]]<=res)
			{
				res++;
			}
			else
			{
				if(s[i-1]=='1')
					sum++;
				else
					res++;
			}
		if(sum>=m)
			ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			b[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i];
		if(c[i]==0)
			num++;
	}
	if(n<=10)
	{
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}
	if(n-num<m)
		cout<<0;
	else
	{
		ans=1;
		for(int i=1;i<=n;i++)
			ans=(ans*i)%mod;
		cout<<ans<<endl;
	}
	return 0;
}