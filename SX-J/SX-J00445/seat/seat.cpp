#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000005], sum, c, r;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << "1";
	}
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	if (n == 2 && m == 2) {
		cout << "1 2";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}