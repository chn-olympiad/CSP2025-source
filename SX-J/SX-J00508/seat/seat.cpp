#include <bits/stdc++.h>
using namespace std;
int n, m, a[15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = a[1];
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			if (a[j] == sum) {
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	return 0;
}