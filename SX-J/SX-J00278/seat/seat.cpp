#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[405];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	long long s = a[1];
	sort(a + 1, a + (n *m) + 1, cmp);
	long long cur = 1;
	for (int j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				if (a[cur] == s) {
					cout << j << " " << i << endl;
					return 0;
				}
				cur++;
			}
		} else {
			for (int i = n; i >= 1; i--) {
				if (a[cur] == s) {
					cout << j << " " << i << endl;
					return 0;
				}
				cur++;
			}
		}
	}
	return 0;
}
