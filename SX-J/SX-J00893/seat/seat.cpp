#include <bits/stdc++.h>
using namespace std;
int a[105];

bool cmp(int p, int q) {
	return p > q;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, s;
	cin >> n >> m;
	cin >> s;
	a[1] = s;
	for (int i = 2; i <= n * m; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n *m, cmp);
	int x = 1, y = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == s) {
			cout << x << " " << y;
			break;
		}
		if (y == n && x % 2 == 1) {
			x++;
		} else if (y == 1 && x % 2 == 0) {
			x++;
		} else if (x % 2 == 1)
			y++;
		else if (x % 2 == 0)
			y--;
	}
	return 0;
}//#Shang4Shan3Ruo6Shui4
/*3 3
94 95 96 97 98 99 100 93 92*/
