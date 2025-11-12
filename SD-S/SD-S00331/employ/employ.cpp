#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,MOD=998244353;
int n,m;
string s;
int c[N];
ll ans=0;
int a[N],vis[N];
void dfs1(int t)
{
	if(t==n+1)
	{
	  int cnt=0;
	  for(int i=1;i<=n;i++)
	  {
	  	if(s[i]=='0')  cnt++;
	  	else  if(cnt>=c[a[i]])  cnt++;
	  }
	  if(n-cnt>=m)  ans=(ans+1)%MOD;
	  return; 
	}
	for(int i=1;i<=n;i++)
	{
	  if(vis[i])  continue;
	  vis[i]=1;
	  a[t]=i;
	  dfs1(t+1);
	  vis[i]=0;
	}
}
void solve1()
{
	dfs1(1);
	cout<<ans<<"\n";
}
void solve3(int k)
{
	ll fac=1;
	for(int i=1;i<=k;i++)  fac=fac*i%MOD;
	cout<<fac<<"\n";
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++)  cin>>c[i];
	if(n<=10){
	  solve1();
	  return 0;	
	}
	bool flag=1;
	for(int i=1;i<=n;i++)  if(s[i]=='0')  flag=0;
	if(m==n)
	{
	  if(!flag)  cout<<"0\n";
	  else  solve3(n);
	  return 0;
	}
	if(flag){
		int cnt=0;
		for(int i=1;i<=n;i++)  if(c[i]==0)  cnt++;
		if(n-cnt<m)  cout<<"0\n";
		else  solve3(n);
		return 0;
	}
	return 0;
}

