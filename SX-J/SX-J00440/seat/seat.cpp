#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100100];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int k = n * m;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	int c = a[1];
	sort(a + 1, a + k + 1);
	for (int i = 1; i <= k; i++) {
		if (c == a[i]) {
			int p = (i - 1) / n;
			cout << (i + n - 1) / n << " ";
			if (p % 2 == 0) {
				cout << i % n << endl;
			} else
				cout << n - i % n;
			break;
		}
	}
	return 0;
}
