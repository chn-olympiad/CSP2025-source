#include<bits/stdc++.h>
#define endl '\n'
#define MSOD

using namespace std;
using ll = long long;

constexpr ll N = 1e5 + 5; 

ll n;
ll cnt[5];
struct T {
	ll v, id; 
	T() {}
	T(ll a, ll b) : v(a), id(b) {}
	inline friend bool operator < (T x, T y) {
		return x.v > y.v; 
	}
} vc[N][5];
inline void solve() {
	cin>>n;
	ll sm = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	for(int i = 1 ; i <= n ; i ++) {
		for(int j = 1 ; j <= 3 ; j ++) {
			cin>>vc[i][j].v;
			vc[i][j].id = j;
		}
		sort(vc[i] + 1, vc[i] + 4);
		sm += vc[i][1].v;
		cnt[vc[i][1].id] ++;
	}
	ll ans = 0;
	bool ok = true;
	if(cnt[1] > n / 2 || cnt[2] > n / 2 || cnt[3] > n / 2) {
		ok = false;
	}
	if(ok) {
		cout<<sm<<endl;
		return;
	} else {
		vector<ll> vvc;
		ll q = 0;
		ans = sm;
		for(int i = 1 ; i <= n ; i ++) {
			if(cnt[vc[i][1].id] > n / 2 && cnt[vc[i][2].id] != n / 2) {
				vvc.push_back(vc[i][2].v - vc[i][1].v);
				q = vc[i][1].id;
			}
		}
		sort(begin(vvc), end(vvc), greater<ll>());
		ll tot = 0;
		while(cnt[q] > n / 2) {
			if(tot < vvc.size()) {
				ans += vvc[tot ++];
				cnt[q] --;
			}
		}
		cout<<ans<<endl;
	}
	return;
}

signed main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int TC = 1;
#ifdef MSOD
	cin>>TC;
#endif
	while(TC --) {
		solve();
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
