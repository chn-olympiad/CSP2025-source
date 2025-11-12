#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vel;
typedef pair<ll,ll> pll;
typedef vector<pll> velp;
typedef vector<vel> vevel;
void slv(){
	ll n,k;
	cin>>n>>k;
	vel v(n+3);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	ll x=0;
	map<ll,ll> mp;
	vel dp(n+3);
	mp[0]=0;
	for(int i=1;i<=n;i++){
		x^=v[i];
		ll tmp1=x,tmp2=k,tmpp=0,cnt=1;
		while(tmp1||tmp2){
			if((tmp1&1)==1&&(tmp2&1)==0||(tmp1&1)==0&&(tmp2&1)==1){
				tmpp+=cnt;
			}
			tmp1/=2;
			tmp2/=2;
			cnt*=2;
		}
		if(mp.find(tmpp)!=mp.end()){
			dp[i]=dp[mp[tmpp]]+1;
		}
		dp[i]=max(dp[i],dp[i-1]);
		mp[x]=i;
	}
	cout<<dp[n];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
	while(T--){
		slv();
	}
	return 0;
}