#include <bits/stdc++.h>
using namespace std;
int a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
	}
	int l = a[1], k = 1;
	sort(a + 1, a + m *n + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= n; j++) {
				if (a[k] == l) {
					cout << i << " " << j;
					return 0;
				}
				k++;
			}
		}
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				if (a[k] == l) {
					cout << i << " " << j;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
