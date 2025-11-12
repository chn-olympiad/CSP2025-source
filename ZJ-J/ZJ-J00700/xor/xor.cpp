#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int MOD=1e9+7;
const int INF=1e9;
int n,ans,dp[N];
ll sum[N],a[N],k;
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],sum[i]=(sum[i-1]^a[i]);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=1;j<=i;j++){
			if((sum[i]^sum[j-1])==k)dp[i]=max(dp[i],dp[j-1]+1);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
/*
²Å320pts£¬ÒªAFOÁË55555555555 
*/
