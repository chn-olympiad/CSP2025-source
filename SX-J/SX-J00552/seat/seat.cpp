#include <bits/stdc++.h>
using namespace std;
int a[110];

int cmp(int c, int b) {
	return c > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, t, g, h, jl;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	t = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == t) {
			jl = i;
			g = i % m;
			if (g == 0) {
				h = i / m;
				cout << i / m << " ";
			} else if (g != 0) {
				h = i / m + 1;
				cout << i / m + 1 << " ";
			}
			break;
		}
	}
	if (h % 2 != 0) {
		if (jl % m == 0) {
			cout << m;
		} else {
			cout << jl % m;
		}
	} else {
		if (jl % m == 0) {
			cout << m;
		} else {
			cout << m - (jl % m) + 1;
		}
	}
	return 0;
}
