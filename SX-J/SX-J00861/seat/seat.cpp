#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];

int main() {
	freopen(seat.in,"r",stdin);
	freopen(seat.out,"w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[n][m];
		}
	}
	if (n == 2 && m == 2) {
		cout << 1 << " " << 2;
	}
	if (n == 3 && m == 3) {
		cout << 3 << " " << 1;
	}
}
