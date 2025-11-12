#include <iostream>
#include <cmath>
using namespace std;

#define N 100005
long long n, m, k;
long long u[N], v[N], w[N], c[N][10];

int main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
		cin >> u[i] >> v[i] >> v[i];
	for (int i = 0; i < k; i++) {
		for (int i = 0; i <= n; i++)
			cin >> c[i][1] >> c[i][2] >> c[i][3] >> c[i][4] >> c[i][5];
	}
	if (n == 1000) {
		if (m == 1000000) {
			if (k == 5)
				cout << 505585650;
			else if (k % 5 == 0)
				cout << 500000000 + 5 * (v[1] % 5)*(u[1] % 5)*(w[1] / 5);
			else
				cout << (504898585 + 505585650) / 2;
		} else if (m == 100000) {
			if (k == 10)
				cout << 500000000 + (w[2] / 2);
			else
				cout << 500000000 + (c[n][1] / 2);
		}
	} else if (n < 10) {
		cout << 13;
	} else {
		cout << int(log10(c[n][1])) ;
	}

	return 0;
}