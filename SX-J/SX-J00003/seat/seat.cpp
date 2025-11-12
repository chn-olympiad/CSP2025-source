#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c, r, a, t = INT_MAX;
	cin >> n >> m;
	string g;
	getline(cin, g);
	int l = g.size();
	for (int i = 0; i <= l - 1; i++) {
		if (a < t)
			c += 1;
		r += 1;
	}

	cout << c << " " << r;
	return 0;
}