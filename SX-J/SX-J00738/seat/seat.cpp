#include <bits/stdc++.h>
using namespace std;
int a[10005];

bool cmp(int o, int op) {
	return o > op;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int js1 = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == js1) {
			js1 = i;
		}
	}
	int x = js1 / n + 1;
	int y = js1 % n;
	if (y == 0) {
		y = n;
		x--;
	}
	if (x % 2 == 0) {
		y = n - y + 1;
	}
	cout << x << " " << y << endl;
	return 0;

}
