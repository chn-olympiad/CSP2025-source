#include <bits/stdc++.h>
using namespace std;
int b[105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m, n, i, s = 1, c, r;
	cin >> n >> m;
	for (i = 1; i <= m * n; i++) {
		cin >> b[i];
		if (b[1] < b[i])
			s = s + 1;
	}
	if (s < 4) {
		c = 1;
		r = s;
	} else if (s % 2 == 1 && s % n != 0) {
		c = s / n + 1;
		r = s % n ;
	} else if (s % 2 == 0 && s % n == 0) {
		c = s / n;
		r = 1;
	} else if (s % 2 == 1 && s % n == 0) {
		c = s / n;
		r = n;
	} else {
		c = s / n + 1;
		r = n - s % n + 1;
	}
	cout << c << " " << r;
	return 0;
}
