#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	ll  x = 0;
	cin >> s;
	ll p = s.length();
	for (ll i = 0; i < p; i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			a[x] = (int) s[i] - '0';
			x++;
		}
	}
	sort(a, a + x);
	for (ll i = x - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}