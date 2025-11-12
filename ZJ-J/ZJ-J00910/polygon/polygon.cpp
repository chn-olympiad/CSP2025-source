#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans;
int a[5005];
int dp[5005][5005];//表示前i个数选出总和为j的方案数 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=1;i<n;i++){
		dp[i][0]=1;
		for(int j=1;j<=a[n];j++){
			if(j>=a[i])dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%mod;
			else dp[i][j]=dp[i-1][j];
		}
		for(int k=a[n]+1-a[i];k<=a[n]+1;k++){
			dp[i][a[n]+1]=(dp[i][a[n]+1]+dp[i-1][k])%mod;
		}
		dp[i][a[n]+1]=(dp[i][a[n]+1]+dp[i-1][a[n]+1])%mod;
	}
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=a[n]+1;j++){
			ans=(ans+dp[i-1][j])%mod;
		}
	}
	cout<<ans;
	return 0;
}
