#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1005], h;

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	h = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (h == a[i])
			cout << a[1];
	}

	return 0;
}