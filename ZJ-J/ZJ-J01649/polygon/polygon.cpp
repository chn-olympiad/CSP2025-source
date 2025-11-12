#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5005];
int dp[5005][5005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j]*dp[i][j-1];
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)sum+=dp[n][i];
	cout<<sum;
	return 0;
}
