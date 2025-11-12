#include <bits/stdc++.h>
using namespace std;
long long q, a, n, m, b1;
int x, y;
int b[105];
bool c = 0;

bool cmp(long long a, long long b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	q = n * m;
	for (int i = 1; i <= q; i++) {
		cin >> b[i];
	}
	b1 = b[1];
	sort(b + 1, b + 1 + q, cmp);
	/*for (int i = 1; i <= q; i++) {
		cout << b[i] << " ";
	}
	cout << endl;*/
	x = 1;
	y = 1;
	for (int i = 1; i <= q; i++) {
		if (b[i] == b1) {
			break;
		}
		if (c == 0) {
			if (y + 1 <= n) {
				y++;
			} else {
				x++;
				c = !c;
			}
		} else {
			if (y - 1 >= 1) {
				y--;
			} else {
				x++;
				c = !c;
			}
		}

	}
	cout << x << " " << y;
	return 0;
}
