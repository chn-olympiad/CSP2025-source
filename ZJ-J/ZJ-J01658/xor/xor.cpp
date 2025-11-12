#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
const ll M=(1<<21);
ll a[N],dp[N];
ll mp[M];
void solve(){
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	mp[0]=0;
	for(ll i=1;i<=n;i++){
		dp[i]=dp[i-1];
		ll tmp=(a[i]^k);
		if(tmp==0){
			ll id=mp[tmp];
			dp[i]=max(dp[i],dp[id]+1);
		}
		if(tmp!=0){
			if(mp[tmp]!=0){
				ll id=mp[tmp];
				dp[i]=max(dp[i],dp[id]+1);
			}
		}
		mp[a[i]]=i;
	}
	cout<<dp[n];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	return 0;
}
