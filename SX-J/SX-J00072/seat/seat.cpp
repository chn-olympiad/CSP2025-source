#include <bits/stdc++.h>
using namespace std;
int a[120];

int cmp(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int q = a[1];
	sort(a, a + m *n + 2, cmp);
	cout << n << " " << m;


	return 0;
}
