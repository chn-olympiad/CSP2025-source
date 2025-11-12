#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s,dp[500005],ans,lt[1048576];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=dp[i-1];
		s^=a[i];
		if(lt[s^k]||s==k)dp[i]=max(dp[i],dp[lt[s^k]]+1);
		lt[s]=i;
	}
	cout<<dp[n];
	return 0;
}
