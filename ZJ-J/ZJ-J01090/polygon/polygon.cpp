#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long dp[5010];
int mod=998244353;
long long power(long long a,long long b){
	long long ans=1;
	for(int i=1;i<=b;++i){
		ans=ans*a%mod;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=power(2,n)-2-n;
	dp[0]=1;
	for(int i=1;i<=n;++i){
		if(i>=3){
			long long cnt=0;
			for(int j=1;j<=a[i];++j){
				cnt=(cnt+dp[j])%mod;
			}
			ans=ans-cnt;
		}
		for(int j=5000;j>=a[i];j--){
			if(dp[j-a[i]]==0){
				continue;
			}
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	cout<<ans;
	return 0;
}
