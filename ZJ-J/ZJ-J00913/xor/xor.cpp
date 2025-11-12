#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010]={0};
int main(){
	freopen("xor6.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int dp[n+10][n+10]={0},x[n+10][n+10]={0};
	for(int i=1;i<=n;i++){
		x[i][i]=a[i];
		dp[i][i]=(a[i]==k?1:0);
	}
	for(int i=2;i<=n;i++){
		for(int l=1,r=l+i-1;r<=n;l++,r++){
			x[l][r]=x[l][r-1]^a[r];
			dp[l][r]=(x[l][r]==k?1:0);
			for(int j=l;j<r;j++){
				dp[l][r]=max(dp[l][r],dp[l][j]+dp[j+1][r]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}
