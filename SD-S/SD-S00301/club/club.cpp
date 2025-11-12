#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll n;
vector<ll> dat[4];
void solve(){
	ll ans=0,a,b,c,ttt[4];
	ttt[0]=ttt[1]=ttt[2]=ttt[3]=0;
	dat[0].clear();dat[1].clear();dat[2].clear();dat[3].clear();
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a>>b>>c;
		ll ida=1,idb=2,idc=3;
		if(a<b) swap(a,b),swap(ida,idb);
		if(b<c) swap(b,c),swap(idb,idc);
		if(a<b) swap(a,b),swap(ida,idb);
		ans+=a;
		ttt[ida]++;dat[ida].push_back(b-a);
	}
	if(ttt[1]*2>n){
		sort(dat[1].begin(),dat[1].end());
		ll lz=dat[1].size();
		for(ll i=1;ttt[1]-i>=(n/2);i++) ans+=dat[1][lz-i];
	}
	if(ttt[2]*2>n){
		sort(dat[2].begin(),dat[2].end());
		ll lz=dat[2].size();
		for(ll i=1;ttt[2]-i>=(n/2);i++) ans+=dat[2][lz-i];
	}
	if(ttt[3]*2>n){
		sort(dat[3].begin(),dat[3].end());
		ll lz=dat[3].size();
		for(ll i=1;ttt[3]-i>=(n/2);i++) ans+=dat[3][lz-i];
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll T;cin>>T;while(T--) solve();
	return 0;
}
