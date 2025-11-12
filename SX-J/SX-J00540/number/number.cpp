#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 1e6+3;
string s;
ll a[M];

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	ll len = s.size();
	ll cnt = 0;
	for (ll i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i] - '0';
			cnt++;
		}
	}
	sort(a, a + len, cmp);
	for (ll i = 0; i < cnt; i++) {
		cout << a[i];
	}
	return 0;
}