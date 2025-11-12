#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
long long b[1000010];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, hang, lie, paiming;
	cin >> n >> m;
	for (long long i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	for (long long i = 1; i <= n * m; i++) {
		b[i] = a[i];
	}
	sort(b, b + n *m + 1);
	for (long long i = 1; i <= n * m; i++) {
		if (b[i] == a[1])
			paiming = n * m - i + 1;
	}
	if (paiming % n == 0)
		lie = paiming / n;
	else
		lie = paiming / n + 1;
	if (lie % 2 == 0)
		hang = n - paiming + n * lie - n + 1;
	else
		hang = paiming - n * lie + n;
	cout << lie << ' ' << hang;
}
