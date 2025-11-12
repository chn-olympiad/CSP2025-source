#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxx=5e3+4,MOD=998244353;
ll n,a[maxx],dp[maxx],mx,ans;

ll sum(ll k){
	ll tmp=0;
	for (ll i=k+1;i<=mx+1;i++){
		tmp=(tmp+dp[i])%MOD;
	}
	return tmp;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (ll i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for (ll i=1;i<=n;i++){
		if (i>=3) ans=(ans+sum(a[i]))%MOD;
		for (ll j=mx+a[i]+1;j>=a[i];j--){
			if (j>mx){
				dp[mx+1]=(dp[mx+1]+dp[j-a[i]])%MOD;	
			}
			else dp[j]=(dp[j]+dp[j-a[i]])%MOD;
		}
	}
	cout<<ans;
	return 0;
}
