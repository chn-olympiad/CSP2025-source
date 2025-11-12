#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define pli pair<ll, int> 
#define fi first
#define se second
const int N = 5e2+10;
const int mod = 998244353;
int c[N];
ll qpl(ll x) {
	ll res = 1;
	rep(i, 2, x) {
		res = res*i%mod;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	rep(i, 1, n) cin >> c[i];
	int t = 0;
	rep(i, 1, n) {
		if (c[i]) t ++;
	}
	if (t < m) cout << 0;
	else cout << qpl(n);
	return 0;
}
