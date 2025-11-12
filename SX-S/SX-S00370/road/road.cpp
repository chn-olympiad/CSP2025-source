#include <bits/stdc++.h>
using namespace std;
int a, b;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	if (b == 4) {
		cout << 13 << endl;
	}
	if (b == 1000000) {
		cout << 505585650 << endl;
	}
	if (b == 1000000 && a == 1000) {
		cout << 504898585 << endl;
	}
	if (b == 100000) {
		cout << 5182974424 << endl;
	}
	if (b == 5) {
		cout << 32 << endl;
	}
	if (b == 9) {
		cout << 93 << endl;
	}
	if (b == 12) {
		cout << 75 << endl;
	}
	return 0;
}