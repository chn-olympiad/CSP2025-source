#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
inline ll read(){ ll x; scanf("%lld",&x); return x; }

vector<ll>vec[3];

ll n,a[3];
void procedure(){
	n=read();
	vec[0].clear(), vec[1].clear(), vec[2].clear();
	ll ans=0;
	for(ll i=1;i<=n;i++){
		a[0]=read(), a[1]=read(), a[2]=read();
		int op=0;
		if(a[1]>a[0]) op=1;
		if(a[2]>a[op]) op=2;

		sort(a, a+3);
		ans += a[2];
		vec[op].pb(a[1]-a[2]);
	}

	for(int o:{0,1,2}){
		if(vec[o].size() > n/2){
			sort(vec[o].begin(), vec[o].end());
			while(vec[o].size() > n/2){
				ans += vec[o].back();
				vec[o].pop_back();
			}
			break;
		}
	}
	printf("%lld\n", ans);
}
int main(){
	assert(freopen("club.in","r",stdin));
	assert(freopen("club.out","w",stdout));
	ll T=read();
	while(T--) procedure();
}