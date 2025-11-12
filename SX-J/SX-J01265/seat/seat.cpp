#include <bits/stdc++.h>
using namespace std;
int s[1000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> s[i];
	}
	r = s[0];
	sort(s, s + m *n);
	int q = m * n - 1;
	for (int a = 1; a <= m; a++) {
		if (a % 2 == 1) {
			for (int b = 1; b <= n; b++) {
				if (s[q] == r) {
					cout << a << " " << b;
					return 0;
				}
				q--;
			}
		} else if (a % 2 == 0) {
			for (int b = n; b >= 1; b--) {
				if (s[q] == r) {
					cout << a << " " << b;
					return 0;
				}
				q--;
			}
		}
	}
}
