#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll a[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	ll len = s.size();
	for (ll i = 0; i < len; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[s[i] - '0']++;
		}
	}
	for (ll i = 9; i >= 0; i--) {
		while (a[i] != 0) {
			printf("%lld", i);
			a[i]--;
		}
	}
	return 0;
}
