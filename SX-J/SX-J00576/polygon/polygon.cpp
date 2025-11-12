#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e6+10;
const ll M = 1e3+10;
const ll inf = 0x3f3f3f3f3f3f;
const ll mod = 998244353;

ll n, arr[N];
ll ans;

namespace e1 {
	void solve() {
		for (ll i = 3; i <= n; i++) {
			ans += ((n % i + 1) % mod);
			ans %= mod;
		}
		cout << ans;
	}
}

namespace e2 {
	void solve() {
		ll sum = 0;
		ll mymax = 0;
		for (ll i = 1; i <= n; i++) {
			sum += arr[i];
			mymax = max(mymax, arr[i]);
		}
		if (sum > 2 * mymax) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
}

ll mymax, a;
ll brr[N];
bool vis[N];

namespace e3 {
	void dfs(ll now, ll step, ll sum) {
		if (now > n)
			return ;
		if (step >= a) {
			for (ll i = 1; i <= step; i++)
				mymax = max(mymax, arr[brr[i]]);
			if (sum > mymax * 2) {
				ans++;
				ans %= mod;
//				for (ll i = 1; i <= step; i++)
//					cout << arr[brr[i]] << " ";
//				cout << endl;
			}
			return ;
		}
		for (ll i = now; i <= n; i++) {
			if (vis[i] || i < brr[step])
				continue;
			brr[step + 1] = i;
			vis[i] = 1;
			dfs(now + 1, step + 1, sum + arr[i]);
			brr[step + 1] = 0;
			vis[i] = 0;
		}

	}
	void solve() {
		for (ll i = 3; i <= n; i++) {
			memset(vis, 0, sizeof(vis));
			mymax = 0;
			a = i;
			dfs(1, 0, 0);
		}
		cout << ans % mod;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool f = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] != 1) {
			f = 1;
		}
	}
	if (!f) {
		e1::solve();
	} else if (n <= 3) {
		e2::solve();
	} else {
		e3::solve();
	}
	return 0;
}
