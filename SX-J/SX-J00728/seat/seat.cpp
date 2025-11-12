#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int a[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, j, r, l;
	cin >> n >> m;
	for (int i = 1; i <= (n * m); i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a, a + n *m );
	for (int i = 1; i <= (n * m); i++) {
		if (r == a[i]) {
			j = (n *m) - i;
		}
	}
	if ((j % m) == 0) {
		l = (j / m);
		cout << l << " ";
	} else {
		l = (j / m) + 1;
		cout << l << " ";
	}
	if (l % 2 == 0) {
		if ((j % m) == 0) {
			cout << "1";
		} else {
			cout << m - (j % m) + 1 ;
		}
	} else {
		if ((j % m) == 0) {
			cout << m;
		} else {
			cout << (j % m) ;
		}
	}
	return 0;
}