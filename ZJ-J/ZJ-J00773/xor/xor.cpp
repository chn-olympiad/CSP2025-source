#include<bits/stdc++.h>
using namespace std;
int a[500005],pre[1050005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,k,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	pre[0] = 0;
	for(int i=1;i<=n;i++){
		dp[i] = dp[i-1];
		s^=a[i];
		int t = s^k;
		if(pre[t]||t==0){
			dp[i] = max(dp[i],dp[pre[t]]+1);
		}
		pre[s] = i;
	}
	cout<<dp[n];
	return 0;
}
