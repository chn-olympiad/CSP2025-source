#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
#define ll long long
int n, m, t, tot;
string s;
vector<int> c;
bool flag;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	t = n;
	cin >> s;
	c.resize(n);
	for (auto& i: c) {
		cin >> i;
		if (i == 0) t --;
	}
	for (int i = 0; i < s.size(); i ++ ) {
		if (s[i] == '0') flag = 1;
		else tot ++;
	}
	if (m > t) {
		cout << 0;
		return 0;
	}
	if (!flag && m <= t) {
		ll ans = 1;
		for (int i = 2; i <= t; i ++ ) {ans *= i; ans %= mod;}
		cout << ans;
		return 0;
	} else if (!flag) {
		cout << 0;
		return 0;
	}
	if (m == n && n == t) {
		ll ans = 1;
		for (int i = 2; i <= t; i ++ ) {ans *= i; ans %= mod;}
		cout << ans;
		return 0;
	} else if (m == n) {
		cout << 0;
		return 0;
	}
	if (tot < m) {
		cout << 0;
		return 0;
	}
	vector<int> vec;
	for (int i = 1; i <= n; i ++ ) vec.push_back(i);
	ll ans = 0;
	do {
		int ty = 0, no_ty = 0;
		for (int i = 0; i < n; i ++ ) {
			int p = vec[i] - 1;
			if (c[p] <= no_ty) no_ty ++;
			else if (s[i] == '0') no_ty ++;
			else ty ++;
		}
		if (ty >= m) ans ++;
		ans %= mod;
	} while (next_permutation(vec.begin(), vec.end()));
	cout << ans << "\n";
	return 0;
}