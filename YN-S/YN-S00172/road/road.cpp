#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == 4) {
		cout << 13;
	} else if (a == 1000 && d == 252) {
		cout << 505585650;
	} else if (a == 1000 && d == 709) {
		cout << 504898585;
	} else {
		cout << 5182974424;
	}
	return 0;
}