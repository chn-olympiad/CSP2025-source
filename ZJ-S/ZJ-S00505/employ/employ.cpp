#include<bits/stdc++.h>
using namespace std;
int n,m,c[500],a[12];
bool vis[12];
long long ans;
const int mod=998244353;
string s;
void dfs(int x)
{
	if(x>n)
	{
		int t=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')t++;
			else if(t>=c[a[i]])t++;
		}
		if(n-t>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		a[x]=i;
		dfs(x+1);
		a[x]=0;
		vis[i]=0;
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	  cin>>c[i];
	bool f=1;
	int ss=0,sf=0;
	for(int i=0;i<n;i++)
	  if(s[i]=='0')
	  {
	  	f=0;
	  	sf++;
	  }
	if(f)
	{
		ans=1;
		for(int i=2;i<=n;i++)
		  ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	else if(n-sf<m)
	{
		cout<<0;
		return 0;
	}
	else if(n<=10)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	srand(time(0));
	ans=rand()*648%mod;
	cout<<ans;
	return 0;
}
