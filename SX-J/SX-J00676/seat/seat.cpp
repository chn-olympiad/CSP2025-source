#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int t = n * m;
	for (int i = 0; i < t; i++) {
		cin >> a[i];

	}
	int b = a[0];
	sort(a, a + t);
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a)
			if (j == m)
				n++;
		j++;

	}
	cout << n << ' ' << m;
	return 0;
}
