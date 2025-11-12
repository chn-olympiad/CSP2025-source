#include<bits/stdc++.h>
using namespace std;

int n, m, a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int target = a[1], level;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == target) {
			level = i;
			break;
		}
	}
	int c, r;
	if (level % (2 * n) == 0) {
		c = level / n; 
		r = 1;
	} else {
		c = level / (2 * n) * 2 + 1;
		level %= (2 * n);
		if (level <= n) {
			r = level;
		} else {
			c++;
			r = 2 * n - level + 1;
		}
	}
	cout << c << " " << r;
	return 0;
}