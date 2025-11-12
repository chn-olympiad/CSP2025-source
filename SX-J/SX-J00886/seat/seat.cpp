#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int n, m;

bool cmp(int x, int y) {
	return x >= y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int nn = n * m;
	for (int i = 1; i <= nn; i++) {
		cin >> a[i];
	}
	int t = a[1], tt;
	sort(a + 1, a + 1  + nn, cmp);
	for (int i = 1; i <= nn; i++) {
		if (a[i] == t) {
			tt = i ;
			break;
		}
	}
	if (tt == 1) {
		cout << 1 << ' ' << 1;
		return 0;
	}
	int x = 1, y = 1, cnt = 1;
	while (true) {
		while (x + 1 <= n) {
			x++;
			cnt++;
			if (cnt == tt) {
				cout << y << ' ' << x;
				return 0;
			}
		}
		if (y + 1 <= m) {
			cnt++;
			y++;
		}
		if (cnt == tt) {
			cout << y << ' ' << x;
			return 0;
		}
		while (x - 1 >= 1) {
			x--;
			cnt++;
			if (cnt == tt) {
				cout << y << ' ' << x;
				return 0;
			}
		}
		if (y + 1 <= m) {
			cnt++;
			y++;
		}

		if (cnt == tt) {
			cout << y << ' ' << x;
			return 0;
		}
	}
	return 0;
}
