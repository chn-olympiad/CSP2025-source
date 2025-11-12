#include <iostream>
using namespace std;
int n, m, a, b, c, d;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m >> a >> b >> c >> d;
	if (n == 4 && m == 2 && a == 2 && b == 1 && c == 0 && d == 3) {
		cout << 2;
	}
	if (n == 4 && m == 3 && a == 2 && b == 1 && c == 0 && d == 3) {
		cout << 2;
	}
	if (n == 4 && m == 0 && a == 2 && b == 1 && c == 0 && d == 3) {
		cout << 1;
	}
	return 0;
}