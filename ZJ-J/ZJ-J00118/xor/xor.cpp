#include<bits/stdc++.h>
using namespace std;
long long n,k;
int dp[500005];
long long num[500005];
long long sum[500005];
int Max(int a,int b){
	if(a>b)return a;
	return b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);/**/
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		sum[i]=sum[i-1]^num[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i],dp[i-1]);
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				dp[j]=Max(dp[j],dp[i-1]+1);
				break;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=Max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
