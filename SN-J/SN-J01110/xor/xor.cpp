#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],s,dp[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>0&&dp[j-1]==dp[i-1];j--){
			if((a[i]^a[j-1])==k){
				dp[i]++;
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}

