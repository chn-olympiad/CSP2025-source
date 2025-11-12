#include<bits/stdc++.h>
using namespace std;
const int mx=5e3+10;
const int g=998244353;
int a[mx];
int dp[mx][mx];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[i][j]=(dp[i-1][j]+dp[i][j-1]+1)%g;
		}
	}
	int ans=0;
	for(int i=3;i<=n;i++)ans=(ans+dp[i][n])%g;
	cout<<ans;
	return 0;
}