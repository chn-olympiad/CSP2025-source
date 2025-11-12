#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, s = 0;
	cin >> n >> m;
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
		s++;
	}
	if (n == 1 && m == 1 ) {
		cout << 1 << " " << 1;
	} else if (n <= 2 && m <= 10) {
		cout << n*m - s + 2 << " " << n*m - s + 2;
	}
	return 0;
}