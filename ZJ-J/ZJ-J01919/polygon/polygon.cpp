#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int ans,m;
int cnt[5005];
int Pascal[5005][5005];
//const int M=998244353;
void dfs(const int t,const int sum,const int sdick)
{
  if(t==m)
  {
  	if((a[sdick]<<1)<sum)
  	{
	  ++ans;
	  if(ans==998244353)ans=0;
	}
	return;
  }
  for(int i=sdick+1;i<=n&&(n-i+1)+t>=m;++i)
  {
  	dfs(t+1,sum+a[i],i);
  }
}
inline void Pasical(const int n)
{
  for(int i=0;i<=n;++i)
  for(int j=0;j<=i;++j)
  {
  	if(j==0||j==i)Pascal[i][j]=1;
  	else Pascal[i][j]=(Pascal[i-1][j]+Pascal[i-1][j-1])%998244353;
  }
}
inline void solve()
{
  Pasical(n);
  for(int i=3;i<=n;++i)
  ans=(ans+Pascal[n][i])%998244353;
  cout<<ans;
  exit(0);
}
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;++i)
  cin>>a[i];
  sort(a+1,a+n+1);
  if(a[n]==1)
  solve();
  for(m=3;m<=n;++m)
  dfs(0,0,0);
  cout<<ans;
  return 0;
}
