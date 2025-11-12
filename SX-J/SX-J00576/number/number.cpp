#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e6+10;
const ll inf = 0x3f3f3f3f3f3f;

string s;
int x[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int a = (int)s[i] - '0';
			x[a]++;
		}
	}
//	for (ll i = 0; i <= 9; i++) {
//		cout << x[i] << endl;
//	}
//	return 0;
	for (ll i = 9; i >= 0; i--) {
		if (x[i] >= 1) {
			for (ll j = 1; j <= x[i]; j++) {
				cout << i;
			}
		}
	}
	return 0;
}
