#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5+10;
const ll B=5;
ll n,a[N][B];
vector<ll>de[B];
void solve(){
	cin>>n;
	for(ll i=1;i<=3;i++){
		de[i].clear();
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll mx=0;ll nmx=0;
		for(ll j=1;j<=3;j++){
			if(a[i][mx]<a[i][j]) nmx=mx,mx=j;
			else if(a[i][nmx]<a[i][j]){
				nmx=j;
			}
		}
		de[mx].push_back(a[i][mx]-a[i][nmx]);
		ans+=a[i][mx];
	}
	for(ll i=1;i<=3;i++){
		sort(de[i].begin(),de[i].end());
	}
	ll mxsz=0;
	for(ll i=1;i<=3;i++){
		ll xx=de[i].size();
		mxsz=max(mxsz,xx);
	}
	if(mxsz>(n/2)){
		ll pos=0;
		for(ll i=1;i<=3;i++){
			if(de[i].size()==mxsz){
				pos=i;break;
			}
		}
		ll ddd=de[pos].size()-(n/2);
		for(ll i=0;i<ddd;i++){
			ans-=de[pos][i];
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	ll T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
