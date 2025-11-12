#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n, a[100010], dp[100010], ans, c[5010][5010];
long long f(int x){
	long long sum=0;
	for(int i=1;i<=x;i++){
		sum+=c[x][i];
		sum%=mod;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	c[1][1]=1;
	for(int i=1;i<=5000;i++){
		for(int j=1;j<=i;j++){
			if(!c[i][j])
			c[i][j]=(c[i-1][j-1]%mod+c[i-1][j]%mod)%mod;
		}
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		long long sum=0;
		for(int j=a[i];j<=2*a[i];j++){
			sum+=dp[j-a[i]];
			sum%=mod;
		}
		ans+=(f(i)-sum+mod)%mod;
		ans%=mod;
		for(int j=10001;j>=a[i];j--){
			dp[j]=dp[j]+dp[j-a[i]];
			dp[j]%=mod;
		}
	}
	cout<<ans;
	return 0;
} 
