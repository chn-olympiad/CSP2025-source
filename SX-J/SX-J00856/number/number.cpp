#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll n[1000010], a;

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] > '0' && s[i] <= '9') {
			n[a] = s[i] - '0';
		}
	}
	sort(n, n + a, cmp);
	for (ll i = 0; i <= a; i++) {
		cout << n[i];
	}
	return 0;
}