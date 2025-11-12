#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	int n, m;
	int c = 1, r = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	cout << c << r;
	return 0;
}