#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5003],dp[5005][10005][2],AC,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=0;i<=a[1];i++) dp[1][i][1]=1;
	dp[1][0][0]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=2*a[n]+1;j++){
			dp[i][j][0]=(dp[i][j][0]+dp[i-1][j][0]+dp[i-1][j][1])%mod;
			dp[i][j][1]=(dp[i][j][1]+dp[i-1][max(0,j-a[i])][0]+dp[i-1][max(0,j-a[i])][1])%mod;
		}
	}
	for(int i=3;i<=n;i++) AC=(AC+dp[i][2*a[i]+1][1])%mod;
	cout<<AC;
	return 0;
}
