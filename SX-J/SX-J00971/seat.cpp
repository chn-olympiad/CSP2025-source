#include <bits/stdc++.h>
using namespace std;
int a[105];
int n, m, b;

int main() {
	cin >> n >> m >> a[1];
	b = a[1];
	for (int i = 2; i <= n * m; i++)
		cin >> a[i];
	sort(a, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == b) {
			if (i % 2 != 0) {
				cout << i / n + 1 << i / m;
			} else {
				cout << i / n << i / m + 1;
			}
		}
	}
	return 0;
}
