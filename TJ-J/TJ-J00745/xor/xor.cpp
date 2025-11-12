#include <bits/stdc++.h>
using namespace std;
int a[500001],n,k,dp[500001],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n >>k;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>0;j--){
			cnt=a[i]^a[j-1];
			if(cnt==k){
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}
	}
	cout <<dp[n];
	return 0;
} 
