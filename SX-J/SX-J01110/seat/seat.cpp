#include <bits/stdc++.h>
using namespace std;
long long m, n, a[10000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int b = n * m, c = 0;
	for (int i = 0; i < b; i++) {
		cin >> a[i];
		if (a[i] > a[1])
			c++;
	}
	int d = c / n + 1;
	if (d % 2 == 1)
		cout << d << " " << c % n + 1;
	else
		cout << d << " " << m - c % n;
	return 0;
}
