#include <bits/stdc++.h>
using namespace std;
int n, m, s[105], a;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i];
	}
	a = s[1];
	sort(s + 1, s + n + 1, cmp);
	m = n = 1;
	for (int i = 1; i <= n * m; i++) {
		if (n % 2 == 1 && i > m) {
			n++;
			i = 1;
		} else
			m++;
		if (n % 2 == 0 && m == 1) {
			n++;
			i = 1;
		} else
			m--;
	}
	cout << n << m;
	return 0;
}
