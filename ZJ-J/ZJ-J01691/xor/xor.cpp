#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int dp[500010],xo[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<=n;++i) xo[i]=xo[i-1]^a[i];
	if (a[1]==k) dp[1]=1;
	for (int i=2;i<=n;++i){
		for (int j=i-1;j>=0;--j){//1-j (j+1)-i
			if ((xo[i]^xo[j])==k) dp[i]=max(dp[i],dp[j]+1);
			else dp[i]=max(dp[i],dp[j]);
		}
	}
	cout<<dp[n];
//	for (int i=1;i<=n;++i) cout<<dp[i]<<' ';
	return 0; 
} 
