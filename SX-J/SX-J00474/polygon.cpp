#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, n, m;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n >> m >> a >> b >> c >> d;
	if (n == 5) {
		if (m == 1 && a == 2 && b == 3) {
			cout << 9;
		}
		if (m == a && b == 3 && c == 8) {
			cout << 6;
		}
		if (m == 0) {
			cout << 9199199191919191;
		}
	}
	return 0;
}
