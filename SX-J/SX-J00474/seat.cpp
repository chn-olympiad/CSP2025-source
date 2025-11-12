#include <bits/stdc++.h>
using namespace std;
int a[105][105], stu[11451], stuw[11451], n, m, bigman, x = 1, y = 1, k = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int ren = n * m;
	for (int i = 1; i <= ren; i++) {
		cin >> stu[i];
	}
	bigman = stu[1];
	sort(stu + 1, stu + 1 + ren);
	int gg = ren;
	for (int i = 1; i <= ren; i++) {
		stuw[gg] = stu[i];
		if (stuw[gg] == bigman) {
			bigman = gg;
		}
		gg--;
	}
	for (int i = 1; i <= m; i++) {
		if (m % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = k;
				if (k == bigman) {
					cout << i << ' ' << j;
					return 0;
				}
				k++;
			}
		} else {
			for (int g = n; g >= 1; g--) {
				a[i][g] = k;
				if (k == bigman) {
					cout << i << ' ' << g;
					return 0;
				}
				k++;
			}
		}
	}

	return 0;
}
