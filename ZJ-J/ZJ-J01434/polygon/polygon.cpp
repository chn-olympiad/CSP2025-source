#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll mod=998244353;
ll n,num,ans,a[114514],dp[114514];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	for(ll i=1;i<=n;i++){
		ans+=num;ans%=mod;
		num*=2;num%=mod;
		for(ll j=a[n];j>=0;j--){
			if(dp[j]){
				if(j>a[i]) ans+=dp[j],ans%=mod;
				if(j+a[i]>a[n]) num+=dp[j],num%=mod;
				else dp[j+a[i]]+=dp[j],dp[j+a[i]]%=mod;
			}
		}
	}
	cout<<ans%mod;
	return 0;
}

// I AK CSP!