#include<bits/stdc++.h>
#define lon long long
#define INF 5001
using namespace std;
const lon mod=998244353;//zs
int n;//5e3
int a[5010];//5e3
lon dp[5010];
lon ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	dp[a[1]]++;
	dp[a[2]]++;
	dp[min(INF,a[1]+a[2])]++;
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=INF;j++) ans=(ans+dp[j])%mod;
		for(int j=INF;j>=0;j--) dp[min(INF,a[i]+j)]=(dp[min(INF,a[i]+j)]+dp[j])%mod;
	}
	cout<<ans%mod;
	return 0;
}
