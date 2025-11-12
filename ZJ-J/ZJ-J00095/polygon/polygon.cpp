#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5,mod=998244353,M=5e3+5;
#define int long long
int n,ans,a[M],dp[N],s[M];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		s[i]%=mod;
	}
	for(int i=1;i<3;i++){
		for(int j=s[i];j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			dp[j]%=mod;
		}
	}
	for(int i=3;i<=n;i++){
		int p=s[i]-a[i]-a[i];
		for(int j=0;j<p;j++){
			ans+=dp[j];
			ans%=mod;
		}
		for(int j=s[i];j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			dp[j]%=mod;
		}
	}
	printf("%lld",ans%mod);
	return 0;
}
