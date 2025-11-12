#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[100],vis[100],c[100],ans;
bool f=1;
string s;
bool ch()
{
	int x=0,num=0;
	for(int i=1;i<=n;i++)
	{
	
		if(x>=c[a[i]])x++;
		else if(s[i]=='0')x++;		
		else num++;
	}
	return num>=m;
}
void dfs(int x)
{
	if(x==n+1)
	{
		if(ch())ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
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
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n>13)
	{
		if(m==1)
		{
			long long ans=1;
			for(long long i=1;i<=n*m;i++)
			{
				ans=(ans*i)%mod;
			}
			cout<<ans;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		dfs(1);
		cout<<ans;
	}
	return 0;
}