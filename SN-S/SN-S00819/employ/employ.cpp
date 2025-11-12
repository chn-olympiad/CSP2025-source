#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=550;
const ll p=998244353;
ll c[maxn];
ll rk[maxn];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	
	ll cnt0=0;
	for (ll i=1;i<=n;i++){
		cin>>c[i];
		rk[i]=i;
		if (c[i]==0) cnt0++;
	}
	
	ll ans=0;
	do {
		ll wa=0;
		ll ac=0;
		for (ll i=1;i<=n;i++){
			if (wa>=c[rk[i]]) {
				wa++;
				continue;
			}
			if (s[i-1]=='0') wa++;
			else ac++;
			if (ac>=m) {
				ans++;
				ans%=p;
				break;
			}
		}
	}
	while (next_permutation(rk+1,rk+n+1));
	cout<<ans<<"\n";
	
	
}

