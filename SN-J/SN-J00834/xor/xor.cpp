#include<bits/stdc++.h>
using namespace std;
int a[500005],dp[500005],b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]^b[i-1];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1 and dp[i]==dp[j];j--){
			if((b[i]^b[j-1])==m){
				dp[i]=max(dp[j-1]+1,dp[i]);
			}
		}
	}
	cout<<dp[n];
	return 0;
}
