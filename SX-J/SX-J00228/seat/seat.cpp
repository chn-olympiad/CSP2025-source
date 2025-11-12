#include <bits/stdc++.h>
using namespace std;
int a[15][15], b[110], z[110];
int n, m, c, r, t, s;
int cnt;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	cin >> n >> m;
	s = n * m;
	for (int i = 1; i <= s; i++) {
		cin >> b[i];
		t = b[1];
	}
	sort(b + 1, b + s + 1, cmp);
	for (int i = 1; i <= s; i++) {
		cnt++;
		if (t == b[i]) {
			break;
		}
	}
	for (int i = 1; i <= s; i++) {
		c = cnt / 2;
		if (c % 2 == 0)
			r = m - [cnt - m * (c - 1)] + 1;


	}
	cout << c << " " << r;
	return 0;
}