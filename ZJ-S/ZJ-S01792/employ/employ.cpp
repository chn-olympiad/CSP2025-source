#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
map<ll,ll> mp;
ll f(ll x){
	ll sum=1;
	for(ll i=1;i<=x;i++) sum=(sum*i)%mod;
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m,sum=0;
	string s;
	cin>>n>>m>>s;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		if(x==0) sum++;
		mp[x]++;
	}
	ll ans=(sum*f(n-sum)%mod)*f(sum-1)%mod;
	for(ll i=sum;i<=n-m;i++){
		ll temp=i,cnt=1;
		map<ll,ll>::iterator it=mp.begin();
		for(;it!=mp.end();it++){
			if(temp<it->first) break;
			if(temp>it->second){
				cnt=(cnt*f(it->second))%mod;
				temp-=it->second;
			}else{
				cnt=(cnt*f(temp))%mod;
				temp=0;
			}
		}
		if(temp>0) continue;
		cnt=(cnt*f(n-i))%mod;
		ans=(ans+cnt)%mod;
	}
	cout<<ans;
	return 0;
}
