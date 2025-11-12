#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e6+10;
const ll M = 1e3+10;
const ll inf = 0x3f3f3f3f3f3f;

ll n, k, arr[N];
ll ans;

namespace ee {
	void solve() {
		cout << n / 2;
	}
}

namespace e2 {
	void solve() {
		ll num = 0;
		for (ll i = 1; i <= n; i++) {
			if (arr[i] == 1)
				num++;
		}
		if (k == 1) {
			cout << num;
		} else {
			ll tot = 0;
			for (ll i = 1; i <= n; i++) {
				if (arr[i] == 1 && arr[i + 1] == 1) {
					tot++, i++;
				}
			}
			cout << n - num + tot;
		}
	}
}

ll brr[N];

namespace e3 {
	void solve() {
		ll sum = 0;
		for (ll i = 1; i <= n; i++) {
			if (arr[i] == k) {
				sum++;
			}
		}
		ll id = 0;
		for (ll i = 1; i <= n; i++) {
			if (abs(arr[i] - brr[i - 1]) == k) {
				ans++;
				brr[i - 1] = 0;
				arr[i] = 0;
			}
			brr[i] = brr[i - 1] + arr[i];
		}
		cout << max(sum, ans);
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool f = 0;
	bool f2 = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] != 1)
			f = 1;
		if (arr[i] != 1 && arr[i] != 0)
			f2 = 1;
	}
	if (f == 0) {
		ee::solve();
	} else if (f2 == 0) {
		e2::solve();
	} else {
		e3::solve();
	}
	return 0;
}
