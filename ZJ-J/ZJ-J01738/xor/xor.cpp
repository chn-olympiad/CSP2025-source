#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,a[500100],dp[500100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(i=1;i<=n;i++){
		for(j=i;j>=1;j--){
			dp[i]=max(dp[j-1]+((a[i]^a[j-1])==k),dp[i]);
		}
	}cout<<dp[n];
	return 0;
}
