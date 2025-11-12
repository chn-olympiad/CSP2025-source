#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
string s;
long long c[505];
int vis[505],sum;
void dfs(int l,int k,int q)
{
	int qq=q;
	if(s[l]=='0' || q>=c[k])
	{
		qq++;
	}
	if(l==n)
	{
		if(n-qq>=m)
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(l+1,i,qq);
			vis[i]=0;
		}
	}
}
int main()
{
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s='0'+s;
	for(int i=1;i<=n;i++)sum+=s[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	if(sum<m)
	{
		cout<<0;
		return 0;
	}
	int o=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			o++;
		}
	}
	if(n-o<m)
	{
		cout<<0;
		return 0;
	}
	if(sum==n)
	{
		
		ans=1;
		for(int i=1;i<=n;i++)ans=(ans*i)%998244353;
		cout<<ans%998244353;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		dfs(1,i,0);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}

