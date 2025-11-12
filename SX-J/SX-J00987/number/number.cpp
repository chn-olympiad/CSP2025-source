#include <bits/stdc++.h>
#define ll long long
using namespace std;
string a;
ll maa[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a;
	for (ll i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			maa[a[i] - '0']++;
		}
	}
	for (ll i = 9; i >= 0; i--) {
		for (ll j = maa[i]; j >= 1; j--) {
			cout << i;
		}
	}
	return 0;
}
