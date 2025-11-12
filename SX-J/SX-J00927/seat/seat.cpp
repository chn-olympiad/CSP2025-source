#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], s, t, u;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == s) {
			u = (i - 1) / m + 1;
			if (u % 2 == 1) {
				if (i % m == 0)
					t = m;
				else
					t = i % m;
			} else {
				if (i % m == 0)
					t = 1;
				else
					t = n + 1 - (i % m);
			}
			break;
		}
	}
	cout << u << " " << t << endl;
}
