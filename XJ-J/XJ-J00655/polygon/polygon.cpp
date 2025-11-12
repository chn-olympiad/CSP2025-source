#include<bits/stdc++.h>
#define int long long int
using namespace std;
int n,a[5555],ans;
void dfs(int x,int mx,int sum)
{
 if(x>n)
 {
  if(x==n+1&&sum>mx*2)
   ans=(ans%998244353)+1;
  return;
 }
 dfs(x+1,max(mx,a[x]),sum+a[x]);
 dfs(x+1,mx,sum);
}
signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	dfs(1,0,0);
	cout<<ans%998244353;
	return 0;
}
