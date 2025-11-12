#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,mod=998244353;
int a[N],dp[N],dp1[N];
int quick_pow(int x,int y){
	int ans=1;
	while(y){
		if(y%2==1) ans=(ans*x)%mod;
		y/=2;
		x=(x*x)%mod;
	}
	ans%=mod;
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++){
			dp1[i]=(dp1[i]+dp[j])%mod;
			dp1[i]%=mod;
		}
		for(int j=m;j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
			dp[j]%=mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=(quick_pow(2,i-1)-dp1[i]+mod)%mod;
		ans=(ans+x)%mod;
	}
	cout<<ans;
	return 0;
}
