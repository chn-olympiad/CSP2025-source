#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll l, a[15];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	l = s.size();
	for (ll i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') a[s[i] - '0']++;
	}
	for (ll i = 9; i >= 0; i--) {
		for (ll j = 1; j <= a[i]; j++) {
			printf("%lld", i);
		}
	}
	return 0;
}
