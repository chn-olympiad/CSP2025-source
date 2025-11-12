#include<bits/stdc++.h>
using namespace std;
const long long P=998244353;
int a[5005];
long long dp[5005][5005],DP[5005][5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(j<a[i]){
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
				if(dp[i][j]>=P) dp[i][j]-=P;
			}
		}
		dp[i][m+1]=dp[i-1][m+1];
		dp[i][m+1]+=DP[i-1][m+1-a[i]];
		if(dp[i][m+1]>=P) dp[i][m+1]-=P;
		for(int j=m+1;j>=0;j--){
			DP[i][j]=DP[i][j+1]+dp[i][j];
			if(DP[i][j]>=P) DP[i][j]-=P;
		}
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		ans+=DP[i-1][a[i]+1];
		if(ans>=P) ans-=P;
	}
	cout<<ans;
	return 0;
}
