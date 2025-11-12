#include<bits/stdc++.h>
using namespace std;
int g[5009];
long long dp[5009][5009][3];
int m=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	sort(g+1,g+1+n);
	dp[0][0][0]=1;
	long long sum=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=5001;j++){
			dp[i][j][0]=dp[i-1][j][0];
			dp[i][j][1]=(dp[i-1][j][1]+dp[i-1][max(0,j-g[i])][0])%m;
			dp[i][j][2]=(dp[i-1][j][2]+dp[i-1][max(0,j-g[i])][1]+dp[i-1][max(0,j-g[i])][2])%m;
		}
		if(i>=3)sum=(sum+dp[i-1][g[i]+1][2])%m;
	}
	cout<<sum;
	return 0;
}
