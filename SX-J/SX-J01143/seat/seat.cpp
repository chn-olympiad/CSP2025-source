#include <bits/stdc++.h>
using namespace std;

long long a[105], s[11][11], r;
int m, n;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int l = n * m;
	for (long long  i = 0; i < l; i++) {
		cin >> a[i];
	}
	r = a[0];
	for (int i = 0; i < l; i++) {
		for (int j = 1; j < l; j++) {
			if (a[j] > a[j - 1]) {
				swap(a[j], a[j - 1]);
			}
		}
	}
	int k = 0;
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				s[j][i] = a[k];
				k++;
			}
		} else {
			for (int j = n - 1; j >= 0; j--) {
				s[j][i] = a[k];
				k++;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (s[j][i] == r) {
				cout << i + 1 << " " << j + 1;
				return 0;
			}
		}
	}
}