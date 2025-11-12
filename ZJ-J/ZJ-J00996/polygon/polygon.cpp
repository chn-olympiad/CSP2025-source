#include<bits/stdc++.h>
using namespace std;
const long long N=5015;
const long long mod=998244353;
long long n,a[N],dp[5015],mx,cur;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	long long ret=0;
	for(long long i=0;i<n-1;i++){
		for(long long j=mx+1;j>=0;j--){
			dp[min(mx+1,j+a[i+1])]=(dp[min(mx+1,j+a[i+1])]+dp[j])%mod;
		}
		for(long long k=a[i+2]+1;k<=mx+1;k++){
			ret=(ret+dp[k])%mod;
		}
	}
	cout<<ret;
	return 0;
}