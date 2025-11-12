#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ans;
const int N=510;
int s[N],c[N],a[N],vis[N];
string st;
int n,m;
void dfs(int k)
{
	if(k>n)
	{
		int num=0;
		for(int i=1;i<=n;i++)
		  if(s[i]==0||c[a[i]]<=num) num++;
		if(n-num>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	  if(!vis[i])
	  {
	  	  vis[i]=1;a[k]=i;
	  	  dfs(k+1);
	  	  vis[i]=0;
	  }
}
int check()
{
	for(int i=1;i<=n;i++)
	  if(s[i]==0) return 0;
	return 1;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
    cin>>st;
    for(int i=0;i<n;i++) s[i+1]=(st[i]-'0');
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		  if(s[i]==0)
		  {
		  	  cout<<0;
		  	  return 0;
		  }
		for(int i=1;i<=n;i++)
		  if(c[i]==0)
		  {
		  	  cout<<0;
		  	  return 0;
		  }
		ans=1ll;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	dfs(1);
    cout<<ans;
	return 0;
	return 0;
}
