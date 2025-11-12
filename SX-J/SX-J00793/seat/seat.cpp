#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, x;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int c = n * m;
	int s[c + 1] = {};
	for (int i = 1; i <= c; i++) {
		cin >> s[i];
		if (a == 0) {
			b = s[i];
			a += 1;
		}
	}
	sort(s + 1, s + c + 1);
	for (int i = 1; i <= c; i++) {
		if (b == s[i]) {
			if ((c + 1 - i) % n == 0) {
				x = (c + 1 - i) / n;
				cout <<  x << " " ;
			} else {
				x = (c + 1 - i) / n + 1;
				cout << x  << " " ;
			}
			if (x % 2 == 0) {
				cout << x*m - i ;
			} else {
				cout <<  i % m + 1 ;
			}
		}
	}
	return 0;
}
