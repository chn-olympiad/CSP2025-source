#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], b[15][15], x, y = 1;

bool cmp(int p, int q) {
	return p > q;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	int l = n * m;
	for (int i = 1; i <= l; i++) {
		cin >> a[i];
	}
	int num = a[1];
	sort(a + 1, a + l + 1, cmp);
	for (int i = 1; i <= l; i++) {
		if (x < n)
			x++;
		else if (x >= n)
			x = 1, y++;
		b[x][y] = a[i];
		if (b[x][y] == num) {
			cout << y << " " << x;
			return 0;
		}
	}
	return 0;
}
