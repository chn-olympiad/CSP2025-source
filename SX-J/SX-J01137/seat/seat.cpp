#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+5;
long long a[N];
int b[12][12];

int main() {
	freopen("seat.in", "r", stdin)
	freopen("seat.out", "w", stdout)
	int n, m, p, xi;
	cin >> n >> m;
	p = m * n;
	for (int i = 1; i <= p; i++) {
		cin >> a[i];
	}
	xi = a[1];
	for (int j = 1; j <= p; j++) {
		for (int k = 1; k <= p; k++) {
			if (a[k] < a[k + 1])
				swap(a[k], a[k + 1]);
		}
	}
	for (int q = 2; q <= p; q++) {
		int i = 1, j = 1;
		b[1][1] = a[1];
		b[m][n] = a[p];
		if (i % 2 == 1) {
			j++;
			b[i][j] = a[q];
		} else if (i % 2 == 0) {
			j--;
			b[i][j] = a[q];
		}
		if (j == 1 || j == n) {
			if (i != m) {
				b[j][i] = a[q];
				q += 2;
				i++;
				b[i][j] = a[q - 1];
			}
		}
		if (b[i][j] == xi) {
			cout << i << " " << j;
			return 0;
		}
	}
	return 0;
}