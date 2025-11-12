#include <bits/stdc++.h>
using namespace std;
int n, m, r, c, ri, stu = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int fen[n * m];
	for (int i = 0; i < n * m; i++) {
		cin >> fen[i];
	}
	r = fen[0];
	for (int i = 1; i < n * m; i++) {
		if (fen[i] > r) {
			stu += 1;
		}
	}
	ri = stu % (2 * n);
	if (ri == 0)
		ri = 8;
	if (ri > n)
		ri = 2 * n - ri + 1;
	c = stu / n + 1;
	if (stu % n == 0) {
		c -= 1;
	}
	cout << c << " " << ri;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
