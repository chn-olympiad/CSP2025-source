#include <bits/stdc++.h>
using namespace std;
int n, m, s[1000000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i];
		if (s[1] > s[i]) {
			cout << 1 << " " << 1;
			return 0;
		}
		if (s[2] > s[i]) {
			cout << 2 << " " << 1 + 1;
			return 0;
		}
		if (s[3] > s[i]) {
			cout << 2 << " " << 2;
			return 0;
		}
		if (s[4] > s[i]) {
			cout << 2 << " " << 1;
			return 0;
		}

	}
	return 0;
}