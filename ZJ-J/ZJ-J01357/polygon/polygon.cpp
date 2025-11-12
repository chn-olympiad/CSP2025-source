#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010],dp[2][5060],ans=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		int nw=(i&1),lst=!nw;
		for(int j=0;j<a[i];j++){
			dp[nw][j]=dp[lst][j];
			dp[nw][j]%=998244353;
		}
		for(int j=a[i];j<=5049;j++){
			dp[nw][j]=dp[lst][j-a[i]]+dp[lst][j];
			dp[nw][j]%=998244353;
		}
		dp[nw][5050]=dp[lst][5050];
		for(int j=5050-a[i];j<=5050;j++){
			dp[nw][5050]+=dp[lst][j];
			dp[nw][5050]%=998244353;
		}
		for(int j=a[i]+1;j<=5050;j++)
			ans+=dp[lst][j],ans%=998244353;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
