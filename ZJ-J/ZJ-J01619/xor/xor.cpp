#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e6+5;
int n,k,a[maxn],sum[maxn],dp[maxn];
map<int,int> lst;
map<int,bool> vis;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
	vis[0]=true;lst[0]=0;
	for(int i=1;i<=n;i++)
	 {
	 	dp[i]=dp[i-1];
	 	int need=(sum[i]^k);
	 	if(vis[need]) dp[i]=max(dp[i],dp[lst[need]]+1);
	 	vis[sum[i]]=true;
	 	if(dp[i]>dp[lst[sum[i]]]) lst[sum[i]]=i;
	 	//cout<<dp[i]<<' ';
	 }
	cout<<dp[n];
	return 0;
}
