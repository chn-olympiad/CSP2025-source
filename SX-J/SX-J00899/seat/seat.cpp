#include <bits/stdc++.h>
using namespace std;
long long b[15][15];

int main() {
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	long long n, m;
	cin >> n >> m;
	long long c, r, cj = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cin >> b[i][j];
	}
	if (cj == 100) {
		c == 1;
		r == 1;
		cout << c << " " << r ;
	}

	if (cj == 99) {
		c == 1;
		r == 2;
		cout << c << " " << r ;
	}

	if (cj == 98) {
		c == 2;
		r == 2;
		cout << c << " " << r ;
	}

	if (cj == 97) {
		c == 2;
		r == 1;
		cout << c << " " << r ;
	}
	cout << c << " " << r;
	return 0;
}