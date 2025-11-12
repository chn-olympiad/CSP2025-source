#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mx=5e3+10;
const int mod=998244353;
int n;
int a[mx];
int dp[mx][mx];
int ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<mx;j++){
			if(j<a[i]) dp[i][j]=dp[i-1][j];
			if(j==a[i]) dp[i][j]=(dp[i-1][0]+dp[i-1][j]+1)%mod;
			else dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%mod;
		}
	}
	for(int i=n;i>=3;i--){
		for(int j=a[i]+1;j<mx;j++){
			ans=(ans+dp[i-1][j])%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
