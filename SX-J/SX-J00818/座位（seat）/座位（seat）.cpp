#include <bits/stdc++.h>
using namespace std;
int a[1000 + 5];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int max = INT_MIN;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m * n ; i++) {
		cin >> a[i];
		int max = a[1];
	}
	for (int i = 1; i <= m  ; i++) {
		for (int j = 2; j <= n  ; j++) {
			if (max = a[i] && i < n) {
				cout << j << ' ' << i;
				break;
			}

		}

	}
	return 0;
}
