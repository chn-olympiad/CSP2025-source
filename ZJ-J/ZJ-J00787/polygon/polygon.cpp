#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
const int mod=998244353;
int n,sum=0;
long long ans;
int a[N];
long long dp[N];
long long Q(int x){
	if(x==0)return 1;
	if(x==1)return 2;
	long long T=Q(x/2);
	T=T*T%mod;
	if(x%2==1)T=T*2%mod;
	return T;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		long long t=0;
		for(int j=10000;j>=a[i];j--){
		    if(j<=2*a[i])t=(t-dp[j]+mod)%mod;
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
			if(j<=2*a[i])t=(t+dp[j]+mod)%mod;
		}
		ans=((ans+Q(i-1))%mod-t+mod)%mod;
	}
	cout<<ans;
	return 0;
}
