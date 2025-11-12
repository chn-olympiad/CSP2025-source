#include <bits/stdc++.h>
#define ll long long
#define P pair<long long,long long>

using namespace std;
const int N = 1e6+10;
const ll inf = 0x3f3f3f3f3f3f;
const ll mod = 998224353;

ll n, m;
string s;
ll arr[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	if (n == m) {
		cout << n;
		return 0;
	}
	if (m == 1) {
		ll ans = 0;
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] == '1')
				ans++;
			ans %= mod;
		}
		cout << ans % mod;
		return 0;
	}
	cin >> s;
	for (ll i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	ll sum = 1;
	for (ll i = 2; i <= n; i++) {
		sum *= i;
		sum %= mod;
	}
	ll cnt = 1;
	for (ll i = 2; i <= n - m; i++) {
		cnt *= i;
		cnt %= mod;
	}
	cout << (sum / cnt) % mod;
	return 0;
}
