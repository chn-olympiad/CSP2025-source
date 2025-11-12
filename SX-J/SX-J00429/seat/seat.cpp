#include <bits/stdc++.h>
using namespace std;
int a[105];
int n, m;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum++;
			cin >> a[sum];
		}
	}
	int xx = a[1];
	sort(a + 1, a + 1 + sum, cmp);
	sum = 0;
	for (int j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				sum++;
				if (a[sum] == xx) {
					cout << j << " " << i;
					return 0;
				}
			}
		} else {
			for (int i = n; i >= 1; i--) {
				sum++;
				if (a[sum] == xx) {
					cout << j << " " << i;
					return 0;
				}
			}

		}
	}
	return 0;
}
