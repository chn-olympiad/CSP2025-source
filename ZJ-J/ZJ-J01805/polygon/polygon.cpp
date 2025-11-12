#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,m,a[N];
long long ans,dp[N];
//dp[i] sum>=i cnt 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	m=a[n]+1;//max
	dp[0]=1;
	for(int i=1;i<=n;i++){
		//qin ding maxn=a[i] a[i] bi xuan
		if(i>=3)
			ans=(ans+dp[a[i]+1])%mod;
		for(int j=m;j>=a[i];j--)
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		for(int j=a[i]-1;j>=0;j--)
			dp[j]=(dp[j]+dp[0])%mod;
	}
	printf("%lld",ans);
	return 0;
}
