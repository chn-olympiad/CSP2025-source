#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, s, a, x, c, r;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 2; i <= n * m; i++) {
		cin >> x;
		if (x > s) {
			a++;
		}
	}
	a++;
	c = a / n;
	if (a != 0) {
		c++;
	}
	a %= n;
	cout << c << " " ;
	if (c % 2 == 0) {
		r = m - a + 1;
	} else {
		r = a;
	}
	cout << r;
}
