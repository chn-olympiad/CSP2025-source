#include <bits/stdc++.h>

using namespace std;
using num = long long;

namespace sol {

	bitset<1010> bs;
	constexpr num modn = 998244353;

	num fac(num x) {
		num res = 1;
		for (num i = 2; i <= x; ++i) {
			res *= i;
			res %= modn;
		}
		return res;
	}

	void run() {
		ios::sync_with_stdio(0), cin.tie(0);
		freopen("employ.in", "r", stdin);
		freopen("employ.out", "w", stdout);
		num n, m;
		cin >> n >> m >> bs;
//		cerr << "1";
		vector<num> a(n);
		num sum = 0;
		for (num i = 0; i < n; ++i) {
			sum += bs[i];
			cin >> a[i];
		}
//		if (sum < m) {
//			cout << "0\n";
//			return;
//		}
//		if (sum == n) {
//			cout << fac(n) << '\n';
//			return;
//		}
//		if (m == 1 && bs[0] == 1) {
//			cout << fac(n) << '\n';
//			return;
//		}
		num ans = 0;
		vector<num> v(n);
		iota(v.begin(), v.end(), 0);
		do {
			num cnt = 0, fail = 0;
			for (num i = 0; i < n; ++i) {
				if (bs[i] && fail < a[v[i]]) {
					++cnt;
				} else {
					++fail;
				}
			}
			if (cnt >= m) {
				++ans;
			}
		} while (next_permutation(v.begin(), v.end()));
		cout << ans;
	}

}

int main() {
	sol::run();
}