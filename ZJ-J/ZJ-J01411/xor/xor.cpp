#include<bits/stdc++.h>
using namespace std;
int n,k,x,c,sum[2000005],a[2000005],dp[2000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		c^=x;
		sum[c^x]=i;
		dp[i]=dp[i-1];
		if(sum[c^k])dp[i]=max(dp[i],dp[sum[c^k]-1]+1);
	}
	cout<<dp[n];
	return 0;
}
