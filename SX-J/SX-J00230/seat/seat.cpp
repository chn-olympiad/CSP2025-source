#include <bits/stdc++.h>
using namespace std;
int n, m, a[110];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> a[1];
	int t = n * m, tmp = a[1], k = 1;
	for (int i = 2; i <= t; i++) {
		cin >> a[i];
	}
	stable_sort(a + 1, a + t + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			for (int j = m; j >= 1; j--) {
				if (a[k] == tmp) {
					cout << i << " " << j;
					return 0;
				}
				k++;
			}
		} else {
			for (int j = 1; j <= m; j++) {
				if (a[k] == tmp) {
					cout << i << " " << j;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
