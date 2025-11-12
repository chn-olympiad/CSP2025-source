#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int>Seats(n *m + 1);
	cin >> Seats[1];
	int x = 1;
	for (int i = 2; i <= n * m ; i++ ) {
		cin >> Seats[i];
		if (Seats[i] > Seats[1]) {
			x += 1;
		}
	}
	int c, r, x_n1, x_n2;
	x_n1 = x / n;
	x_n2 = x % n != 0 ? 1 : 0;
	c = x_n1 + x_n2;
	if (c % 2) {
		r = (x - 1) % n + 1;
	} else {
		r = n - x % n + 1;
	}
	cout << c << " " << r;
	return 0;
}

