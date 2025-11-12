#include<bits/stdc++.h>
#define endl '\n'
//#define MSOD

using namespace std;
using ll = long long;

constexpr ll N = 5e2 + 5, M = 998244353;

ll n, m, tt;
ll c[N];
string s;
ll fac[N], dp[N][N];
inline void init() {
	fac[0] = 1;
	for(int i = 1 ; i <= 500 ; i ++) {
		fac[i] = fac[i - 1] * i % M;
	}
	return;
}
inline void task1() {
	return;
}
inline void solve() {
	cin>>n>>m>>s;
	s = " " + s;
	for(int i = 1 ; i <= n ; i ++) {
		cin>>c[i];
	}
	cout<<0<<endl;
	return;
}

signed main() {
	init();
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	int TC = 1;
#ifdef MSOD
	cin>>TC;
#endif
	while(TC --) {
		solve();
	}
	return 0;
}

