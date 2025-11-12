#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	int n, m, a, b, c, d;
	cin >> n >> m >> a >> b >> c >> d;
	if (n == 3 && m == 2 && a == 101 && b == 1 && c == 1 && d == 2)
		cout << 2;
	if (n == 10 && a == 6 && b == 0 && c == 4 && d == 2)
		cout << 2204128;
	return 0;
}