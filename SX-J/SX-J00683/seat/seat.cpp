#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	if (x > y)
		return 1;
	else
		return 0;
};

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int x, y;
	cin >> x >> y;
	int a[x * y + 5] = {0};
	int sum[x + 5][y + 5];
	int c;
	for (int i = 1; i <= x * y; i++) {
		cin >> a[i];
		if (i == 1)
			c = a[i];
	}
	sort(a + 1, a + x *y + 1, cmp);
	int sum1 = 1;
	for (int i = 1; i <= y; i++) {

		if (i % 2 == 1) {
			for (int j = 1; j <= x; j++) {
				sum[j][i] = a[sum1];
				sum1++;
			}


		} else {
			for (int j = x; j >= 1; j--) {
				sum[j][i] = a[sum1];
				sum1++;
			}
		}
	}
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (sum[i][j] == c) {
				cout << j << ' ' << i;
				return  0;
			}
		}
	}

	return 0;
}
