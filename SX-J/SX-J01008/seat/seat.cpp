#include <bits/stdc++.h>
using namespace std;
int n, m, in = 1, im = 1, it = 1;
int a[1005];
int pos;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("saet.out", "w", stdout);
	cin >> n >> m;
	cin >> pos;
	a[1] = pos;
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		//	cout << a[i] << ' ';
		if (a[i] == pos)
			it = i;
	}
	cout << (it - 1) / n + 1 << ' ';
	if (((it - 1) / n + 1) % 2 == 1) {
		cout << (((it % n) == 0 ) ? n : (it % n));
	} else {
		cout << (n - ((it % n == 0 ) ? n : (it % n)) + 1);
	}
	return 0;
}
