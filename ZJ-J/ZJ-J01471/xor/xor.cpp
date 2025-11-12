#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,k;
int a[N];
int dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j=i;j>=1;j--){
			if(j!=i) x=x^a[j];
			if(x==k){
				dp[i]=max(dp[j-1]+1,dp[i]);
				j=0;
			}
			if(dp[j]<dp[i]-1) j=0;
		}
		dp[i]=max(dp[i-1],dp[i]);
	}
	cout<<dp[n];
	return 0;
}