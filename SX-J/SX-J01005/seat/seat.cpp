#include <bits/stdc++.h>
using namespace std;
int n, m, g, s[250], a, x, y;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> g;
	for (int i = 1; i < n * m ; i++)
		cin >> s[i];
	sort(s + 1, s + n *m );
	for (int i = 1; i < n * m ; i++)
		if (s[i + 1] > g && s[i] < g) {
			a = n * m - i ;
			break;
		}
	if (a % n == 0) {
		x = a / n;
		y = n;
		cout << x << ' ' << y << ' ' << a;
		return 0;
	} else {
		x = a / n + 1;
		g = 1;
	}
	a = a % n;
	if (x % 2 != 0)
		y = a;
	else
		y = a + (n - a);
	cout << x << ' ' << y ;
	return 0;
}