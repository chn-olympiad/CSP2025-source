#include <bits/stdc++.h>
using namespace std;

long long s1[120];

long long cmp(long long a, long long b) {
	if ((a = b))
		return a;
	else if ((a < b))
		return b;
	else if ((a > b))
		return b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c = 1, r = 1;
	cin >> n >> m;
	long long s[15][15];
	for (int i = 1; i <= 100; ++i) {
		cin >> s1[i];
	}
	sort(s1 + 1, s1 + (n *m) + 1);
	for (int i = 1; i <= 100 ; ++i) {
		for (int j = 1; j <= n ; ++j) {
			for (int k = 1; k <= m ; ++k) {
				if (m % 2 == 0) {
					s[j][1] = s[j][m];
					s1[1] = s[j][k];
					break;
				}
				j = c;
				k = r;
			}
		}
		cout << c << " " << r;
	}

	return 0;
}
