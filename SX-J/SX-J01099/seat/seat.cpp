#include <bits/stdc++.h>
using namespace std;
int s[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	int d = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i];
		d = s[1];
	}
	for (int i = 1; i <= n * m; i++) {
		for (int j = 1; j <= n * m; j++) {
			int max = 0;
			if (s[j]  < s[j + 1] ) {
				max = s[j] ;
				s[j] = s[j + 1];
				s[j + 1]  = max;
			}
		}
	}
	int h = 0;
	for (int i = 1; i <= n * m; i++) {
		if (s[i] == d)
			h = i;
	}
	int r = 0, l = 0;
	if (h <= n)
		cout << 1 << " " << h;
	else if (h % n == 0) {
		if ((h % n) % 2 == 0) {
			r = 1;
		} else {
			r = n;
		}
		cout << h / n << " " << r;
	} else if (h % n != 0) {
		l = h / n + 1;
		if ((h / m) % 2 == 0) {
			r = h % n;
		} else {
			r = (1 + n) - (h % n);
		}
		cout << l << " " << r;
	}
	return 0;
}
