#include<bits/stdc++.h>
using namespace std;
int sum[3501][3501];
int a[500001];
int dp[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i;j++){
			sum[j][i]=a[j];
			for(int t=j+1;t<=i;t++) sum[j][i]^=a[t];
		}
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=1;j<=i;j++) if(sum[j][i]==k)dp[i]=max(dp[i],dp[j-1]+1);
	}
	cout<<dp[n];
	return 0;
} 
