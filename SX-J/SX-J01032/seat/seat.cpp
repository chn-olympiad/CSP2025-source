#include <bits/stdc++.h>
using namespace std;

int n, m;
int t;
int a[105];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	t = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == t) {
			t = i;
			break;
		}
	}
	int y = t / n ;
	if (t % n != 0)
		y++;
	int x = t % n;
	if (x == 0)
		x = n;
	if (y % 2 == 1)
		cout << y << ' ' << x;
	else
		cout << y << ' ' << n - x + 1;
	return 0;
}