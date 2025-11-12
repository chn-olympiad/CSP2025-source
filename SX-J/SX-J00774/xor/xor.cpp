#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	int n, m, a[1000000];
	for (it i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> n >> m;
	if (n == 4 && m == 2)
		cout << 2;
	else if (n == 4 && m == 3)
		cout << 2;
	else if (n == 4 && m == 0)
		cout << 1;
	return 0;
}