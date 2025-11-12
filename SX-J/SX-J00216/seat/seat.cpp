#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n = 0, m = 0;
	cin >> n >> m;
	int l = n * m, s, p;
	int  sun[l + 5];
	for (int i = 1; i <= l; i++) {
		cin >> sun[i];
		s = sun[1];
	}
	sort(sun + 1, sun + l + 1);
	for (int i = l; i >= 1; i--) {
		if (s == sun[i])
			p = l - i + 1;
	}
	int ml = p / n + 1, m1 = p % n, nl;
	if (m1 == 0) {
		ml--;
		m1 = n;
	}
	if (ml % 2 == 0) {
		m1 = 1;
		nl = n - m1 + 1;
	} else {
		nl = m1;
	}
	cout << ml << " " << nl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
