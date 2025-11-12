#include <bits/stdc++.b>
using namespace std;
int a[15][15], b[110], z[110];
int n, m, c, r, t, s;
int cnt;

bool cmp (int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin)
	freopen("seat.out", "r", stdout)
	cin >> n >> m;
	s = n * m;
	for (int i = 1; i <= s; i++) {
		cin >> b[i];
		t = b[i];
	}
	sort(b + 1, b + s + 1, cmp)
	for (int i = 1; i <= s; i++) {
		cnt++;
		if (t == b[i]) {
			break;
		}

	}
	int k = cnt / 2;
	if (n % 2 != 0) {
		c = cnt / m + 1;
		r = cnt - m * c + m;
	} else if (k % 2 = 0) {
		c = cnt / m + 1;
		r = cnt - m * c + 1;
	}
	cout << c << " " << r;
	return 0;
}
