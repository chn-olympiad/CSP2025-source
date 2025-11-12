#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int z[N][13];
long long maxx = LLONG_MIN, t, n;

void gl(int a, int b, int c, int i, long long s) {
	if (i > n) {
		maxx = max(maxx, s);
		return;
	}
	for (int j = 1; j <= 3; j++) {
		if (j == 1) {
			if (a < n / 2) {
				gl(a + 1, b, c, i + 1, s + z[i][1]);
			}
		}
		if (j == 2) {
			if (b < n / 2) {
				gl(a, b + 1, c, i + 1, s + z[i][2]);
			}
		}
		if (j == 3) {
			if (c < n / 2) {
				gl(a, b, c + 1, i + 1, s + z[i][3]);
			}
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> z[i][1] >> z[i][2] >> z[i][3];
		}
		maxx = LLONG_MIN;
		gl(0, 0, 0, 1, 0);
		cout << maxx << "\n";
	}
	return 0;
}