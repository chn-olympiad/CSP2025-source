#include<bits/stdc++.h>
#define ll long long
#define ac ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
ll n,a[5005],ans,mx=0;
void dfs(ll cur,ll maxs,ll h)
{
  if(cur==n+1)
  {
  	if(h>maxs*2) ans++,ans%=998244353;
  	return;
  }
  dfs(cur+1,maxs,h);
  dfs(cur+1,max(maxs,a[cur]),h+a[cur]);
}
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  ac;
  cin>>n;
  for(ll i=1;i<=n;i++)
  {
  	cin>>a[i];
  	mx=max(mx,a[i]);
  }
  if(mx==1)
  {
  	cout<<max(n-n,n-2);
  }
  else
  {
  	dfs(1,0,0);
  	cout<<ans;
  }
  return 0;
}
