#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll a, b, n[101];
ll s = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> a >> b;
	for (ll i = 1; i <= a * b; i++) {
		cin >> n[i];
		if (n[i] > n[1]) {
			s++;
		}
	}
	for (ll j = 1; j <= b; j += 2) {
		for (ll i = 1; i <= a; i++) {
			s--;
			if (s == 0) {
				cout << i << ' ' << j;
				return 0;
			}
		}
		for (ll i = a; i >= 1; i--) {
			s--;
			if (s == 0) {
				cout << i << ' ' << (j + 1);
				return 0;
			}
		}
	}/*
	eee = (((sum - 1) / a) % 2);
	if (eee == 0) {
		ll qw = (sum - 1) / a + 1;
		ll wq = sum % a;
		if (wq == 0)
			wq = a;
		cout << qw << " " << wq;
	} else {
		ll qwe = (sum - 1) / a + 1;
		ll wqe = sum % a;
		if (wqe == 0)
			wqe = a;
		wqe = a - wqe + 1;
		cout << qwe << " " << wqe;
	}*/
	return 0;
}
