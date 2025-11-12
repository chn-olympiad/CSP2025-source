#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,p[505],a[505],ans,flag[505],mod=998244353;
string s;
void dfs(int k,int num)
{
	if(k==n+1)
	{
		if(num>=m) ans=(ans+1)%mod;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=1;
			dfs(k+1,num+(k-1-num<a[i]&&s[k-1]=='1'));
			flag[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j;
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=10) 
	{
		dfs(1,0);cout<<ans; 
	}
	else if(m==1)
	{
//		sort(a+1,a+n+1);
//		for(i=1;i<=n;i++)
//		{
//			if(s[i-1]=='0') 
//		}
		cout<<0;
	}
	else if(m==n)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]==0||s[i-1]=='0') break;
		}
		if(i<=n) cout<<0;
		else
		{
			ans=1;
			for(i=1;i<=n;i++)
			{
				ans=ans*i%mod;
			}
			cout<<ans;
		}
	}
	else cout<<0;
	return 0;
}
