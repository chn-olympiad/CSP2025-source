#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int mod=998244354;
int dp[N][N],n,a[N],ans,f[N];
void dfs(int k,int xt,int x,int mx,int sum)
{
	if(xt==x)
	{
		if(mx*2<sum)
			ans++,ans%=mod;
		return;
	}
	if(k>n)
		return;
	dfs(k+1,xt+1,x,max(mx,a[k]),sum+a[k]);//选
	dfs(k+1,xt,x,mx,sum);//不选
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
		dfs(1,0,i,0,0);
	cout<<ans<<"\n";
	return 0;
}