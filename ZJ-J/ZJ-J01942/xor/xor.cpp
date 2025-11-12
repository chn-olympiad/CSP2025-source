#include<bits/stdc++.h>
using namespace std;
long long arr[500010],dp[500010];
int check(long long x,long long y){
	return (arr[y]^arr[x-1]);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	for(long long i=1;i<=n;i++){
		arr[i]=(arr[i-1]^arr[i]);
	}
	for(long long i=1;i<=n;i++){
		dp[i]=max(dp[i-1],dp[i]);
		for(long long j=i;j>=1;j--){
			if(check(j,i)==k){	
				dp[i]=max(dp[i],dp[j]+1);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}
