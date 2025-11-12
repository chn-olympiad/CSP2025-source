#include <bits/stdc++.h>
using namespace std;
int a[1000];

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c, s = 0;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	c = a[0];
	for (int i = 1; i < n * m; i++) {
		if (c < a[i])
			s++;
	}
	int v, b;
	if (s < n) {
		cout << "1 " << s + 1;
	}
	v = s / n;
	int p;
	p = v + 1;
	if (s >= n) {
		if (p % 2 == 0) {
			b = s / m ;
			b = b + 1;
			int x;
			x = n - b + 1;
			cout << p << " " << x + 1 ;
		} else {
			b = s % m;
			cout << p << " " << b + 1;
		}

	}



	return 0;
}