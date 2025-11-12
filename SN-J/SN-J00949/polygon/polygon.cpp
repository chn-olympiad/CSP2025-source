#include<iostream>
#include<algorithm>
using namespace std;
constexpr long long mod=998244353;
int n,a[5000];
long long dp[5002],sum,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n),dp[0]=1;
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=5001;j>a[i];j--)sum=(sum+dp[j])%mod;
		ans=(ans+sum)%mod;
		for(int j=5001;j>=0;j--){
			dp[min(5001,j+a[i])]=(dp[min(5001,j+a[i])]+dp[j])%mod;
		}
	}printf("%lld",ans);
	return 0;
}
