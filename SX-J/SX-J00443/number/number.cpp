#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (ll i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			t[s[i] - '0']++;
		}
	}
	for (ll i = 9; i >= 0; i--) {
		for (ll j = 1; j <= t[i]; j++)
			cout << i;
	}
	return 0;
}
