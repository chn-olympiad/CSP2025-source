#include <bits/stdc++.h>
using namespace std;
int x, y, a, c, r, a1;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> x >> y;
	a = x * y;
	int num[a + 2];
	for (int i = 1; i <= a; i++) {
		if (i == 1) {
			cin >> a1;
			num[1] = a1;
		} else {
			cin >> num[i];
		}
	}
	int cnt = 1;
	int seat[x + 2][y + 2];
	sort(num + 1, num + a + 1, cmp);
	for (int i = 1; i <= y; i++) {
		if (i % 2 == 0) {
			for (int j = x; j >= 1; j--) {
				seat[j][i] = num[cnt];
				if (num[cnt] == a1) {
					cout << i << " " << j;
					return 0;
				}
				cnt++;
			}
		} else {
			for (int j = 1; j <= x; j++) {
				seat[j][i] = num[cnt];
				if (num[cnt] == a1) {
					cout << i << " " << j;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}
