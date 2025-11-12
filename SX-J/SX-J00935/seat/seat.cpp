#include <bits/stdc++.h>
using namespace std;
int n, m, r, a;
int c[105];

int main() {
	//freopen("seat.in", "r", "stdin");
	//freopen("seat.out", "w", "stdout");
	cin >> n >> m;

	for (int i = 0; i < n * m; i++ ) {
		cin >> c[i];
		if (i == 0)
			r = c[i];
	}
	sort(c, c + n *m);
	for (int i = 0; i < n * m; i++) {

		if (r == c[i])
			a = i + 1;
	}

	if (a % n == 1)
		cout <<  a % n << " " << a / n + 1;
	else if (a % n == 0)
		cout << 1 << " " << a / n;
	else
		cout << a % n << " " << a / n + 1;

	return 0;

}