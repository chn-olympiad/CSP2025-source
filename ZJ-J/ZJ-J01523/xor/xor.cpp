#include <bits/stdc++.h>
using namespace std;
/*
about 20 minutes;
60 pts
*/
#define ll long long
int n, k, ans, l, r;
vector<ll> a;
vector<pair<int, int>> vec;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	a.resize(n);
	for (auto& i: a) cin >> i;
	for (l = 0; l < a.size(); l ++ ) {
		ll cur = 0;
		for (r = l; r < a.size(); r ++ ) {
			cur = cur xor a[r];
			if (a[r] == k) {
				vec.push_back({r, r});
				break;
			}
			if (cur == k) {
				vec.push_back({r, l});
				break;
			}
		}
	}
	sort(vec.begin(), vec.end());
	if (vec.size() == 0) {
		cout << 0;
		return 0;
	}
	int l = vec[0].second, r = vec[0].first;
	ans = 1;
	for (auto i: vec) {
		if (r < i.second) {
			l = i.second;
			r = i.first;
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
