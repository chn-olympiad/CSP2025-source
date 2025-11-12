#include <bits/stdc++.h>;
using namespace std;
int n, m, j8, R_mark, num = 0, y = 1, l = 1, t, sum = 0;


int mark[101] = {0};
int seat[101][101] = {0};
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int x = 0; x < n * m; x++) {
		cin >> j8;
		mark[j8]++;
		if (x == 0)
			R_mark = j8;
	}
	for (int x = 100; x >= 0; x--) {
		if (mark[x] == 0)
			continue;
		sum++;
		if (x == R_mark && num == 0)
			num = sum;
		mark[x]--;
		if (mark[x] != 0)
			x++;
	}
	l = num / n;
	t = num % n;
	if (l % 2 == 0) {
		if (t == 0)
			cout << l << ' ' << 1;
		else if (t == 1)
			cout << ++l << ' ' << 1;
		else {
			t--;
			++l;
			y += t;
			cout << l << ' ' << y;
		}
	} else {
		if (t == 0)
			cout << l << ' ' << n;
		else if (t == 1)
			cout << ++l << ' ' << n;
		else {
			t--;
			++l;
			y += n - t;
			cout << l << ' ' << y;
		}
	}
	return 0;
}
