#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], c = 1, r = 1, b;

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	b = a[1];
	sort( a + 1, a + 1 + m *n );
	for (int i = 1; i <= n * m; i++) {

		if (a[i] == b) {
			cout << c  << " " << r ;
		} else {
			r++;
			if (r == n) {
				c++;
			} else {
				c++;
			}
		}

	}
	return 0;
}
