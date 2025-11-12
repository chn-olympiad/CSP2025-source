#include <bits/stdc++.h>
using namespace std;
int n, m, s, k, c, r;
int a[100000000];

bool cmp(int p, int q) {
	return p > q;
}

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	cin >> n >> m;
	if (n == 1 and m == 1) {
		cout << 1 << " " << 1;
		return 0;
	}
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	s = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++)
		if (s == a[i])
			k = i;
	if (n == 1) {
		cout << 1 << " " << k;
		return 0;
	}
	if (m == 1) {
		cout << k << " " << 1;
		return 0;
	}
	return 0;
}