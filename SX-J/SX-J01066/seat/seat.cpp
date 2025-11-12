#include <iostream>
#include <string>
using namespace std;
int n, m, a, b, c;

int main() {
	freopen("seat.in", "w", stdin);
	freopen("seat.out", "r", stdout);
	cin >> n >> m;
	cin >> b;
	c = 1;
	for (int i = 1; i < n * m; i++) {
		cin >> a;
		if (a > b)
			c++;
	}
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 0)
			for (int j = n; j >= 1; j--) {
				c--;
				if (c == 0)
					cout << i << ' ' << j;
			}
		if (i % 2 == 1)
			for (int j = 1; j <= n; j++) {
				c--;
				if (c == 0)
					cout << i << ' ' << j;
			}
	}
	return 0;
}
