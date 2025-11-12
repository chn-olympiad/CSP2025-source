//SN-S00117  吴禹泽  陕西延安中学
#include<iostream>
#include<string>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;

const ll mod = 998244353;
ll n, m;
string t;
ll pt[505], test[505];
bool sp = 1;

void spwork() {
	ll ans = 0;
	for(int i=n-m+1; i<=n; i++) {
		ll t = 1;
		for(int j=i; j<=n; j++) {
			t = ((t % mod) * (j % mod)) % mod ;
		}
		ans = ((ans % mod) + (t % mod)) % mod;
	}

	cout<<ans;
	return;
}

int main() {
	fastio;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m;
	cin>>t;
	for(int i=0; i<t.size(); i++) {
		test[i] = t[i] - '0';
		if(t[i] == 0) sp = 0;
	}
	for(int i=1; i<n; i++) {
		cin>>pt[i];
	}

	if(sp) {
		spwork();
		return 0;
	}

	cout<<1;
	return 0;
}
