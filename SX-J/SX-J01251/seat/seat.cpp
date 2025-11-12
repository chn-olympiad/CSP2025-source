#include <bits/stdc++.h>
using namespace std;
int a[1001];

bool cmp(int c, int b) {
	return c > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, j = 1, paiming;
	cin >> n >> m;
	int k = m * n;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1, a + k + 1, cmp);
	for (int i = 1; i <= m; i++) {
		while (j <= n && i % 2 != 0) {
			paiming = n * (i - 1) + j;
			if (a[paiming] == r) {
				cout << i << " " << j;
				return 0;
			}
			j++;
		}
		j--;
		while (j > 0 && i % 2 == 0) {
			paiming = n * i - j + 1;
			if (a[paiming] == r) {
				cout << i << " " << j;
				return 0;
			}
			j--;
		}
		j++;
	}
}
