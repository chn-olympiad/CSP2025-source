#include <bits/stdc++.h>
using namespace std;
long long n, m;
int a[30];

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == (n * m - i + 1) ) {
			a[i]++;
			if (a[1] > INT_MIN) {
				cout << 1 << ' ' << 1;
				a[i] = INT_MIN;
			}
		}
	}

	return 0;
}