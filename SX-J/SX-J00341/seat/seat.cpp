#include <bits/stdc++.h>
using namespace std;
int a, b;
int a1[400];
int r;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> a >> b;
	for (int i = 0; i < a * b; i++) {
		cin >> a1[i];
	}
	r = a1[0];
	sort(a1, a1 + 400, greater<int>());
	int x = 0, y = 0;
	bool v = 0;
	for (int i = 0; i < 400; i++) {
		if (a1[i] == r) {
			cout << y + 1 << " " << x + 1;
			break;
		}
		if (v == 0) {
			x++;
		} else {
			x--;
		}
		if (x < 0) {
			x = 0;
			y++;
			v = 0;
		}
		if (x >= a) {
			x = a - 1;
			v = 1;
			y++;
		}
	}
	return 0;
}
