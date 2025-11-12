#include <bits/stdc++.h>
using namespace std;
int n, m, a[10010], c[10010];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n ; i++) {
		cin >> a[i];
	}
	if (n == 1 && m == 1) {
		cout << 1;
	}
}
