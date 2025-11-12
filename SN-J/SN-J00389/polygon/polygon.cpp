//SN-J00389  张爱熙  西安高新第一中学
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+5,mod=998244353,M=2.5e6+5;
ll n,a[N],ans,sum[N],dp[M],f[M];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum[i];j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
			if(j>a[i]*2 && i>2) ans=(ans+dp[j-a[i]])%mod;
		}
	}
	cout<<ans;
	return 0;
}
