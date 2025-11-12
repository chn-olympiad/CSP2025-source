#include<bits/stdc++.h>
using namespace std;
int a[500010];
int dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int p=a[i];
		if(p==k){
			dp[i]=max(dp[i],dp[i-1]+1);
		}
		else{
			for(int j=i-1;j>=1;j--){
				p^=a[j];
				if(p==k){
					dp[i]=max(dp[j-1]+1,dp[i]);
					break;
				}
			}
		}
	}
	cout<<dp[n]<<'\n';
	return 0;
}
