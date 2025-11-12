#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x[1005],a[1005],ans,vis[1005],mod=998244353,fl=1,f=1;
string s;
int js(int k)
{
	int sum=1;
	for(int i=1;i<=n-k+1;i++)
		sum=sum*i%mod;
	return sum;
}
void dfs(int k,int num)
{
	if(k-1-num==m)	{
		ans=(ans+js(k))%mod;
		return;
	}
	if(k==n+1)	{
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			if(x[k]==0||a[i]<=num)
				dfs(k+1,num+1);
			else
				dfs(k+1,num);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		x[i]=s[i-1]-'0';
		if(x[i]==0)	fl=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)	f=0;
	}
	if(m==n)
	{
		if(fl&&f)
			cout<<js(1);
		else	cout<<0;
	}
	else{
		dfs(1,0);
	}
	cout<<ans;
	return 0;
}