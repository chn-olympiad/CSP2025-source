#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int flag=0;
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			if(dp[j-1]<dp[j]){
				break;
			}
			flag^=a[j];
			if(flag==k){
				dp[i]=dp[j]+1;
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}