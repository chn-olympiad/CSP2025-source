#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<typename T>
ll SZ(const T &a){
	return a.size();
}
constexpr ll N=100010;
ll n,a[N][3],d[N];
void solve(){
	cin>>n;
	ll ans=0;
	vector<ll> b[3];
	for(ll i=1;i<=n;i++){
		ll mx=-1,id=-1;
		for(ll j=0;j<3;j++){
			cin>>a[i][j];
			if(a[i][j]>mx){
				mx=a[i][id=j];
			}
		}
		ans+=mx;
		b[id].push_back(i);
		d[i]=a[i][id]-max(a[i][(id+1)%3],a[i][(id+2)%3]);
	}
	ll mx=-1,id=-1;
	for(ll i=0;i<3;i++){
		if(SZ(b[i])>mx){
			mx=SZ(b[id=i]);
		}
	}
	sort(b[id].begin(),b[id].end(),[&](ll x,ll y)->ll{
		return d[x]<d[y];
	});
	for(ll i=0;i<mx-n/2;i++){
		ans-=d[b[id][i]];
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}